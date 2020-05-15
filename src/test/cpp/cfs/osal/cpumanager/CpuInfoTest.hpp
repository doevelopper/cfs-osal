#ifndef CFS_OSAL_CPUMANAGER_CPUINFOTEST_HPP
#define CFS_OSAL_CPUMANAGER_CPUINFOTEST_HPP
#include <gtest/gtest.h>
#include <cfs/osal/cpumanager/CpuInfo.hpp>

namespace cfs::osal::cpumanager::test
{
    class CpuInfoTest : public ::testing::Test
    {
        public:

            CpuInfoTest();
            virtual ~CpuInfoTest();

            virtual void SetUp ();
            virtual void TearDown ();

        protected:

            cfs::osal::cpumanager::CpuInfo * m_targetUnderTest;

        private:
    };
}

#endif
