

#ifndef CFS_OSAL_BLOCKDEVICE_HPP
#define CFS_OSAL_BLOCKDEVICE_HPP

//#include <linux/blkdev.h>

namespace cfs::osal
{
    class BlockDevice
    {
        public:

            BlockDevice() = default;
            BlockDevice(const BlockDevice&) = default;
            BlockDevice(BlockDevice&&) = default;
            BlockDevice& operator=(const BlockDevice&) = default;
            BlockDevice& operator=(BlockDevice&&) = default;
            virtual ~BlockDevice() = default;

        protected:

        private:
    };
}
#endif

