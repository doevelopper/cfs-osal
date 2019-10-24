

#ifndef CFS_OSAL_TASK_RUNNABLETEST_HPP
#define CFS_OSAL_TASK_RUNNABLETEST_HPP

#include <cfs/osal/task/Runnable.hpp>
#include <gmock/gmock.h>

namespace cfs::osal::task::test
{
    class RunnableMock : public ::testing::NiceMock<Runnable>
    {
        public
        RunnableMock() = default;
        virtual ~RunnableMock();
    };

    class RunnableTest : public ::testing::Test
    {
        public:

            RunnableTest() = default;
            RunnableTest(const RunnableTest&) = default;
            RunnableTest(RunnableTest&&) = default;
            RunnableTest& operator=(const RunnableTest&) = default;
            RunnableTest& operator=(RunnableTest&&) = default;
            virtual ~RunnableTest() = default;

            void SetUp() override;
            void TearDown() override;

        protected:

            RunnableMock *            testee;
            static log4cxx::LoggerPtr logger;
    };
}

#endif

