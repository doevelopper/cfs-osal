

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

CpuAffinity & CpuAffinity::operator=(const CpuAffinity & rhs)
{
    copy_cpuset(rhs);
    return (*this);
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

CpuAffinity& CpuAffinity::getCpuAffinity()
{
       CpuAffinity ret;
       auto err = sched_getaffinity(0, sizeof(ret.m_cpu), &ret.m_cpu);
        if (err < 0)
        {
            throw std::system_error(errno, std::system_category());
        }
    return (ret);
}

void CpuAffinity::copy_cpuset(const CpuAffinity &other)
{
    std::memcpy(&m_cpu, &other.m_cpu, sizeof(cpu_set_t));
}

std::uint32_t CpuAffinity::bindToCpu (std::uint32_t index)
{
    std::uint32_t retval;
    cpu_set_t cpuset;
    std::memset(&cpuset, 0, sizeof(cpu_set_t));
    CPU_SET(index, &cpuset);
    retval = sched_setaffinity(0, sizeof( cpu_set_t ), &cpuset);
    return (retval);
}

std::uint8_t CpuAffinity::get_current_cpu()
{
    return (sched_getcpu());
}

void CpuAffinity::set_cpu_affinity(const CpuAffinity &cpuAffinity)
{
    auto err = sched_setaffinity(0, sizeof(cpuAffinity.m_cpu), &cpuAffinity.m_cpu);
    if (err < 0)
    {
        throw std::system_error(errno, std::system_category());
    }
}
