

#ifndef CFS_OSAL_TASK_RUNNABLE_HPP
#define CFS_OSAL_TASK_RUNNABLE_HPP

namespace cfs::osal::task
{
    /*!
     * @brief Interface of a runnable class.
     *      You can write code to be run through a Thread by implementing this interface.
     */
    class Runnable
    {
        public:

            /**
             * This method must be overritten
             */
            virtual void run () noexcept = 0;
            virtual ~runnable()
            {
            }
    };
}

#endif

