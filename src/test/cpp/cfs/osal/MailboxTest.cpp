

#include <cfs/osal/MailboxTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr MailboxTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.MailboxTest"));


MailboxTest::MailboxTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MailboxTest::~MailboxTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MailboxTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MailboxTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MailboxTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(MailboxTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

