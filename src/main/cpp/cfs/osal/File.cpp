

#include <cfs/osal/File.hpp>

using namespace cfs::osal;


void File::close()
{
    if (m_fileStream.is_open())
    {
        m_fileStream.close();
    }
}

