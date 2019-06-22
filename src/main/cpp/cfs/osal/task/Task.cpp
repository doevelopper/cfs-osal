

#include <cfs/osal/task/Task.hpp>

using namespace cfs::osal::task;

Task::Task(const Runnable & runnable, const std::size_t stackSize)
{
    int rc = pthread_attr_init(&m_taskOptions);

    if ( rc != 0)
    {
        //throw thread_exception("pthread_attr_init failed.", rc );
    }

    rc = pthread_attr_setdetachstate(&m_taskOptions, PTHREAD_CREATE_JOINABLE);
    if ( rc != 0)
    {
        //throw thread_exception("pthread_attr_init failed.", rc );
    }

    rc = pthread_attr_setstacksize(&m_taskOptions, stackSize);
    if ( (stackSize > 0) && (rc != 0) )
    {
        //handleError
    }

    //   rc = pthread_create(&m_taskID, &m_taskOptions, routine, (void *) &runnable);
}

