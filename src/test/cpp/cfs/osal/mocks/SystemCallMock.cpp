

#include <cfs/osal/mocks/SystemCallMock.hpp>

using namespace cfs::osal::mocks;

log4cxx::LoggerPtr SystemCallMock::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.SystemCallMock"));


SystemCallMock::SystemCallMock()
{
    /*
           m_pread = [this](int fd, void *buffer, size_t count, off_t offset)
           {
            //return pread(fd, buffer, count, offset);
        };
     */
}

SystemCallMock::~SystemCallMock()
{
    /*
       m_pread = nullptr;
       m_pwrite = nullptr;
       m_preadv = nullptr;
       m_pwritev = nullptr;
       m_fsync = nullptr;
       m_close = nullptr;
       m_unlink = nullptr;
       m_open = nullptr;
       m_ftruncate = nullptr;
       m_fstat = nullptr;
     */
}

