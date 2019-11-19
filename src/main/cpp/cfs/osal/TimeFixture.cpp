

#include <cfs/osal/TimeFixture.hpp>

using namespace cfs::osal;
unsigned int m_timerMumber = 0;

TimeFixture::TimeFixture(const char* name, std::size_t unit)
    : m_start(std::chrono::system_clock::now())
    , m_name(name)
    , m_number(m_timerMumber++)
    , m_unit(unit)
    , m_timeInformation()
{
    m_timeInformation << "TIMER START [" << m_number << "] - " << m_name;
}

TimeFixture::~TimeFixture()
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

