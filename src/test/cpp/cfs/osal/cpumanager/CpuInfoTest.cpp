
#include <cfs/osal/cpumanager/CpuInfoTest.hpp>

using namespace cfs::osal::cpumanager;
using namespace cfs::osal::cpumanager::test;
//log4cxx::LoggerPtr ManagerTest::logger =
//    log4cxx::Logger::getLogger(std::string("cfs..test.ManagerTest"));
CpuInfoTest::CpuInfoTest()
    : m_targetUnderTest()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

CpuInfoTest::~CpuInfoTest()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void CpuInfoTest::SetUp()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    m_targetUnderTest = new CpuInfo();
}

void CpuInfoTest::TearDown()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete m_targetUnderTest;
}

TEST_F(CpuInfoTest, test_Simple)
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
