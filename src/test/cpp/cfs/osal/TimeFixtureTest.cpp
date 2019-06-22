

#include <cfs/osal/TimeFixtureTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr TimeFixtureTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.TimeFixtureTest"));


TimeFixtureTest::TimeFixtureTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TimeFixtureTest::~TimeFixtureTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void TimeFixtureTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void TimeFixtureTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(TimeFixtureTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}
TEST_F(TimeFixtureTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

