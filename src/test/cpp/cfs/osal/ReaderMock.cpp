

#include <cfs/osal/ReaderMock.hpp>

using namespace cfs::osal::test::mock;
log4cxx::LoggerPtr ReaderMock::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.mock.test.ReaderMock"));

ReaderMock::ReaderMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ReaderMock::~ReaderMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

