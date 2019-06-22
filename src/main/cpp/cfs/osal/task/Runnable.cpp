

#include <cfs/osal/task/Runnable.hpp>

using namespace cfs::osal::task;

Runnable::Runnable()
    : stopTask()
    , m_thread()
{
}

void Runnable::entry(Runnable * Run)
{
    Run->run();
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
    m_thread = std::thread(&Runnable::run, this);
}

