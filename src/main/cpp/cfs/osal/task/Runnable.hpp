

#ifndef CFS_OSAL_TASK_RUNNABLE_HPP
#define CFS_OSAL_TASK_RUNNABLE_HPP

#include <atomic>
#include <thread>

namespace cfs::osal::task
{
    /*!
     * @brief Interface of a runnable class.
     *      You can write code to be run through a Thread by implementing this interface.
     */
    class Runnable
    {
        public:

            Runnable();
            Runnable(Runnable const&) = delete;
            Runnable& operator =(Runnable const&) = delete;
            virtual ~Runnable();

            /*! @brief
             *  @param Run Subclass object pointer. assignment to call its run() method up.
             *  @param entryPt Entry point of new task.
             */
            static void entry(Runnable * Run);

            void stop();
            void start();

        protected:

            /*!
             * @brief This method must be overritten
             */
            virtual void run () noexcept = 0;
            virtual void exception(const std::exception & exc) = 0;
            virtual void error() = 0;

        private:

            std::atomic<bool> stopTask;
            std::thread       m_thread;
    };
}

#endif
/*
   class myThread : public Runnable
   {
   protected:
    void run()
    {
        while (!stop)
        {
            // do something...
        };
    }
   };

 */

