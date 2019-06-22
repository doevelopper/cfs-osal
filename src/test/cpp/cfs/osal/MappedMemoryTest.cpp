

#include <cfs/osal/MappedMemoryTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr MappedMemoryTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.MappedMemoryTest"));


MappedMemoryTest::MappedMemoryTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MappedMemoryTest::~MappedMemoryTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MappedMemoryTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MappedMemoryTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MappedMemoryTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}
TEST_F(MappedMemoryTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

