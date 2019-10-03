

#ifndef CFS_OSAL_IOMANAGER_HPP
#define CFS_OSAL_IOMANAGER_HPP

namespace cfs::osal::network
{
    class IOManager
    {
        public:

            IOManager(const IOManager&) = default;
            IOManager(IOManager&&) = default;
            IOManager& operator=(const IOManager&) = default;
            IOManager& operator=(IOManager&&) = default;
            virtual ~IOManager() = default;

            void createNetworkService();
    };
}
#endif

