

#include <cfs/osal/task/RunnableTest.hpp>

using namespace cfs::osal::log::test;
using namespace cfs::osal::task::test;

log4cxx::LoggerPtr RunnableTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.task.test.RunnableTest"));


RunnableTest::RunnableTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

RunnableTest::~RunnableTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void RunnableTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    testee = new RunnableMock();
}

void RunnableTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete testee;
}

TEST_F(RunnableTest, test_routine)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

