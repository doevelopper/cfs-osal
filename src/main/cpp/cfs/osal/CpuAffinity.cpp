

#include <cfs/osal/CpuAffinity.hpp>
#include <pthread.h>
#include <sched.h>
#include <sys/cpuset.h>

using namespace cfs::osal;

CpuAffinity::CpuAffinity()
    : m_counter(0)
    ,m_totalCores(std::max<ushort>(std::thread::hardware_concurrency(), 1))
{
}

CpuAffinity::~CpuAffinity()
{
}

std::set<size_t>CpuAffinity::processorsAvailable()
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset); // NOLINT(clang-tidy)
    std::set<size_t> processors;

    return (processors);
}

int CpuAffinity::setMask(const std::uint8_t & core) const
{
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core, &cpuset);
    bool er = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    return (!er) ? core : -1;
}

