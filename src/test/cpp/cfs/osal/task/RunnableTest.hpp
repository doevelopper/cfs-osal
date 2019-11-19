

#ifndef CFS_OSAL_TASK_RUNNABLETEST_HPP
#define CFS_OSAL_TASK_RUNNABLETEST_HPP

#include <cfs/osal/task/Runnable.hpp>
#include <cfs/osal/log/TestLogger.hpp>
#include <gmock/gmock.h>

namespace cfs::osal::task::test
{
    class RunnableMock : public ::testing::NiceMock<cfs::osal::task::Runnable>
    {
        public:

            RunnableMock() = default;
            virtual ~RunnableMock() = default;

            MOCK_METHOD(void,routine,(), (override));
            MOCK_METHOD(void,exception,(const std::exception & except), (override));
            MOCK_METHOD(void,error,(), (override));
    };

    class RunnableTest : public ::testing::Test
    {
        public:

            RunnableTest();
            RunnableTest(const RunnableTest&) = default;
            RunnableTest(RunnableTest&&) = default;
            RunnableTest& operator=(const RunnableTest&) = default;
            RunnableTest& operator=(RunnableTest&&) = default;
            virtual ~RunnableTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            RunnableMock *            testee;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

