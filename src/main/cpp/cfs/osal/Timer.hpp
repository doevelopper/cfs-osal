

#ifndef CFS_OSAL_TIMER_HPP
#define CFS_OSAL_TIMER_HPP

#include <cstdint>
#include <signal.h>
#include <time.h>

namespace cfs::osal
{
    template <class T>
    class Timer
    {
        enum class TimerType
        {
            SINGLE_SHOOT, //timer which Signals only one time
            MULTI_SHOOT   //Periodic timer
        };

        public:

            Timer();
            Timer(const Timer&) = default;
            Timer(Timer&&) = default;
            Timer& operator=(const Timer&) = default;
            Timer& operator=(Timer&&) = default;
            /*!
             * @brief Construct a Timer with a explanatory message.
             * @param handler Class to which timer needs to notify the during timeout.
             */
            Timer(T * handler);
            virtual ~Timer();
            /*!
             * @brief Gets the internal timer ID
             */
            timer_t getID()
            {
                return (m_TimerID);
            };

            T*  getHandler();

            void start(long msec);
            void Start();
            void Stop();

            void setInterval(long msec);
            int getInterval();

            TimerType getTimerType();
            void setTimerType(TimerType type);

        protected:

        private:

            void StartTimer(long msec);
            void StopTimer();
            static void TimerThreadFunc(union sigval arg);

            T *       m_handler;
            timer_t   m_TimerID;
            TimerType m_TimerType;
            long      m_interval;

            static const std::uint64_t MS_TO_NS_FACTOR;
    };
}
#endif

