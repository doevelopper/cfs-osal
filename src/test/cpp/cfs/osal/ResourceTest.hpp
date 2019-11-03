

#ifndef CFS_OSAL_TASK_RESOURCETEST_HPP
#define CFS_OSAL_TASK_RESOURCETEST_HPP

#include <cfs/osal/Resource.hpp>
#include <cfs/osal/log/TestLogger.hpp>

#include <gmock/gmock.h>

namespace cfs::osal::test
{
    template <typename V>
    class ResourceTest : public ::testing::Test
    {
        public:

            ResourceTest();
            ResourceTest(const ResourceTest&) = default;
            ResourceTest(ResourceTest&&) = default;
            ResourceTest& operator=(const ResourceTest&) = default;
            ResourceTest& operator=(ResourceTest&&) = default;
            virtual ~ResourceTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;
    };
    TYPED_TEST_SUITE_P(ResourceTest);
}

#endif

