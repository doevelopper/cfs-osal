

#ifndef CFS_OSAL_NETWORK_RPI_RPIUART_HPP
#define CFS_OSAL_NETWORK_RPI_RPIUART_HPP

#include <cfs/osal/network/serial/Uart.hpp>
#include <cfs/osal/FileDescriptor.hpp>

namespace cfs::osal::network::rpi
{
    class RpiUART final : public cfs::osal::network::serial::Uart
        , public cfs::osal::FileDescriptor
    {
        public:

            RpiUART ();

            //RpiUART (const std::string & device, const SerialConfig & config);
            //            RpiUART (const Uart& orig) = delete;
            RpiUART (RpiUART&& orig) = delete;
            RpiUART & operator=(const RpiUART & orig) = delete;
            RpiUART & operator=(RpiUART && orig) = delete;
            virtual ~RpiUART();

            void setRts(int level);
            std::vector<std::uint8_t> receive(int size);
            void transmit(const std::vector<std::uint8_t> &buffer);
    };
    /*
        std::unique_ptr<::Uart> openSerialPort(const std::string& device, const SerialConfig& config)
        {
            return std::unique_ptr<Uart>(new RpiUART(device, config));
        }
     */
}
#endif

