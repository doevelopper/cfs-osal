

#include <cfs/osal/SemaphoreTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr SemaphoreTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.SemaphoreTest"));


SemaphoreTest::SemaphoreTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SemaphoreTest::~SemaphoreTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SemaphoreTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SemaphoreTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(SemaphoreTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(SemaphoreTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

