

#ifndef CFS_OSAL_NETWORK_CAN_CAN_HPP
#define CFS_OSAL_NETWORK_CAN_CAN_HPP

#include <cstddef>
#include <cstdint>
#include <linux/types.h>
#include <linux/socket.h>
/* controller area network (CAN) kernel definitions */

/* special address description flags for the CAN_ID */
#define CAN_EFF_FLAG 0x80000000U /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000U /* remote transmission request */
#define CAN_ERR_FLAG 0x20000000U /* error message frame */

/* valid bits in CAN ID for frame formats */
#define CAN_SFF_MASK 0x000007FFU /* standard frame format (SFF) */
#define CAN_EFF_MASK 0x1FFFFFFFU /* extended frame format (EFF) */
#define CAN_ERR_MASK 0x1FFFFFFFU /* omit EFF, RTR, ERR flags */

/*
 * Controller Area Network Identifier structure
 *
 * bit 0-28 : CAN identifier (11/29 bit)
 * bit 29   : error message frame flag (0 = data frame, 1 = error message)
 * bit 30   : remote transmission request flag (1 = rtr frame)
 * bit 31   : frame format flag (0 = standard 11 bit, 1 = extended 29 bit)
 */

#define CAN_SFF_ID_BITS     11
#define CAN_EFF_ID_BITS     29

namespace cfs::osal::network::can
{
    using canID = std::uint32_t;

    class CAN
    {
        public:

            struct CanFrame
            {
                std::uint32_t id = 0;
                std::uint8_t len = 0;
                std::uint8_t flags = 0;
                std::uint8_t data[64];
            };

            CAN() = default;
            CAN(const CAN&) = default;
            CAN(CAN&&) = default;
            CAN& operator=(const CAN&) = default;
            CAN& operator=(CAN&&) = default;
            virtual ~CAN() = default;
    };
}
#endif

