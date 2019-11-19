

#include <cfs/osal/Timer.hpp>

using namespace cfs::osal;

template <typename T>
const std::uint64_t Timer<T>::MS_TO_NS_FACTOR = 1000000;

template <typename T>
Timer<T>::Timer(T * handler)
    : m_handler(handler)
    , m_TimerID(NULL)
    , m_TimerType(TimerType::MULTI_SHOT)
    , m_interval(100)
    , m_mutex()
    , m_cv()
{
}

template <typename T>
void Timer<T>::TimerThreadFunc(union sigval arg)
{
    Timer<T> * pThis = static_cast<Timer<T>*>(arg.sival_ptr);
    pThis->getHandler()->OnTimeOut();
}

template <typename T>
T* Timer<T>::getHandler()
{
    return m_handler;
}

/*
   template <typename T>
   Timer::TimerType Timer<T>::getTimerType()
   {
    return m_TimerType;
   }
 */

template <class T>
void Timer<T>::setTimerType(TimerType type)
{
    m_TimerType = type;
}

template <class T>
void Timer<T>::setInterval(std::uint64_t msec)
{
    m_interval = msec;
}

template <class T>
std::uint64_t Timer<T>::getInterval()
{
    return m_interval;
}

/*
   template <class T>
   void Timer<T>::start(long msec)
   {

    stopTimer();
    startTimer(msec);
    m_handler->OnStart();

   }

   template <class T>
   void Timer<T>::start()
   {

    stopTimer();
    startTimer(m_interval);
    m_handler->OnStart();

   }

   template <class T>
   void Timer<T>::StartTimer(long msec)
   {
    int status;
    struct itimerspec ts;
    struct sigevent se;


     // Set the sigevent structure to cause the signal to be
     //        delivered by creating a new thread.

    se.sigev_notify = SIGEV_THREAD;
    se.sigev_value.sival_ptr = this;
    //se.sigev_notify_function = TimerThreadFunc;
    se.sigev_notify_attributes = NULL;

    status = timer_create(CLOCK_REALTIME, &se, &m_TimerID);
    if (status == -1) {
        //Handle Timer Create Error;
        return;
    }

    status = timer_settime(m_TimerID, 0, &ts, 0);
    if (status == -1)
    {
        //Handle Timer Set Time Error;
        return;
    }
   }

   template <class T>
   void Timer<T>::stopTimer()
   {
    if(m_TimerID != NULL)
    {
        try
        {
            stop();
        }
        catch(...TimerException& ex)
        {   //Catching exception if any during stoping of alraedy started timer
            std::cout<<"Exception in stopping the timer."<<ex.what()<< std::endl;
        }
    }
   }

   template <class T>
   void Timer<T>::stop()
   {
    int status = timer_delete(m_TimerID);
    if (status == -1)
    {
       // Handle Timer Delete Error;
        return;
    }
    m_TimerID = NULL;
    m_handler->OnStop();
   }
 */

