

#include <cfs/osal/SerializableTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr SerializableTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                             "cfs.osal.task.test.SerializableTest"));

SerializableTest::SerializableTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

SerializableTest::~SerializableTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SerializableTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void SerializableTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

