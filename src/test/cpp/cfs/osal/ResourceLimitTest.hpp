

#ifndef CFS_OSAL_RESOURCELIMITTEST_HPP
#define CFS_OSAL_RESOURCELIMITTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/ResourceLimit.hpp>

namespace cfs::osal::test
{
    class ResourceLimitTest : public ::testing::Test
    {
        public:

            ResourceLimitTest();
            ResourceLimitTest(const ResourceLimitTest&) = default;
            ResourceLimitTest(ResourceLimitTest&&) = default;
            ResourceLimitTest& operator=(const ResourceLimitTest&) = default;
            ResourceLimitTest& operator=(ResourceLimitTest&&) = default;
            virtual ~ResourceLimitTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;
            ResourceLimit *           testee;

        private:
    };
}

#endif

