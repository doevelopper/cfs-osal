

#include <cfs/osal/BinaryWriterTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr BinaryWriterTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.BinaryWriterTest"));


BinaryWriterTest::BinaryWriterTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

BinaryWriterTest::~BinaryWriterTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void BinaryWriterTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void BinaryWriterTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(BinaryWriterTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(BinaryWriterTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

