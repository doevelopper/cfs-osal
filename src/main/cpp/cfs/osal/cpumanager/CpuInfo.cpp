

#include <fstream>
#include <sstream>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>

#include <cfs/osal/cpumanager/CpuInfo.hpp>

using namespace cfs::osal::cpumanager;

CpuInfo::CpuSpec::CpuSpec()
:  m_cpuSocket(-1)
,  m_cpuCore(-1)
,  m_cpuProcessingUnit(-1)
{

}

CpuInfo::CpuSpec::CpuSpec(std::uint32_t cpuSocket,std::uint32_t cpuCore,std::uint32_t cpuProcessingUnit)
:  m_cpuSocket(cpuSocket)
,  m_cpuCore(cpuCore)
,  m_cpuProcessingUnit(cpuProcessingUnit)
{

}
/*
CpuInfo::CpuSpec CpuInfo::CpuSpec::parse(const std::string &rhs)
{
    std::istringstream buf(rhs);
    CpuInfo::CpuSpec spec;
    buf >> spec;
    return (spec);
}
*/
CpuInfo::CpuSpec::~CpuSpec()
{

}

std::uint32_t  CpuInfo::CpuSpec::cpuSocket() const
{
    return(m_cpuSocket);
}
void CpuInfo::CpuSpec::cpuSocket(const std::uint32_t cpuSocket)
{
    m_cpuSocket = std::move(cpuSocket);
}
std::uint32_t CpuInfo::CpuSpec::cpuCore() const
{
    return (m_cpuCore);
}
void CpuInfo::CpuSpec::cpuCore(const std::uint32_t cpuCore)
{
    m_cpuCore = std::move(cpuCore);
}
std::uint32_t CpuInfo::CpuSpec::cpuProcessingUnit() const
{
    return (m_cpuProcessingUnit);
}
void CpuInfo::CpuSpec::cpuProcessingUnit(const std::uint32_t cpuProcessingUnit)
{
    m_cpuProcessingUnit = std::move(cpuProcessingUnit);
}

std::uint32_t CpuInfo::getOnlineProcessors ()
{
    return (std::uint32_t) sysconf(_SC_NPROCESSORS_ONLN);
}

void CpuInfo::readProcFile ()
{
    std::ifstream procCpuInfo( "/proc/cpuinfo" );
    {
        for ( std::string line; std::getline( procCpuInfo, line ); )
        {
        }
    }
}

