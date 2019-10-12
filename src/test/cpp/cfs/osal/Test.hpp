

#ifndef CFS_OSAL_TEST_TEST_HPP
#define CFS_OSAL_TEST_TEST_HPP

#include <vector>
#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::test
{
    /*
        class GtestExtendedEventListener : public ::testing::TestEventListener
        {
            protected:

                ::testing::TestEventListener* eventListener;

            public:

                // Show the names of each test case.
                bool showTestCases;
                 //Show the names of each test.
                bool showTestNames;
                 // Show each success.
                bool showSuccesses;
                 // Show each failure as it occurs. You will also see it at the bottom after the full suite is run.
                bool showInlineFailures;
                // Show the setup of the global environment.
                bool showEnvironment;

                explicit GtestExtendedEventListener(::testing::TestEventListener* theEventListener)
                    : eventListener(theEventListener)
                {
                    showTestCases = true;
                    showTestNames = true;
                    showSuccesses = true;
                    showInlineFailures = true;
                    showEnvironment = true;
                }

                virtual ~GtestExtendedEventListener()
                {
                    delete eventListener;
                }

                virtual void OnTestProgramStart(const ::testing::UnitTest& unit_test)
                {
                    eventListener->OnTestProgramStart(unit_test);
                }

                virtual void OnTestIterationStart(const ::testing::UnitTest& unit_test, int iteration)
                {
                    eventListener->OnTestIterationStart(unit_test, iteration);
                }

                virtual void OnEnvironmentsSetUpStart(const ::testing::UnitTest& unit_test)
                {
                    if(showEnvironment)
                    {
                        eventListener->OnEnvironmentsSetUpStart(unit_test);
                    }
                }

                virtual void OnEnvironmentsSetUpEnd(const ::testing::UnitTest& unit_test)
                {
                    if(showEnvironment)
                    {
                        eventListener->OnEnvironmentsSetUpEnd(unit_test);
                    }
                }

                virtual void OnTestCaseStart(const ::testing::TestCase& test_case)
                {
                    if(showTestCases)
                    {
                        eventListener->OnTestCaseStart(test_case);
                    }
                }

                virtual void OnTestStart(const ::testing::TestInfo& test_info)
                {
                    if(showTestNames)
                    {
                        eventListener->OnTestStart(test_info);
                    }
                }

                virtual void OnTestPartResult(const ::testing::TestPartResult& result)
                {
                    eventListener->OnTestPartResult(result);
                }

                virtual void OnTestEnd(const ::testing::TestInfo& test_info)
                {
                    if((showInlineFailures && test_info.result()->Failed()) || (showSuccesses &&
                                                                                !test_info.result()->Failed()))
                    {
                        eventListener->OnTestEnd(test_info);
                    }
                }

                virtual void OnTestCaseEnd(const ::testing::TestCase& test_case)
                {
                    if(showTestCases)
                    {
                        eventListener->OnTestCaseEnd(test_case);
                    }
                }

                virtual void OnEnvironmentsTearDownStart(const ::testing::UnitTest& unit_test)
                {
                    if(showEnvironment)
                    {
                        eventListener->OnEnvironmentsTearDownStart(unit_test);
                    }
                }

                virtual void OnEnvironmentsTearDownEnd(const ::testing::UnitTest& unit_test)
                {
                    if(showEnvironment)
                    {
                        eventListener->OnEnvironmentsTearDownEnd(unit_test);
                    }
                }

                virtual void OnTestIterationEnd(const ::testing::UnitTest& unit_test, int iteration)
                {
                    eventListener->OnTestIterationEnd(unit_test, iteration);
                }

                virtual void OnTestProgramEnd(const ::testing::UnitTest& unit_test)
                {
                    eventListener->OnTestProgramEnd(unit_test);
                }
        };
     */
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

            cfs::osal::log::test::TestLogger * testsLoggingService;

            static const unsigned long LOGGER_WATCH_DELAY;
            static log4cxx::LoggerPtr  logger;
    };
}

#endif

