

#ifndef CFS_OSAL_MAPPEDMEMORY_HPP
#define CFS_OSAL_MAPPEDMEMORY_HPP

#include <sys/mman.h>

#include <cfs/osal/FileDescriptor.hpp>

namespace cfs::osal
{
    class MappedMemory
    {
        public:

            MappedMemory() = default;
            MappedMemory(const MappedMemory&) = delete;
            MappedMemory(MappedMemory&&);
            MappedMemory& operator=(const MappedMemory&) = delete;
            MappedMemory& operator=(MappedMemory&&);
            virtual ~MappedMemory();

            MappedMemory(std::size_t len, std::int32_t prot, std::int32_t flags, std::int32_t fd, off_t off = 0);
            MappedMemory(void *addr, std::size_t len, std::int32_t prot, std::int32_t flags, std::int32_t fd, off_t
                         off = 0);

            char &operator[](std::size_t i);
            const char &operator[](std::size_t i) const;
            char *operator+(std::size_t i);
            const char *operator+(std::size_t i) const;
            operator char *();
            operator const char *() const;
            std::size_t size() const;

        private:

            char *      m_address;
            std::size_t m_size;
    };
}
#endif

