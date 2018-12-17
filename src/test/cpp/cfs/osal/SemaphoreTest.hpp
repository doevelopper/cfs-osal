

#ifndef CFS_OSAL_SEMAPHORETEST_HPP
#define CFS_OSAL_SEMAPHORETEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/Semaphore.hpp>


namespace cfs::osal::test
{
    class SemaphoreTest : public ::testing::Test
    {
        public:

            SemaphoreTest();
            SemaphoreTest(const SemaphoreTest&) = default;
            SemaphoreTest(SemaphoreTest&&) = default;
            SemaphoreTest& operator=(const SemaphoreTest&) = default;
            SemaphoreTest& operator=(SemaphoreTest&&) = default;
            virtual ~SemaphoreTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

