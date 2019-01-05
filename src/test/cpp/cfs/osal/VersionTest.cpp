

#include <cfs/osal/VersionTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr VersionTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.VersionTest"));


VersionTest::VersionTest()
    : objectVersionToTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionTest::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    delete objectVersionToTest;
}

void VersionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void VersionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(VersionTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
TEST_F(VersionTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

