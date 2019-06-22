

#include <cfs/osal/MessageQueueTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr MessageQueueTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.MessageQueueTest"));


MessageQueueTest::MessageQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MessageQueueTest::~MessageQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageQueueTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageQueueTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MessageQueueTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(MessageQueueTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

