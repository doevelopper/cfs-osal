

#include <cfs/osal/FileDescriptorTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr FileDescriptorTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                               "cfs.osal.test.FileDescriptorTest"));


FileDescriptorTest::FileDescriptorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

FileDescriptorTest::~FileDescriptorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void FileDescriptorTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void FileDescriptorTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(FileDescriptorTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}
TEST_F(FileDescriptorTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

