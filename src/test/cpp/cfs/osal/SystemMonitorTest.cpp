

#include <cfs/osal/SystemMonitorTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr SystemMonitorTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "cfs.osal.test.SystemMonitorTest"));


SystemMonitorTest::SystemMonitorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SystemMonitorTest::~SystemMonitorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SystemMonitorTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SystemMonitorTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(SystemMonitorTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(SystemMonitorTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

