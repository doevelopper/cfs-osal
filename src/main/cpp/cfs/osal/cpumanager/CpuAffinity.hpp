

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
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <system_error>

namespace cfs::osal::cpumanager
{
    class CpuAffinity
    {
        public:

            CpuAffinity();
            CpuAffinity(std::uint8_t cpu);
            CpuAffinity(const CpuAffinity &other);
            //CpuAffinity(const CpuAffinity&) = default;
            CpuAffinity(CpuAffinity&&) = delete;
            CpuAffinity &operator=(const CpuAffinity & rhs);
            CpuAffinity& operator=(CpuAffinity&&) = default;
            virtual ~CpuAffinity();

            int setMask(const std::uint8_t & core) const;
            void clear();
            void insert(std::uint8_t cpu);
            void remove(std::uint8_t cpu);
            bool find(std::uint8_t cpu) const;
            std::size_t size() const;
            std::size_t max_cpus() const;
            CpuAffinity& getCpuAffinity();
            std::uint32_t bindToCpu (std::uint32_t index);
            void set_cpu_affinity(const CpuAffinity &CpuAffinity);
            std::uint8_t get_current_cpu();

            CpuAffinity &operator&=(const CpuAffinity &rhs)
            {
                CPU_AND(&m_cpu, &rhs.m_cpu, &m_cpu);

                return (*this);
            }

            CpuAffinity &operator|=(const CpuAffinity &rhs)
            {
                CPU_OR(&m_cpu, &rhs.m_cpu, &m_cpu);

                return (*this);
            }

            CpuAffinity &operator^=(const CpuAffinity &rhs)
            {
                CPU_XOR(&m_cpu, &rhs.m_cpu, &m_cpu);

                return (*this);
            }
            friend bool operator==(const CpuAffinity &lhs, const CpuAffinity &rhs);
            friend CpuAffinity operator&(const CpuAffinity &rhs, const CpuAffinity &lhs);
            friend CpuAffinity operator|(const CpuAffinity &rhs, const CpuAffinity &lhs);
            friend CpuAffinity operator^(const CpuAffinity &rhs, const CpuAffinity &lhs);

        private:

            void copy_cpuset(const CpuAffinity &other);

            std::set<size_t> processorsAvailable();
            static thread_local int           m_core;
            mutable std::atomic<std::uint8_t> m_counter;
            std::uint8_t                      m_totalCores;
            cpu_set_t                         m_cpu;
    };

    bool operator==(const CpuAffinity &lhs, const CpuAffinity &rhs)
    {
        return (CPU_EQUAL(&lhs.m_cpu, &rhs.m_cpu));
    }

    CpuAffinity operator&(const CpuAffinity &rhs, const CpuAffinity &lhs)
    {
        CpuAffinity ret;
        CPU_AND(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);

        return (ret);
    }

    CpuAffinity operator|(const CpuAffinity &rhs, const CpuAffinity &lhs)
    {
        CpuAffinity ret;
        CPU_OR(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);

        return (ret);
    }

    CpuAffinity operator^(const CpuAffinity &rhs, const CpuAffinity &lhs)
    {
        CpuAffinity ret;
        CPU_XOR(&ret.m_cpu, &rhs.m_cpu, &lhs.m_cpu);

        return (ret);
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

        return (os);
    }
}

