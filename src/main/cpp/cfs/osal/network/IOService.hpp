

#ifndef CFS_OSAL_NETWORK_IOSERVICE_HPP
#define CFS_OSAL_NETWORK_IOSERVICE_HPP

namespace cfs::osal::network
{
    class IOService
    {
        public:

            IOService() = default;
            IOService(const IOService&) = delete;
            IOService(IOService&&) = delete;
            IOService& operator=(const IOService&) = delete;
            IOService& operator=(IOService&&) = delete;
            virtual ~IOService() = default;

            virtual void open() = 0;
            virtual void close() = 0;
            virtual void transmit() = 0;
            virtual void receive() = 0;

        protected:

        private:
    };
}
#endif

