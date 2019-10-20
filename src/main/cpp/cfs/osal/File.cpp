

#include <cfs/osal/File.hpp>

using namespace cfs::osal;

File::File(const char* fileName, Mode mode)
    : m_fileName(fileName)
    , m_mode(mode)
    , m_fileStream(fileName, static_cast<std::ios_base::openmode>(mode) | std::ios_base::binary)
{
    if(!m_fileStream.good())
    {
        throw Exception("Failed to open file: " + m_fileName
                        + ", " + strerror(errno));
    }
}

void File::close()
{
    if (m_fileStream.is_open())
    {
        m_fileStream.close();
    }
}

