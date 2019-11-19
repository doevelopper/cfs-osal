

#ifndef CFS_OSAL_TIMEFIXTURE_HPP
#define CFS_OSAL_TIMEFIXTURE_HPP

#include <ctime>
#include <chrono>
#include <sstream>
#include <thread>
#include <functional>

#include <cfs/osal/Export.hpp>

namespace cfs::osal
{
    class CFS_OSAL_MAIN_EXPORT TimeFixture
    {
        public:

            TimeFixture() = delete;
            /*!
             * @brief Construct a new Time Fixture object
             *
             * @param name
             * @param unit
             */
            TimeFixture(const char* name, std::size_t unit = 0);
            TimeFixture(const TimeFixture&) = delete;
            TimeFixture(TimeFixture&&) = delete;
            TimeFixture& operator=(const TimeFixture&) = delete;
            TimeFixture& operator=(TimeFixture&&) = delete;
            ~TimeFixture();

        private:

            static unsigned                                    m_timerNumber;
            std::chrono::time_point<std::chrono::system_clock> m_start;
            const char*                                        m_name;
            const unsigned                                     m_number;
            std::size_t                                        m_unit;
            std::stringstream                                  m_timeInformation;
    };
}

#endif

