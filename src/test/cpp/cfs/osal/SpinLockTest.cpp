

#include <cfs/osal/SpinLockTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr SpinLockTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.SpinLockTest"));


SpinLockTest::SpinLockTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SpinLockTest::~SpinLockTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SpinLockTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SpinLockTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(SpinLockTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(SpinLockTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

