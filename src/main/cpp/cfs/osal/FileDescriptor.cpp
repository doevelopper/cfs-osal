

#include <cerrno>
#include <fcntl.h>
#include <utility>
#include <system_error>

#include <cfs/osal/FileDescriptor.hpp>

using namespace cfs::osal;


FileDescriptor::FileDescriptor(std::int32_t fd) CFS_OSAL_NOEXCEPT
    :  m_fileDescriptor(fd) //::open(path.c_str(), oflag);
{
    if(m_fileDescriptor < 0)
    {
        throw std::system_error(EFAULT, std::system_category());// throw bad fd
    }
}

FileDescriptor::FileDescriptor(FileDescriptor && rhs)
    : m_fileDescriptor(rhs.m_fileDescriptor)
{
    std::swap(m_fileDescriptor, rhs.m_fileDescriptor);
    rhs.m_fileDescriptor = -1;
}

FileDescriptor::~FileDescriptor()
{
    if((m_fileDescriptor >= 0) && (::fcntl(m_fileDescriptor, F_GETFD) != -1 || errno != EBADF))
    {
        ::close(m_fileDescriptor);
    }
}

bool FileDescriptor::isInUse() const
{
    return (::fcntl(m_fileDescriptor, F_GETFD) != -1 || errno != EBADF);
}

FileDescriptor & FileDescriptor::operator = (FileDescriptor && rhs)
{
    if (this != &rhs)
    {
        //    close();
    }

    std::swap(m_fileDescriptor, rhs.m_fileDescriptor);

    return (*this);
}

std::int32_t FileDescriptor::fileDescriptorOperations(std::int32_t command)
{
    std::int32_t result = ::fcntl(m_fileDescriptor, command);
    if (result < 0)
        throw std::system_error(errno, std::system_category(), "what");

    return (result);
}

std::int32_t FileDescriptor::fileDescriptorOperations(std::int32_t command, std::uint8_t arguments)
{
    std::int32_t result = ::fcntl(m_fileDescriptor, command, arguments);
    if (result < 0)
        throw std::system_error(errno, std::system_category(), "what");

    return (result);
}

std::int32_t FileDescriptor::fileDescriptorOperations(std::int32_t command, struct flock * fileLocking)
{
    std::int32_t result = ::fcntl(m_fileDescriptor, command, fileLocking);
    if (result < 0)
        throw std::system_error(errno, std::system_category(), "what");

    return (result);
}

std::size_t FileDescriptor::read(char *buffer, std::size_t size) const
{
    auto n = ::read(m_fileDescriptor, buffer, size);
    if (n < 0)
        //throw std::system_error(errno, "read()");
        throw std::system_error(EFAULT, std::generic_category());

    return (static_cast<std::size_t>(n));
}

std::size_t FileDescriptor::write(const char *buffer, std::size_t size) const
{
    auto n = ::write(m_fileDescriptor, buffer, size);
    if (n < 0)
        //throw std::system_error(errno, "write()");
        throw std::system_error(EFAULT, std::generic_category());

    return (static_cast<std::size_t>(n));
}

std::size_t FileDescriptor::pread(char *buffer, std::size_t size, std::size_t off) const
{
    auto n = ::pread(m_fileDescriptor, buffer, size, static_cast<off_t>(off));
    if (n < 0)
        //throw std::system_error(errno, "pread()");
        throw std::system_error(EFAULT, std::generic_category());

    return (static_cast<std::size_t>(n));
}

std::size_t FileDescriptor::pwrite(const char *buffer,
                                   std::size_t size,
                                   std::size_t off) const
{
    auto n = ::pwrite(m_fileDescriptor, buffer, size, static_cast<off_t>(off));
    if (n < 0)
        throw std::system_error(EFAULT, std::generic_category());
    //throw std::system_error(errno, "pread()");
    //throw std::system_error(EBADF, "pwrite()");

    return (static_cast<std::size_t>(n));
}

