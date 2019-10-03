

#ifndef CFS_OSAL_NETWORK_I2C_HPP
#define CFS_OSAL_NETWORK_I2C_HPP

#include <cstdint>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

namespace cfs::osal::network::i2c
{
    /*!
     * @defgroup I2c I2c device interface
     * @brief Functions to control an I2C device.
     *        These functions can be used to control GPIO.
     * @{
     */
    class I2c
    {
        public:

            struct I2cDevice
            {
                int bus;                    /* I2C Bus fd, return from i2c_open */
                unsigned short addr;        /* I2C device(slave) address */
                unsigned char tenbit;       /* I2C is 10 bit device address */
                unsigned char delay;        /* I2C internal operate delay, unit millisecond */
                unsigned short flags;       /* I2C i2c_ioctl_read/write flags */
                unsigned int page_bytes;    /* I2C max number of bytes per page, 1K/2K 8, 4K/8K/16K 16, 32K/64K 32 etc
                                             */
                unsigned int iaddr_bytes;   /* I2C device internal(word) address bytes, such as: 24C04 1 byte, 24C64 2
                                               bytes */
            };

            I2c();
            I2c(const I2c& orig) = default;
            I2c(I2c&& orig) = default;
            I2c & operator=(const I2c& orig) = default;
            I2c & operator=(I2c && orig) = default;
            virtual ~I2c();
            /*!
             * @brief Reads from the device.
             * @param[out] data Output buffer to write the data to.
             * @param[in] len Number of bytes to read.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t read(const I2cDevice* device, void* data, std::int32_t len);
            /*!
             * @brief Reads a byte from an I2C register.
             * @param[in] reg Register to read from.
             * @param[in] val Output pointer to value to read.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t readRegisterByte(const I2cDevice * device,  std::uint8_t reg, std::uint8_t * val);
            /*!
             * @brief  Reads a word from an I2C register.
             * @param[in] reg Register to read from.
             * @param[in] val Output pointer to value to read.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t readRegisterWord(const I2cDevice* device, std::uint8_t reg, std::uint16_t * val);
            /*!
             * @brief Reads from an I2C register.
             * @param[in] reg Register to read from.
             * @param[out] data Output buffer to write the data to.
             * @param[in] len Number of bytes to read.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t readRegisterBuffer(const I2cDevice* device, std::uint8_t reg, void* data, std::uint32_t len);
            /*!
             * @brief Writes to the device.
             * @param[in] reg Register to read from.
             * @param[out] data Buffer to write.
             * @param[in] len Number of bytes to write.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t write(const I2cDevice* device, std::uint8_t reg, void* data, std::uint32_t len);
            /*!
             * @brief Writes a byte to an I2C register.
             * @param[in] reg Register to write to.
             * @param[in]  val Value to write.
             * @param[out] device
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::int8_t writeRegisterByte(const I2cDevice* device, std::uint8_t reg, std::uint8_t val);
            /*!
             * @brief Writes a word to an I2C register.
             * @param[out] device
             * @param[in] reg Register to write to.
             * @param[in] val Value to write.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::uint8_t writeRegisterWord(const I2cDevice* device, std::uint8_t reg, std::uint16_t val);
            /*!
             * @brief Writes to an I2C register.
             * @param[out] device Pointer to the I2cDevice struct.
             * @param[in] reg Register to write to.
             * @param[out] data Data to write.
             * @param[in] len Number of bytes to write.
             * @retval  0: Success
             * @retval  n: errno Error
             */
            std::uint8_t writeRegBuffer(const I2cDevice* device, std::uint8_t reg, const void* data, std::uint32_t len);

        private:
    };
    /*!
     * @}
     */
}
#endif

