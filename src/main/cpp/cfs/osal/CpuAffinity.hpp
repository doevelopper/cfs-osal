

#include <cstddef>
#include <set>
#include <algorithm>
#include <atomic>
#include <thread>
#include <unistd.h>
#include <sched.h>
#include <sys/syscall.h>
#include <cerrno>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <system_error>

namespace cfs::osal
{
    class CpuAffinity
    {
        public:

            CpuAffinity();
            ~CpuAffinity();
            /*!
             * @brief
             */
            int setMask(const std::uint8_t & core) const;
            friend bool   operator==(const CpuAffinity &lhs, const CpuAffinity &rhs);
            friend CpuAffinity operator&(const CpuAffinity &rhs, const CpuAffinity &lhs);
            friend CpuAffinity operator|(const CpuAffinity &rhs, const CpuAffinity &lhs);
            friend CpuAffinity operator^(const CpuAffinity &rhs, const CpuAffinity &lhs);
    CpuAffinity()
    {
        clear();
    }

    CpuAffinity(std::uint8_t cpu)
    {
        clear();
        insert(cpu);
    }

    CpuAffinity(const CpuAffinity &other)
    {
        copy_cpuset(other);
    }

    CpuAffinity &operator=(const CpuAffinity &other)
    {
        copy_cpuset(other);
        return *this;
    }

    void clear()
    {
        CPU_ZERO(&m_cpu);
    }

    void insert(std::uint8_t cpu)
    {
        CPU_SET(cpu, &m_cpu);
    }

    void remove(std::uint8_t cpu)
    {
        CPU_CLR(cpu, &m_cpu);
    }

    bool find(std::uint8_t cpu) const
    {
        return CPU_ISSET(cpu, &m_cpu);
    }

    std::size_t size() const
    {
        return CPU_COUNT(&m_cpu);
    }

    std::size_t max_cpus() const
    {
        return CPU_SETSIZE - 1;
    }

    friend void   set_cpu_affinity(const CpuAffinity &CpuAffinity);
    friend CpuAffinity get_cpu_affinity();

    CpuAffinity &operator&=(const CpuAffinity &rhs)
    {
        CPU_AND(&m_cpu, &rhs.m_cpu, &m_cpu);
        return *this;
    }

    CpuAffinity &operator|=(const CpuAffinity &rhs)
    {
        CPU_OR(&m_cpu, &rhs.m_cpu, &m_cpu);
        return *this;
    }

    CpuAffinity &operator^=(const CpuAffinity &rhs)
    {
        CPU_XOR(&m_cpu, &rhs.m_cpu, &m_cpu);
        return *this;
    }
        private:

        void copy_cpuset(const CpuAffinity &other)
        {
            std::memcpy(&m_cpu, &other.m_cpu, sizeof(cpu_set_t));
        }
            std::set<size_t> processorsAvailable();
            static thread_local int           m_core = 1;
            mutable std::atomic<std::uint8_t> m_counter;
            const std::uint8_t                mtotalCores;
            cpu_set_t m_cpu;

    };
bool operator==(const CpuAffinity &lhs, const CpuAffinity &rhs)
{
    return CPU_EQUAL(&lhs.m_cpu, &rhs.m_cpu);
}

CpuAffinity operator&(const CpuAffinity &rhs, const CpuAffinity &lhs)
{
    CpuAffinity ret;
    CPU_AND(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);
    return ret;
}

CpuAffinity operator|(const CpuAffinity &rhs, const CpuAffinity &lhs)
{
    CpuAffinity ret;
    CPU_OR(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);
    return ret;
}

CpuAffinity operator^(const CpuAffinity &rhs, const CpuAffinity &lhs)
{
    CpuAffinity ret;
    CPU_XOR(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);
    return ret;
}

std::ostream &operator<<(std::ostream &os, const CpuAffinity &CpuAffinity)
{
    os << "[";
    for (std::size_t i = 0; i < CpuAffinity.max_cpus(); ++i) {
        if (CpuAffinity.find(i)) {
            os << std::setw(4) << i;
        }
    }

    os << "]";
    return os;
}

std::uint8_t get_current_cpu()
{
    return sched_getcpu();
}

void set_cpu_affinity(const CpuAffinity &CpuAffinity)
{
    auto err = sched_setaffinity(0, sizeof(CpuAffinity.m_cpu), &CpuAffinity.m_cpu);
    if (err < 0) {
        throw std::system_error(errno, std::system_category());
    }
}

CpuAffinity get_cpu_affinity()
{
    CpuAffinity ret;
    auto err = sched_getaffinity(0, sizeof(ret.m_cpu), &ret.m_cpu);
    if (err < 0) {
        throw std::system_error(errno, std::system_category());
    }

    return ret;
}
}

