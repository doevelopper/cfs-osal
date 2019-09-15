

#include <cstddef>
#include <set>

namespace cfs::osal
{
    class CpuAffinity
    {
        private:

            std::set<size_t> processorsAvailable();
    }
}

