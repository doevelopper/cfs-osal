

#include <cfs/osal/BidirectionnalContainerTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr BidirectionnalContainerTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                        "cfs.osal.test.BidirectionnalContainerTest"));


BidirectionnalContainerTest::BidirectionnalContainerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

BidirectionnalContainerTest::~BidirectionnalContainerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void BidirectionnalContainerTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void BidirectionnalContainerTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(BidirectionnalContainerTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(BidirectionnalContainerTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

