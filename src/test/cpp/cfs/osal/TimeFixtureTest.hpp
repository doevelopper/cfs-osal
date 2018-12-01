

#ifndef CFS_OSAL_TIMEFIXTURETEST_HPP
#define CFS_OSAL_TIMEFIXTURETEST_HPP

#include <gmock/gmock.h>

namespace cfs::osal::test
{
    class TimeFixtureTest : public ::testing::Test
    {
        public:

            TimeFixtureTest();
            TimeFixtureTest(const TimeFixtureTest&) = default;
            TimeFixtureTest(TimeFixtureTest&&) = default;
            TimeFixtureTest& operator=(const TimeFixtureTest&) = default;
            TimeFixtureTest& operator=(TimeFixtureTest&&) = default;
            virtual ~TimeFixtureTest();

            void SetUp() override;
            void TearDown() override;

        protected:

        private:
    };
}
#endif

