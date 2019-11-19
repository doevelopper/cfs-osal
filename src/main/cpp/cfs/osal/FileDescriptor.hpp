

#ifndef CFS_OSAL_FILEDESCRIPTOR_HPP
#define CFS_OSAL_FILEDESCRIPTOR_HPP

#include <unistd.h>
#include <cstddef>
#include <cstdint>
#include <string>
#include <cfs/osal/CompilerDetection.hpp>
#include <cfs/osal/Export.hpp>

namespace cfs::osal
{
    class CFS_OSAL_MAIN_EXPORT FileDescriptor
    {
        int flag = 0;
        enum class Access : std::uint8_t
        {
            ReadOnly /*= (flag |= O_RDONLY)*/,
            WriteOnly /*= (flag |= O_WRONLY)*/,
            ReadWrite /*= (flag |= O_RDWR)*/,
            NO_DLAY_CTTY /*= (flag |= O_NOCTTY | O_NDELAY)*/
        };

        public:

            FileDescriptor() = delete;
            FileDescriptor(std::int32_t fd = -1) CFS_OSAL_NOEXCEPT;
            FileDescriptor(const FileDescriptor&) = delete;
            FileDescriptor(FileDescriptor&&);
            FileDescriptor& operator=(const FileDescriptor&) = delete;
            FileDescriptor& operator=(FileDescriptor&&);
            virtual ~FileDescriptor();

            inline operator int() const
            {
                return (m_fileDescriptor);
            }

            std::int32_t fileDescriptor()
            {
                return (m_fileDescriptor);
            }

            std::int32_t fileDescriptorOperations(std::int32_t command);
            std::int32_t fileDescriptorOperations(std::int32_t command, std::uint8_t arguments);
            std::int32_t fileDescriptorOperations(std::int32_t command, struct flock * fileLocking);
            std::size_t read(const std::string & buffer) const;
            std::size_t read(char *buffer, std::size_t size) const;
            std::size_t write(const std::string & buffer) const;
            std::size_t write(const char *buffer, std::size_t size) const;
            std::size_t pread(char *buffer, std::size_t size, std::size_t off) const;
            std::size_t pwrite(const char *buffer, std::size_t size, std::size_t off) const;
            bool isInUse() const;
            void close() CFS_OSAL_NOEXCEPT;

        private:

            std::int32_t m_fileDescriptor;
    };
}
#endif

