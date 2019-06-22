

#include <cfs/osal/thread/WorkerThread.hpp>

using namespace cfs::osal::thread;

template <typename Task, template<typename> class Queue>
inline WorkerThread<Task, Queue>::WorkerThread(std::size_t queue_size)
    : m_queue(queue_size)
    , m_running_flag(true)
{
}

template <typename Task, template<typename> class Queue>
inline WorkerThread<Task, Queue>::WorkerThread(WorkerThread&& rhs) CFS_OSAL_NOEXCEPT
{
    *this = rhs;
}

template <typename Task, template<typename> class Queue>
inline WorkerThread<Task, Queue>& WorkerThread<Task, Queue>::operator=(WorkerThread&& rhs) CFS_OSAL_NOEXCEPT
{
    if (this != &rhs)
    {
        m_queue = std::move(rhs.m_queue);
        m_running_flag = rhs.m_running_flag.load();
        m_thread = std::move(rhs.m_thread);
    }

    return *this;
}

template <typename Task, template<typename> class Queue>
inline void WorkerThread<Task, Queue>::stop()
{
    m_running_flag.store(false, std::memory_order_relaxed);
    m_thread.join();
}

template <typename Task, template<typename> class Queue>
inline void WorkerThread<Task, Queue>::start(std::size_t id, WorkerThread* steal_donor)
{
    m_thread = std::thread(&WorkerThread<Task, Queue>::threadFunc, this, id, steal_donor);
}

template <typename Task, template<typename> class Queue>
inline std::size_t WorkerThread<Task, Queue>::getWorkerIdForCurrentThread()
{
    return *detail::thread_id();
}

template <typename Task, template<typename> class Queue>
template <typename Handler>
inline bool WorkerThread<Task, Queue>::post(Handler&& handler)
{
    return m_queue.push(std::forward<Handler>(handler));
}

template <typename Task, template<typename> class Queue>
inline bool WorkerThread<Task, Queue>::steal(Task& task)
{
    return m_queue.pop(task);
}

template <typename Task, template<typename> class Queue>
inline void WorkerThread<Task, Queue>::threadFunc(std::size_t id, WorkerThread* steal_donor)
{
    *detail::thread_id() = id;

    Task handler;

    while (m_running_flag.load(std::memory_order_relaxed))
    {
        if (m_queue.pop(handler) || steal_donor->steal(handler))
        {
            try
            {
                handler();
            }
            catch(...)
            {
                // suppress all exceptions
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

