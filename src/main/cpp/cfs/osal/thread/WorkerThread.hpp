

#ifndef CFS_OSAL_THREAD_WORKERTHREAD_HPP
#define CFS_OSAL_THREAD_WORKERTHREAD_HPP

#include <atomic>
#include <thread>

#include <cfs/osal/CompilerDetection.hpp>
#include <cfs/osal/Export.hpp>

namespace cfs::osal::thread
{
    /*!
     * @brief The WorkerThread class owns task queue and executing thread.
     *      In thread it tries to pop task from queue. If queue is empty then it tries
     *      to steal task from the sibling worker. If steal was unsuccessful then spins
     *      with one millisecond delay.
     */
    template <typename Task, template<typename> class Queue>
    class CFS_OSAL_MAIN_EXPORT WorkerThread
    {
        public:

            /*!
             * @brief WorkerThread Constructor.
             * @param queue_size Length of undelaying task queue.
             */
            explicit WorkerThread(size_t queue_size);

            /*!
             * @brief Move ctor implementation.
             */
            WorkerThread(WorkerThread&& rhs) CFS_OSAL_NOEXCEPT;

            /*!
             * @brief Move assignment implementaion.
             */
            WorkerThread& operator=(WorkerThread&& rhs) CFS_OSAL_NOEXCEPT;

            /*!
             * @brief start Create the executing thread and start tasks execution.
             * @param id WorkerThread ID.
             * @param steal_donor Sibling worker to steal task from it.
             */
            void start(size_t id, WorkerThread* steal_donor);

            /*!
             * @brief stop Stop all worker's thread and stealing activity.
             * Waits until the executing thread became finished.
             */
            void stop();

            /*!
             * @brief post Post task to queue.
             * @param handler Handler to be executed in executing thread.
             * @return true on success.
             */
            template <typename Handler>
            bool post(Handler&& handler);

            /*!
             * @brief steal Steal one task from this worker queue.
             * @param task Place for stealed task to be stored.
             * @return true on success.
             */
            bool steal(Task& task);

            /*!
             * @brief getWorkerIdForCurrentThread Return worker ID associated with
             * current thread if exists.
             * @return WorkerThread ID.
             */
            static size_t getWorkerIdForCurrentThread();

        private:

            /*!
             * @brief threadFunc Executing thread function.
             * @param id WorkerThread ID to be associated with this thread.
             * @param steal_donor Sibling worker to steal task from it.
             */
            void threadFunc(size_t id, WorkerThread* steal_donor);

            Queue<Task>       m_queue;
            std::atomic<bool> m_running_flag;
            std::thread       m_thread;
    };

    namespace detail
    {
        inline size_t* thread_id()
        {
            static thread_local size_t tss_id = -1u;

            return &tss_id;
        }
    }
}

#endif

