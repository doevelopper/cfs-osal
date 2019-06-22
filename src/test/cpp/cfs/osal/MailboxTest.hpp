

#ifndef CFS_OSAL_MAILBOXTEST_HPP
#define CFS_OSAL_MAILBOXTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
//#include <cfs/osal/Mailbox.hpp>

namespace cfs::osal::test
{
    class MailboxTest : public ::testing::Test
    {
        public:

            MailboxTest();
            MailboxTest(const MailboxTest&) = default;
            MailboxTest(MailboxTest&&) = default;
            MailboxTest& operator=(const MailboxTest&) = default;
            MailboxTest& operator=(MailboxTest&&) = default;
            virtual ~MailboxTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

