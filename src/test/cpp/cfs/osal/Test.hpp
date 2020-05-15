

#ifndef CFS_OSAL_TEST_TEST_HPP
#define CFS_OSAL_TEST_TEST_HPP

#include <vector>
#include <gmock/gmock.h>

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
            // Mechanism for reporting unit tests for which there is no implementation yet.
            void notYetImplemented();

        private:

            std::string  m_testSuites;
            unsigned int m_numberOfTestIteration;
            static const unsigned long LOGGER_WATCH_DELAY;
    };
}

#endif

