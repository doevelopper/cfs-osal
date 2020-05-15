

#include <cfs/osal/Test.hpp>

using namespace cfs::osal;
using namespace cfs::osal::test;

const unsigned long Test::LOGGER_WATCH_DELAY = 5000UL;
//log4cxx::LoggerPtr Test::logger =
//    log4cxx::Logger::getLogger(std::string("cfs.osal.log.test.Test"));

Test::Test()
    : m_testSuites(std::string() )
    , m_numberOfTestIteration(1)
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

Test::Test(std::string & suite, unsigned int iteration)
    : m_testSuites(suite)
    , m_numberOfTestIteration(iteration)
{
    //    testsLoggingService = new Logger(LOGGER_WATCH_DELAY);
    //    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

Test::~Test()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void Test::notYetImplemented()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    GTEST_NONFATAL_FAILURE_("Not YET implemented!!!!!!");
}

int Test::run (int argc, char * argv[])
{
    //    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    //  ::testing::InitGoogleTest(&argc, argv);
    // ::testing::GTEST_FLAG(filter) = suite;
    // GTEST_FLAG(output) = "xml:" + testOuputPath;
    // ::testing::GTEST_FLAG(output) = "xml:cfs-osal-Test-Report.xml";
    // ::testing::FLAGS_gmock_verbose = "verbose";
    // ::testing::GTEST_FLAG(print_time) = false;

    try
    {
        ::testing::InitGoogleTest(&argc, argv);
        //::testing::InitGoogleMock(&argc , argv);
    }
    catch (std::exception & e)
    {
        // LOG_ERROR(logger , "Issues while innitializing test environment" << typeid (e).name () << ": " << e.what ()
        // );
        std::cerr << "Issues while innitializing test environment" << typeid (e).name () << ": " << e.what () <<
            std::endl;
    }
    catch (...)
    {
        std::cerr << "Unhandled exception" <<std::endl;
    }

    return RUN_ALL_TESTS();
}

void Test::showUsage(std::string name)
{
    //    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help \t Show this help message\n"
              << "\t-i,--iterration \t Number of iteration on test Default 1\n"
              << "\t-o,--outputpath \t Specify the destination path Default netx to executable\n"
              << "\t-m,--module \t The name of xml test report to be generated\n"
              << "\t-l,--list \t Specify the list of tests to be executed Default netx to executable\n"
              << std::endl;
}

/*
 *

#include <gtest/gtest.h>

# define EXPECT_NO_DEATH(statement, regex) \
    EXPECT_NO_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)

# define EXPECT_NO_EXIT(statement, predicate, regex) \
    GTEST_NO_DEATH_TEST_(statement, predicate, regex, GTEST_NONFATAL_FAILURE_)

# define GTEST_NO_DEATH_TEST_(statement, predicate, regex, fail) \
  GTEST_AMBIGUOUS_ELSE_BLOCKER_ \
  if (::testing::internal::AlwaysTrue()) { \
    const ::testing::internal::RE& gtest_regex = (regex); \
    ::testing::internal::DeathTest* gtest_dt; \
    if (!::testing::internal::DeathTest::Create(#statement, &gtest_regex, \
        __FILE__, __LINE__, &gtest_dt)) { \
      goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \
    } \
    if (gtest_dt != NULL) { \
      ::testing::internal::scoped_ptr< ::testing::internal::DeathTest> \
          gtest_dt_ptr(gtest_dt); \
      switch (gtest_dt->AssumeRole()) { \
        case ::testing::internal::DeathTest::OVERSEE_TEST: \
          if (gtest_dt->Passed(predicate(gtest_dt->Wait()))) { \
            goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \
          } \
          break; \
        case ::testing::internal::DeathTest::EXECUTE_TEST: { \
          ::testing::internal::DeathTest::ReturnSentinel \
              gtest_sentinel(gtest_dt); \
          GTEST_EXECUTE_DEATH_TEST_STATEMENT_(statement, gtest_dt); \
          gtest_dt->Abort(::testing::internal::DeathTest::TEST_ENCOUNTERED_RETURN_STATEMENT); \
          break; \
        } \
        default: \
          break; \
      } \
    } \
  } else \
    GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__): \
      fail(::testing::internal::DeathTest::LastMessage())

# define ASSERT_NO_EXIT(statement, predicate, regex) \
    GTEST_NO_DEATH_TEST_(statement, predicate, regex, GTEST_FATAL_FAILURE_)

#define ASSERT_NO_DEATH(statement, regex) \
    ASSERT_NO_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)


 */
