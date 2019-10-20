

#include <cfs/osal/CpuAffinityTest.hpp>

using namespace cfs::osal::test;

CpuAffinityTest::CpuAffinityTest()
    : testee()
{
}

void CpuAffinityTest::SetUp ()
{
    //    testee = new CpuAffinity();
}

void CpuAffinityTest::TearDown ()
{
    //    delete testee;
}

TEST_F(CpuAffinityTest, testBlaBlaBla)
{
    //    type ts = testee->methodCall();
}

