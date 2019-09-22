

#include <cstddef>
#include <set>
#include <algorithm>
#include <atomic>
#include <thread>
#include <unistd.h>

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

        private:

            std::set<size_t> processorsAvailable();
            static thread_local int           m_core = 1;
            mutable std::atomic<std::uint8_t> m_counter;
            const std::uint8_t                mtotalCores;
    };
}

