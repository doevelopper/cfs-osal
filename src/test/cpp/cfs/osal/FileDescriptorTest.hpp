

#ifndef CFS_OSAL_FILEDESCRIPTORTEST_HPP
#define CFS_OSAL_FILEDESCRIPTORTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::test
{
    class FileDescriptorTest : public ::testing::Test
    {
        public:

            FileDescriptorTest();
            FileDescriptorTest(const FileDescriptorTest&) = default;
            FileDescriptorTest(FileDescriptorTest&&) = default;
            FileDescriptorTest& operator=(const FileDescriptorTest&) = default;
            FileDescriptorTest& operator=(FileDescriptorTest&&) = default;
            virtual ~FileDescriptorTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}

#endif

