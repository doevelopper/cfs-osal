

#include <cfs/osal/CpuAffinity.hpp>
#include <pthread.h>
#include <sched.h>
#include <sys/cpuset.h>

using namespace cfs::osal;

CpuAffinity::CpuAffinity()
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

