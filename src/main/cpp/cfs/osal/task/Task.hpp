

#ifndef CFS_OSAL_TASK_TASK_HPP
#define CFS_OSAL_TASK_TASK_HPP

#include <pthread.h>
#include <functional>
#include <memory>

#include <cfs/osal/task/Runnable.hpp>
#include <cfs/osal/Semaphore.hpp>

namespace cfs::osal::task
{
    class Task
    {
        public:

            Task(const Task&) = delete;
            Task(Task&&) = default;
            Task& operator=(const Task&) = delete;
            Task& operator=(Task&&) = default;
            virtual ~Task() = default;

            Task(const Runnable & runnable, const std::size_t = 0);
            Task(const double & hertz, const std::function<void()>& callback);
            void join();
            int cancel();

        protected:

        //virtual int routine() =0;

        private:

            /*
               static int entry(int arg)
               {
                Task& task = *static_cast<Task*>(arg);
                semTake(task.sync, WAIT_FOREVER);
                semDelete(task.sync);
                return task.routine();
               }
             */
            void swap ( Task & other );
            pthread_t      m_taskID;
            pthread_attr_t m_taskOptions;
    };
}
#endif

