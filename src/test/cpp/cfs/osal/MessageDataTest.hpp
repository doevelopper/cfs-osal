

#ifndef CFS_OSAL_MESSAGEDATATEST_HPP
#define CFS_OSAL_MESSAGEDATATEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::test
{
    class MessageDataTest : public ::testing::Test
    {
        public:

            MessageDataTest();
            MessageDataTest(const MessageDataTest&) = default;
            MessageDataTest(MessageDataTest&&) = default;
            MessageDataTest& operator=(const MessageDataTest&) = default;
            MessageDataTest& operator=(MessageDataTest&&) = default;
            virtual ~MessageDataTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

