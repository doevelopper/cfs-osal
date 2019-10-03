

#include <unistd.h>
#include <utility>
#include <arpa/inet.h>

#include <cfs/osal/network/Socket.hpp>

using namespace cfs::osal;

Socket::Socket( Domain domain, Type type, int protocol)
    : FileDescriptor(::socket(static_cast<int>(domain), static_cast<int>(type), protocol))
{
    // if (fileDescriptor() < 0)
    // throw_system_error(tag, "Socket()");
}

Socket::~Socket()
{
}

/*
   Socket::Socket(int fd)
    : FileDescriptor(fd)
   {
    // if (fileDescriptor() < 0)
    // throw_system_error(tag, "Socket()", EBADF);
   }

   Socket::Socket(descriptor &&other)
    : FileDescriptor(std::move(other))
   {
    //    if (fileDescriptor() < 0)
    //        throw_system_error(tag, "Socket()", EBADF);
   }

   const Socket &Socket::operator=(const Socket &other) const
   {
    int err = ::dup2(other.fileDescriptor(), fileDescriptor());
    // if (err < 0)
    // throw_system_error(tag, "dup2()");

    return *this;
   }

   void Socket::getsockname(struct sockaddr_storage *saddr, socklen_t *len) const
   {
   std::mutex m
   std::unique_lock<std::mutex> lock(m, std::defer_lock);
   if(lock.try_lock()) {...}
    getsockname((struct sockaddr *) saddr, len);
   }

   void Socket::getpeername(struct sockaddr *saddr, socklen_t *len) const
   {
    //    auto err = ::getpeername(fileDescriptor(), saddr, len);
    // if (err < 0)
    // throw_system_error(tag, "getpeername()");
   }

   void Socket::getpeername(struct sockaddr_storage *saddr, socklen_t *len) const
   {
    getpeername((struct sockaddr *) saddr, len);
   }
 */

