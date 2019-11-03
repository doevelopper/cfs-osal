

#ifndef CFS_OSAL_TASK_ACTIVATORTEST_HPP
#define CFS_OSAL_TASK_ACTIVATORTEST_HPP

#include <cfs/osal/Activator.hpp>
#include <cfs/osal/log/TestLogger.hpp>
#include <gmock/gmock.h>

namespace cfs::osal::test
{
    using ParameterValueTypes = ::testing::Types<bool, char, int, unsigned int, float, double>;

    template <typename V>
    class ActivatorTest : public ::testing::Test
    {
        public:

            ActivatorTest();
            ActivatorTest(const ActivatorTest&) = default;
            ActivatorTest(ActivatorTest&&) = default;
            ActivatorTest& operator=(const ActivatorTest&) = default;
            ActivatorTest& operator=(ActivatorTest&&) = default;
            virtual ~ActivatorTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            using  testee = Activator<V>;
            using  ValueType = V;

            static log4cxx::LoggerPtr logger;
    };

    TYPED_TEST_SUITE_P(ActivatorTest);
}

#endif

