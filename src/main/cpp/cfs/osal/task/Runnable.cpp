

#include <cfs/osal/task/Runnable.hpp>

using namespace cfs::osal::task;

Runnable::Runnable()
    : stopTask()
    , m_thread()
{
}

Runnable::~Runnable()
{
    try
    {
        stop();
    }
    catch(...)
    {     /*??*/
    }
}

void Runnable::entry(Runnable * runnable)
{
    runnable->routine();
}

void Runnable::stop()
{
    stopTask = true;
    m_thread.join();
}

void Runnable::start()
{
    m_thread = std::thread(&Runnable::routine, this);
}

