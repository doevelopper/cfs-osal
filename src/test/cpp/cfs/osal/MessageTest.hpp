

#ifndef CFS_OSAL_MESSAGETEST_HPP
#define CFS_OSAL_MESSAGETEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/Message.hpp>

namespace cfs::osal::test
{
    class MessageTest : public ::testing::Test
    {
        public:

            MessageTest();
            MessageTest(const MessageTest&) = default;
            MessageTest(MessageTest&&) = default;
            MessageTest& operator=(const MessageTest&) = default;
            MessageTest& operator=(MessageTest&&) = default;
            virtual ~MessageTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

