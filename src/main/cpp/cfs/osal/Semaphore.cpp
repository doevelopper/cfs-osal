

#include <system_error>

#include <cfs/osal/Semaphore.hpp>

using namespace cfs::osal;

Semaphore::Semaphore()
{
    int ret = sem_init(&m_Sem, 0, 0);
    if(ret != 0)
    {
        throw std::system_error(ret, std::system_category());
    }
}

Semaphore::~Semaphore()
{
    int ret = sem_close(&m_Sem);
    if(ret != 0)
    {
        throw std::system_error(ret, std::system_category());
    }
}

inline
void Semaphore::post()
{
    sem_post(&m_Sem);
}

inline
void Semaphore::wait()
{
    sem_wait(&m_Sem);
}

inline
bool Semaphore::tryWait()
{
    return (!sem_trywait(&m_Sem) ? true : false);
}

