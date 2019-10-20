

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
            NORMAL,
            INPUT  = std::ios_base::in,
            OUTPUT = std::ios_base::out
        };

        public:

            File() = default;
            File(const File&) = default;
            File(File&&) = default;
            File& operator=(const File&) = default;
            File& operator=(File&&) = default;
            virtual ~File() = default;
            File(const char* fileName, Mode mode);


            void open(const std::ios_base::openmode inputOutputMode);

            unsigned int read()
            {
                std::uint8_t value = 0;
                readBytes(&value, 1);

                return(value);
            }

            void readBytes(void* buf, size_t size)
            {
                if(m_mode == INPUT)
                {
                    m_fileStream.read(static_cast<char*>(buf), size);

                    if(m_fileStream.eof())
                    {
                        throw ("Failed to read file: " + m_fileName + ", read past the end of file.");
                    }

                    if(!m_fileStream.good())
                    {
                        throw ("Failed to read file: " + m_fileName + ", " + strerror(errno));
                    }
                }
            }

            unsigned int write();
            void close();

        protected:

        private:

            std::fstream            m_fileStream;
            std::ios_base::openmode m_ioMode;
            const std::string       m_fileName;
            Mode                    m_mode;
    }
}

#endif

