

#ifndef CFS_OSAL_MOCKS_SYSTEMCALLMOCK_HPP
#define CFS_OSAL_MOCKS_SYSTEMCALLMOCK_HPP

#include <cstddef>

#include <functional>

#include <gmock/gmock.h>

#include <cfs/osal/FileDescriptor.hpp>
#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::mocks
{
    class SystemCallMock
    {
        public:

            SystemCallMock();
            SystemCallMock(const SystemCallMock&) = default;
            SystemCallMock(SystemCallMock&&) = default;
            SystemCallMock& operator=(const SystemCallMock&) = default;
            SystemCallMock& operator=(SystemCallMock&&) = default;
            virtual ~SystemCallMock();

        private:

            static std::function<ssize_t(std::int32_t, void*, std::size_t, off_t)>                m_pread;
            static std::function<ssize_t(std::int32_t, const void*, std::size_t, off_t)>          m_pwrite;
            static std::function<ssize_t(std::int32_t, const struct iovec*, std::int32_t, off_t)> m_preadv;
            static std::function<ssize_t(std::int32_t, const struct iovec*, std::int32_t, off_t)> m_pwritev;
            static std::function<std::int32_t(std::int32_t)>                                      m_fsync;
            static std::function<std::int32_t(std::int32_t)>                                      m_close;
            static std::function<std::int32_t(const char*)>                                       m_unlink;
            static std::function<std::int32_t(const char*, std::int32_t)>                         m_open;
            static std::function<std::int32_t(std::int32_t, off_t)>                               m_ftruncate;
            static std::function<std::int32_t(std::int32_t, struct stat*)>                        m_fstat;
            static log4cxx::LoggerPtr                                                             logger;
    };
}
#endif

