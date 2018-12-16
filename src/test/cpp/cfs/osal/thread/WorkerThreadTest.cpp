

#include <cfs/osal/thread/WorkerThreadTest.hpp>


using namespace cfs::osal::thread::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr WorkerThreadTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.WorkerThreadTest"));


WorkerThreadTest::WorkerThreadTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

WorkerThreadTest::~WorkerThreadTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void WorkerThreadTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void WorkerThreadTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(WorkerThreadTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(WorkerThreadTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

