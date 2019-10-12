

#ifndef CFS_OSAL_CPUMANAGER_CPUINFO_HPP
#define CFS_OSAL_CPUMANAGER_CPUINFO_HPP

#include <vector>
#include <string>
#include <tuple>

namespace cfs::osal::cpumanager
{
    class CpuInfo
    {
        using std::tuple<std::string, std::string> kv;
        using std::vector<kv> kvVect;

        public:

            static bool parse( std::string const &cpuinfostrbuf,
                               std::vector<kvVect> &res);
            static bool cpuinfoSummary(
                std::vector<kvVect> &res);
            static bool cpuinfoOnline(
                std::vector<std::uint8_t> & cpus);
            static bool cpuinfoDetails(
                std::vector<std::uint8_t> & cpus);

        protected:

        private:
    };
}

#endif

