

#include <cfs/osal/Test.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

const unsigned long Test::LOGGER_WATCH_DELAY = 5000UL;
log4cxx::LoggerPtr Test::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.log.test.Test"));

Test::Test()
    : m_testSuites(std::string() )
    , m_numberOfTestIteration(1)
{
    testsLoggingService = new TestLogger(LOGGER_WATCH_DELAY);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
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
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete testsLoggingService;
}

void Test::notYetImplemented()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    GTEST_NONFATAL_FAILURE_("Not YET implemented!!!!!!");
}

int Test::run (int argc, char * argv[])
{
    //    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    //  ::testing::InitGoogleTest(&argc, argv);

    if ( m_numberOfTestIteration > 0)
    {
        ::testing::GTEST_FLAG(repeat) = m_numberOfTestIteration;
    }

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

