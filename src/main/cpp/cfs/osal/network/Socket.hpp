

#ifndef CFS_OSAL_SOCKET_HPP
#define CFS_OSAL_SOCKET_HPP

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <gnutls/gnutls.h>
#include <string>
#include <cstdint>

#include <cfs/osal/FileDescriptor.hpp>

namespace cfs::osal
{
    class Socket : public FileDescriptor
    {
        enum class Domain : std::uint8_t
        {
            NIX = PF_UNIX, // Local communication
            V4 = PF_INET,  // IPv4
            V6 = PF_INET6, // IPv6
            NETLINK = PF_NETLINK,
            X25 = PF_X25,
            PKT = PF_PACKET
        };
        enum class Type : std::uint8_t
        {
            STREAM = SOCK_STREAM,
            DATAGRAM = SOCK_DGRAM,
            SEQ = SOCK_SEQPACKET,
            RAW = SOCK_RAW
        };

        enum class GnuTLSType : std::uint8_t
        {
            TLS,
            SSL
        };

        enum class ShutDownType : std::uint8_t
        {
            R = SHUT_RD,
            W = SHUT_WR,
            RW = SHUT_RDWR
        };

        public:

            Socket() = delete;
            Socket(Domain domain, Type type, int protocol = 0);
            Socket(Socket&&) = default;
            Socket& operator=(Socket&&) = default;
            virtual ~Socket();

            void connect(const struct sockaddr *saddr, socklen_t len) const;
            void connect(const struct sockaddr_un &saddr) const;
            void connect(const struct sockaddr_in &saddr) const;
            void connect(const struct sockaddr_in6 &saddr) const;

            void bind(const struct sockaddr *saddr, socklen_t len) const;
            void bind(const struct sockaddr_un &saddr) const;
            void bind(const struct sockaddr_in &saddr) const;
            void bind(const struct sockaddr_in6 &saddr) const;

            void listen(std::int8_t backlog = 5) const;

            Socket accept() const;
            Socket accept(struct sockaddr *saddr, socklen_t *len) const;
            Socket accept(struct sockaddr_storage *saddr, socklen_t *len) const;

            std::size_t recv(char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t recvmsg(struct msghdr &msg, std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer,
                                 std::size_t size,
                                 struct sockaddr *saddr,
                                 socklen_t *len,
                                 std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t recvfrom(char *buffer,
                                 std::size_t size,
                                 struct sockaddr_storage *saddr,
                                 socklen_t *len,
                                 std::int8_t flags = 0) const;

            std::size_t send(const char *buffer, std::size_t size, std::int8_t flags = 0) const;
            std::size_t sendmsg(const struct msghdr &msg, std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr *saddr,
                               socklen_t len,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_un &saddr,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_in &saddr,
                               std::int8_t flags = 0) const;
            std::size_t sendto(const char *buffer,
                               std::size_t size,
                               const struct sockaddr_in6 &saddr,
                               std::int8_t flags = 0) const;

            void shutdown(std::int8_t mode = SHUT_RDWR) const;

            bool sockatmark() const;

            void getsockopt(int level, int name, char *val, socklen_t *len) const;
            int getsockopt(int level, int name) const;

            void setsockopt(int level, int name, const char *val, socklen_t len) const;
            void setsockopt(int level, int name, int val) const;

            void getsockname(struct sockaddr *saddr, socklen_t *len) const;
            void getsockname(struct sockaddr_storage *saddr, socklen_t *len) const;

            void getpeername(struct sockaddr *saddr, socklen_t *len) const;
            void getpeername(struct sockaddr_storage *saddr, socklen_t *len) const;

            void tlsInitialize(GnuTLSType tlsType,  unsigned size = 1024,
                               const std::string &cert = "",
                               const std::string &key = "",
                               const std::string &trust = "",
                               const std::string &crlfile = "");

        private:

            /*
             * Prevent copying of <B> Socket </B> objects, since the
             *  effect of such copying is not well defined.
             */
            explicit Socket(std::int32_t fd);
            Socket(const Socket&) = default;
            Socket& operator=(const Socket&) = default;
            void  enableTLS();
            gnutls_session                 m_tlsSession;
            gnutls_certificate_credentials m_x509Credential;
            std::uint32_t                  m_nbbits;
            bool                           m_tls;
            static const int INVALID_SOCKET = -1;
            static const int SOCKET_ERROR = -1;
    };
    Socket& operator<<(Socket& socket, const std::string& data);
    Socket& operator>>(Socket& socket, std::string & data);
}
#endif

