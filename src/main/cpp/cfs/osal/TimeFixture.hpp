

#ifndef CFS_OSAL_TIMEFIXTURE_HPP
#define CFS_OSAL_TIMEFIXTURE_HPP

#include <ctime>
#include <chrono>
#include <sstream>

#include <cfs/osal/Export.hpp>

namespace cfs::osal
{
    class CFS_OSAL_MAIN_EXPORT TimeFixture
    {
        public:

            TimeFixture(const char* name, std::size_t unit = 0)
                : m_start(std::chrono::system_clock::now())
                , m_name(name)
                , m_number(s_timer_number++)
                , m_unit(unit)
                , m_timeInformation()
            {
                m_timeInformation << "TIMER START [" << m_number << "] - " << m_name;
            }

            ~TimeFixture()
            {
                std::chrono::time_point<std::chrono::system_clock> end
                    = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end - m_start;
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);

                char mbstr[100];
                std::strftime(mbstr, sizeof(mbstr), "%X", std::localtime(&end_time));

                m_timeInformation << "TIMER END [" << m_number << "] " << m_name
                                  << " -  completed @ " << mbstr << " elapsed time: "
                                  << elapsed_seconds.count() << "s";
                if(m_unit)
                {
                    double per_unit = elapsed_seconds.count() / m_unit;
                    m_timeInformation <<" @" << per_unit << " s/cycle freq: " << 1./per_unit << "/s";
                }
            }

        private:

            static unsigned                                    s_timer_number;
            std::chrono::time_point<std::chrono::system_clock> m_start;
            const char*                                        m_name;
            const unsigned                                     m_number;
            std::size_t                                        m_unit;
            std::stringstream                                  m_timeInformation;
    };
}

#endif

