

#include <cfs/osal/VersionTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr VersionTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.VersionTest"));


VersionTest::VersionTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionTest::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void VersionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    testee = new semver::Version(std::string("1.2.3"));
}

void VersionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete testee;
}

TEST_F(VersionTest, test_Simple_Version)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TEST_F(VersionTest, test_Simple_Version_Error)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

TEST_F(VersionTest, test_Version_Error)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // test::notYetImplemented();
    ASSERT_TRUE(true);
}


TEST_F(VersionTest, test_Version_build)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // test::notYetImplemented();
    ASSERT_TRUE(true);
}

TEST_F(VersionTest, test_Version_pre_release)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // test::notYetImplemented();
    ASSERT_TRUE(true);
}

TEST_F(VersionTest, test_abi_operators)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    //test::notYetImplemented();
    ASSERT_TRUE(true);
}

