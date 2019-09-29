

#ifndef CFS_OSAL_LOCKTEST_HPP
#define CFS_OSAL_LOCKTEST_HPP

#include <gtest/gtest.h>
#include <cfs/osal/Lock.hpp>

namespace cfs::osal::test
{
    class LockTest : public ::testing::Test
    {
        public:

            LockTest();
            LockTest(const LockTest&) = default;
            LockTest(LockTest&&) = default;
            LockTest& operator=(const LockTest&) = default;
            LockTest& operator=(LockTest&&) = default;
            virtual ~LockTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}

#endif

