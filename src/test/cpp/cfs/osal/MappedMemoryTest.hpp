

#ifndef CFS_OSAL_MAPPEDMEMORYTEST_HPP
#define CFS_OSAL_MAPPEDMEMORYTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/MappedMemory.hpp>

namespace cfs::osal::test
{
    class MappedMemoryTest : public ::testing::Test
    {
        public:

            MappedMemoryTest();
            MappedMemoryTest(const MappedMemoryTest&) = default;
            MappedMemoryTest(MappedMemoryTest&&) = default;
            MappedMemoryTest& operator=(const MappedMemoryTest&) = default;
            MappedMemoryTest& operator=(MappedMemoryTest&&) = default;
            virtual ~MappedMemoryTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

