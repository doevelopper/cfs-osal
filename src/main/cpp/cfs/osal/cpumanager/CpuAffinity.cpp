

#include <fstream>
#include <iterator>
#include <cfs/osal/cpumanager/CpuAffinity.hpp>
#include <pthread.h>
#include <sched.h>

using namespace cfs::osal::cpumanager;

CpuAffinity::CpuAffinity()
    : m_counter(0)
    ,m_totalCores(std::max<ushort>(std::thread::hardware_concurrency(), 1))
{
    std::ifstream cpuinfo("/proc/cpuinfo");
    m_totalCores = std::count(std::istream_iterator<std::string>(cpuinfo),
                              std::istream_iterator<std::string>(),
                              std::string("processor"));
    clear();
}

// CpuAffinity::CpuAffinity(std::uint8_t cpu)
// {
// clear();
// insert(cpu);
// }

CpuAffinity::CpuAffinity(const CpuAffinity &other)
{
    copy_cpuset(other);
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

void CpuAffinity::clear()
{
    CPU_ZERO(&m_cpu);
}

// void CpuAffinity::insert(std::uint8_t cpu)
// {
// CPU_SET(cpu, &m_cpu);
// }

void CpuAffinity::remove(std::uint8_t cpu)
{
    CPU_CLR(cpu, &m_cpu);
}

bool CpuAffinity::find(std::uint8_t cpu) const
{
    return CPU_ISSET(cpu, &m_cpu);
}

std::size_t CpuAffinity::size() const
{
    return CPU_COUNT(&m_cpu);
}

std::size_t CpuAffinity::max_cpus() const
{
    return CPU_SETSIZE - 1;
}

