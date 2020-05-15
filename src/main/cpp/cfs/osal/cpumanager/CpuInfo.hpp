

#ifndef CFS_OSAL_CPUMANAGER_CPUINFO_HPP
#define CFS_OSAL_CPUMANAGER_CPUINFO_HPP
#include <stdlib.h>
#include <iostream>
#include <sstream>
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
            class CpuSpec
            {
                public:
                	CpuSpec();
		            CpuSpec(const CpuSpec&) = delete;
		            CpuSpec(CpuSpec&&) = delete;
		            CpuSpec& operator=(const CpuSpec&) = delete;
		            CpuSpec& operator=(CpuSpec&&) = default;
		            virtual ~CpuSpec();
                    CpuSpec(std::uint32_t cpuSocket,std::uint32_t cpuCore,std::uint32_t cpuProcessingUnit);
                    CpuSpec parse(const std::string &rhs);

                    friend std::istream &operator>>(std::istream &s, CpuSpec &rhs)
                    {
                        s >> rhs.m_cpuSocket;
                        s.get();
                        s >> rhs.m_cpuCore;
                        s.get();
                        s >> rhs.m_cpuProcessingUnit;

                        return (s);
                    }

                    friend std::ostream &operator<<(std::ostream &s, const CpuSpec &rhs)
                    {
                        s << rhs.m_cpuSocket
                        << "," << rhs.m_cpuCore
                        << "," << rhs.m_cpuProcessingUnit;
                        return (s);
                    }

                    bool operator==(const CpuSpec &rhs) const
                    {
                        return (m_cpuSocket == rhs.m_cpuSocket
                            && m_cpuCore == rhs.m_cpuCore
                            && m_cpuProcessingUnit == rhs.m_cpuProcessingUnit);
                    }

                    bool operator<(const CpuSpec &rhs) const
                    {
                        if(m_cpuSocket == rhs.m_cpuProcessingUnit)
                        {
                            return (true);
                        }
                        else if (rhs.m_cpuSocket < m_cpuSocket)
                        {
                            return (false);
                        }
                        else
                        {
                            if(m_cpuCore == rhs.m_cpuCore)
                            {
                                return (true);
                            }
                            else if( rhs.m_cpuCore < m_cpuCore)
                            {
                                return (true);
                            }
                            else
                            {
                                return (m_cpuProcessingUnit < rhs.m_cpuProcessingUnit);
                            }
                        }
                    }
                    std::uint32_t  cpuSocket() const;
                    void cpuSocket(const std::uint32_t cpuSocket);
                    std::uint32_t  cpuCore() const;
                    void cpuCore(const std::uint32_t cpuCore) ;
                    std::uint32_t  cpuProcessingUnit() const;
                    void cpuProcessingUnit(const std::uint32_t cpuProcessingUnit);
                protected:
                private:
                    std::uint32_t  m_cpuSocket;
                    std::uint32_t  m_cpuCore;
                    std::uint32_t  m_cpuProcessingUnit;
            };

            static bool parse( std::string const &cpuinfostrbuf,  std::vector<kvVect> &res);
            static bool cpuinfoSummary( std::vector<kvVect> &res);
            static bool cpuinfoOnline( std::vector<std::uint8_t> & cpus);
            static bool cpuinfoDetails( std::vector<std::uint8_t> & cpus);
            std::uint32_t getOnlineProcessors ();

        protected:

        private:
            void readProcFile ();
    };
}

#endif

/*
FILE *fp = fopen ("/proc/uptime", "r");
*/
