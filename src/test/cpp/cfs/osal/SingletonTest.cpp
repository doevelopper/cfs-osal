

#include <cfs/osal/SingletonTest.hpp>


using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr SingletonTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.SingletonTest"));


SingletonTest::SingletonTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SingletonTest::~SingletonTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SingletonTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SingletonTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(SingletonTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(SingletonTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

