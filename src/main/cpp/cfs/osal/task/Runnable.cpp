

#include <cfs/osal/task/Runnable.hpp>

using namespace cfs::osal::task;

Runnable::Runnable()
    : stopTask()
    , m_thread()
{
}

void Runnable::entry(Runnable * runnable)
{
    runnable->routine();
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

void Runnable::stop()
{
    stopTask = true;
    m_thread.join();
}

void Runnable::start()
{
    m_thread = std::thread(&Runnable::routine, this);
}

