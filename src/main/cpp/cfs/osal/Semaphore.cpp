

#include <system_error>

#include <cfs/osal/Semaphore.hpp>

using namespace cfs::osal;

Semaphore::Semaphore(std::int32_t pshared, std::uint32_t value)
{
    int ret = sem_init(&m_Sem, pshared, value);
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

void Semaphore::post()
{
    sem_post(&m_Sem);
}

void Semaphore::wait()
{
    sem_wait(&m_Sem);
}

bool Semaphore::tryWait()
{
    return (!sem_trywait(&m_Sem) ? true : false);
}

