

#include <fstream>
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>

#include <cfs/osal/cpumanager/CpuInfo.hpp>

using namespace cfs::osal::cpumanager;

void CpuInfo::readProcFile ()
{
    std::ifstream procCpuInfo( "/proc/cpuinfo" );
    {
        for ( std::string line; std::getline( procCpuInfo, line ); )
        {
        }
    }
}

