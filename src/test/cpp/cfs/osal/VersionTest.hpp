

#ifndef CFS_OSAL_VERSIONTEST_HPP
#define CFS_OSAL_VERSIONTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/Version.hpp>

namespace cfs::osal::test
{
    class VersionTest : public ::testing::Test
    {
        public:

            VersionTest();
            VersionTest(const VersionTest&) = default;
            VersionTest(VersionTest&&) = default;
            VersionTest& operator=(const VersionTest&) = default;
            VersionTest& operator=(VersionTest&&) = default;
            virtual ~VersionTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;
            semver::Version *         testee;

        private:
    };
}
#endif

