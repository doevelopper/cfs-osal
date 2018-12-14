

#ifndef CFS_OSAL_TEST_TEST_HPP
#define CFS_OSAL_TEST_TEST_HPP

#include <vector>

#include <gmock/gmock.h>

#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::test
{
    class Test
    {
        public:

            Test();
            Test(std::string & suite, unsigned int iteration = 1);
            Test(const Test & orig) = default;
            virtual ~Test();

            int run (int argc = 0, char * argv[] = NULL);
            static void showUsage(std::string name);

        private:

            std::string  m_testSuites;
            unsigned int m_numberOfTestIteration;
            //           cfs::osal::log::test::Logger * testsLoggingService;

            cfs::osal::log::test::TestLogger * testsLoggingService;

            static const unsigned long LOGGER_WATCH_DELAY;
            static log4cxx::LoggerPtr  logger;
    };
}

#endif

