

#ifndef CFS_OSAL_CHARACTERDEVICE_HPP
#define CFS_OSAL_CHARACTERDEVICE_HPP

#include <string>
#include <chrono>
#include <ostream>
#include <sys/stat.h>
#include <fcntl.h>

#include <cfs/osal/FileDescriptor.hpp>

namespace cfs::osal
{
    class CharacterDevice
    {
        enum class Access : std::uint8_t
        {
            ReadOnly,
            WriteOnly,
            ReadWrite
        };

        public:

            CharacterDevice();
            CharacterDevice(const std::string& path, Access access);
            CharacterDevice(const CharacterDevice& orig) = default;
            CharacterDevice(CharacterDevice&& orig) = default;
            CharacterDevice & operator=(const CharacterDevice& orig) = default;
            CharacterDevice & operator=(CharacterDevice && orig) = default;
            virtual ~CharacterDevice();

            bool poll(std::chrono::milliseconds timeout) const;
            void flush() const;
            unsigned int input() const;
            unsigned int output() const;

        protected:

        private:

            FileDescriptor * m_fileDescriptor;
    };
}
#endif

