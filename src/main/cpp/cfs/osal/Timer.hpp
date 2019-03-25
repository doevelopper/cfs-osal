

#ifndef CFS_OSAL_TIMER_HPP
#define CFS_OSAL_TIMER_HPP

#include <cstdint>
#include <signal.h>
#include <time.h>

namespace cfs::osal
{
    template <typename T>
    class Timer
    {
        enum class TimerType : std::uint8_t
        {
            SINGLE_SHOOT, //timer which Signals only ones
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

            /*!
             * @brief Destroy the Timer object
             *
             */
            virtual ~Timer();

            /*!
             * @brief Gets the internal timer ID
             */
            timer_t getID()
            {
                return (m_TimerID);
            };

            T*  getHandler();
            /*!
             * @brief
             *
             * @param msec
             */
            void start(std::uint64_t msec);

            /*!
             * @brief
             *
             */
            void Start();

            /*!
             * @brief
             *
             */
            void Stop();

            /*!
             * @brief Set the Interval object
             *
             * @param msec
             */
            void setInterval(std::uint64_t msec);

            /*!
             * @brief Get the Interval object
             *
             * @return std::uint64_t
             */
            std::uint64_t getInterval();

            TimerType getTimerType();
            /*!
             * @brief Set the Timer Type object
             *
             * @param type
             */
            void setTimerType(TimerType type);

        protected:

        private:

            /*!
             * @brief
             *
             * @param msec
             */
            void StartTimer(std::uint64_t msec);
            /*!
             * @brief
             *
             */
            void StopTimer();
            /*!
             * @brief
             *
             * @param sigval
             */
            static void TimerThreadFunc(union sigval arg);

            T *           m_handler;
            timer_t       m_TimerID;
            TimerType     m_TimerType;
            std::uint64_t m_interval;

            static const std::uint64_t MS_TO_NS_FACTOR;
    };
}
#endif

