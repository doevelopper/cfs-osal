

#include <cfs/osal/MessageDataTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr MessageDataTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.MessageDataTest"));


MessageDataTest::MessageDataTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MessageDataTest::~MessageDataTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageDataTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageDataTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MessageDataTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}
TEST_F(MessageDataTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

