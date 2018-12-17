

#ifndef CFS_OSAL_SYSTEMMONITORTEST_HPP
#define CFS_OSAL_SYSTEMMONITORTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/SystemMonitor.hpp>


namespace cfs::osal::test
{
    class SystemMonitorTest : public ::testing::Test
    {
        public:

            SystemMonitorTest();
            SystemMonitorTest(const SystemMonitorTest&) = default;
            SystemMonitorTest(SystemMonitorTest&&) = default;
            SystemMonitorTest& operator=(const SystemMonitorTest&) = default;
            SystemMonitorTest& operator=(SystemMonitorTest&&) = default;
            virtual ~SystemMonitorTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

