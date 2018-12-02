

#include <iostream>
#include <cstdlib>

#include <cfs/osal/Test.hpp>

int main(int argc, char**argv)
{
    cfs::osal::test::Test cfsOsalTest;
    // log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info("Running UnitTest");
    cfsOsalTest.run(argc,argv);

    return (EXIT_SUCCESS);
}

