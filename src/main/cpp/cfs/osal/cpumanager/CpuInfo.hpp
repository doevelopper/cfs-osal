

#ifndef CFS_OSAL_CPUMANAGER_CPUINFO_HPP
#define CFS_OSAL_CPUMANAGER_CPUINFO_HPP

#include <vector>
#include <string>
#include <tuple>
#include <list>

namespace cfs::osal::cpumanager
{
    class CpuInfo
    {
        using kv = std::tuple<std::string, std::string>;
        using kvVect = std::vector<kv>;

        public:

            static bool parse( std::string const &cpuinfostrbuf
                               ,  std::vector<kvVect> &res);
            static bool cpuinfoSummary( std::vector<kvVect> &res);
            static bool cpuinfoOnline( std::vector<std::uint8_t> & cpus);
            static bool cpuinfoDetails( std::vector<std::uint8_t> & cpus);

        protected:

        private:

            void readProcFile ();
    };
}

#endif

