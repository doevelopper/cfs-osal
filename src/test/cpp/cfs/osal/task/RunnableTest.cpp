

#include <cfs/osal/task/RunnableTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

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

