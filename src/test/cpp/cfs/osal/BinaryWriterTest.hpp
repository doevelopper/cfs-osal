

#ifndef CFS_OSAL_BINARYWRITERTEST_HPP
#define CFS_OSAL_BINARYWRITERTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/BinaryWriter.hpp>


namespace cfs::osal::test
{
    class BinaryWriterTest : public ::testing::Test
    {
        public:

            BinaryWriterTest();
            BinaryWriterTest(const BinaryWriterTest&) = default;
            BinaryWriterTest(BinaryWriterTest&&) = default;
            BinaryWriterTest& operator=(const BinaryWriterTest&) = default;
            BinaryWriterTest& operator=(BinaryWriterTest&&) = default;
            virtual ~BinaryWriterTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

