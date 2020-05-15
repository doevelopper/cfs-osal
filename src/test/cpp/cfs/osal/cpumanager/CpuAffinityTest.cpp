

#include <cfs/osal/cpumanager/CpuAffinityTest.hpp>

using namespace cfs::osal::cpumanager;
using namespace cfs::osal::cpumanager::test;

CpuAffinityTest::CpuAffinityTest()
    : testee()
{
}

CpuAffinityTest::~CpuAffinityTest()
{
}

void CpuAffinityTest::SetUp ()
{
    testee = new CpuAffinity();
}

void CpuAffinityTest::TearDown ()
{
    delete testee;
}

TEST_F(CpuAffinityTest, testBlaBlaBla)
{
    testee->max_cpus();
    //    type ts = testee->methodCall();
    /*
    std::vector<std::thread> workers;
	for (int i = 0; i < 10; ++i)
	{
		workers.push_back(std::thread([&, i]() {
			aff.set_core();
			printf("[Thread %d] core: %d\n", i, aff.get_core_num());
		}));
	}

	std::for_each(workers.begin(), workers.end(), [](std::thread &t)
	{
		t.join();
	});
    */

}
