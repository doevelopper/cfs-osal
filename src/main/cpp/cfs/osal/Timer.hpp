

#ifndef CFS_OSAL_TIMER_HPP
#define CFS_OSAL_TIMER_HPP

#include <chrono>
#include <condition_variable>
#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <thread>

#include <cstdint>
#include <signal.h>
#include <time.h>

namespace cfs::osal
{
    using timerClock = std::chrono::steady_clock;
    using timerCallbackCancel = std::function<void ()>;
    using timerCallbackFunction = std::function<void ()>;
    using timePoint = std::chrono::time_point<timerClock>;
    using timePrint = std::function<std::string(std::string, std::string)>;
    //  using Timeouts = std::multimap<timerClock::time_point, std::shared_ptr<timerCallbackFunction>>;

    template <typename T>
    class Timer
    {
        enum class TimerType : std::uint8_t
        {
            SINGLE_SHOOT, //timer which Signals only ones
            MULTI_SHOOT   //Periodic timer
        };

        class ScopeTimer
        {
            std::string                                    s;
            std::chrono::high_resolution_clock::time_point t0;
            std::chrono::high_resolution_clock::time_point start;

        public:

                //           template<typename ...Args>
                //              ScopeTimer (Args&& ...args)
                //               :s(std::forward<Args>(args)...),t0(std::chrono::high_resolution_clock::now())
                //            {
                //            }

            ScopeTimer()
            {
                start = std::chrono::high_resolution_clock::now();
            }

            virtual ~ScopeTimer()
            {
                using std::chrono::duration_cast;
                using std::chrono::nanoseconds;
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(end - start);

                    //          fprintf(stderr,"%s:\t%.8fs\n",s.c_str()
                    //          ,std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now()-t0).count());
            }
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
            //Timeouts m_timeouts;
            std::mutex                   m_mutex;
            std::condition_variable      m_cv;
            std::unique_ptr<std::thread> m_thread;
            static const std::uint64_t   MS_TO_NS_FACTOR;
    };
}
#endif

