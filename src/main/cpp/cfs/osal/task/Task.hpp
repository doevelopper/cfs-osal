

#ifndef CFS_OSAL_TASK_TASK_HPP
#define CFS_OSAL_TASK_TASK_HPP

#include <pthread.h>
#include <functional>
#include <memory>

#include <cfs/osal/task/Runnable.hpp>

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
            void join();
            int cancel();

        protected:

        private:

            void swap ( Task & other );
            pthread_t      m_taskID;
            pthread_attr_t m_taskOptions;
    };
}
#endif

