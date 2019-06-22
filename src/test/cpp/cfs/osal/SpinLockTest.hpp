

#ifndef CFS_OSAL_SPINLOCKTEST_HPP
#define CFS_OSAL_SPINLOCKTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/SpinLock.hpp>

namespace cfs::osal::test
{
    class SpinLockTest : public ::testing::Test
    {
        public:

            SpinLockTest();
            SpinLockTest(const SpinLockTest&) = default;
            SpinLockTest(SpinLockTest&&) = default;
            SpinLockTest& operator=(const SpinLockTest&) = default;
            SpinLockTest& operator=(SpinLockTest&&) = default;
            virtual ~SpinLockTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

