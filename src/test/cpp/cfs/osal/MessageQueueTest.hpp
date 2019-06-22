

#ifndef CFS_OSAL_MESSAGEQUEUETEST_HPP
#define CFS_OSAL_MESSAGEQUEUETEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/MessageQueue.hpp>

namespace cfs::osal::test
{
    class MessageQueueTest : public ::testing::Test
    {
        public:

            MessageQueueTest();
            MessageQueueTest(const MessageQueueTest&) = default;
            MessageQueueTest(MessageQueueTest&&) = default;
            MessageQueueTest& operator=(const MessageQueueTest&) = default;
            MessageQueueTest& operator=(MessageQueueTest&&) = default;
            virtual ~MessageQueueTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

