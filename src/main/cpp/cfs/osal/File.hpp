

#ifndef CFS_OSAL_FILE_HPP
#define CFS_OSAL_FILE_HPP

#include <fstream>
#include <string>
#include <optional>

namespace cfs::osal
{
    class File
    {
        enum Mode
        {
            BINARY,
            NORMAL
        };

        public:

            void open(const std::ios_base::openmode inputOutputMode);
            unsigned int read();
            unsigned int write();
            void close();

        protected:

        private:

            std::fstream            m_fileStream;
            std::ios_base::openmode m_ioMode;
            std::string             m_fileName;
    }
}

#endif

