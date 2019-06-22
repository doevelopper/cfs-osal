

#ifndef CFS_OSAL_BINARYWRITER_HPP
#define CFS_OSAL_BINARYWRITER_HPP

namespace cfs::osal
{
    class BinaryWriter
    {
        public:

            BinaryWriter(const BinaryWriter&) = default;
            BinaryWriter(BinaryWriter&&) = default;
            BinaryWriter& operator=(const BinaryWriter&) = default;
            BinaryWriter& operator=(BinaryWriter&&) = default;
            virtual ~BinaryWriter() = default;
    };
}
#endif

