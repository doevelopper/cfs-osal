

#ifndef CFS_OSAL_BINARYWRITER_HPP
#define CFS_OSAL_BINARYWRITER_HPP

#include <memory>
#include <string>
#include <cfs/osal/Writer.hpp>

namespace cfs::osal
{
    template<class TStream>
    class BinaryWriter : public Writer
    {
        public:

            BinaryWriter() = delete;
            BinaryWriter(const BinaryWriter&) = delete;
            BinaryWriter(BinaryWriter&&) = default;
            BinaryWriter& operator=(const BinaryWriter&) = delete;
            BinaryWriter& operator=(BinaryWriter&&) = default;
            virtual ~BinaryWriter() = default;

            virtual void commit(const char* name, std::uint8_t value) override;
            virtual void commit(const char* name, std::int16_t value) override;
            virtual void commit(const char* name, std::int32_t value) override;
            virtual void commit(const char* name, std::int64_t value) override;
            virtual void commit(const char* name, std::uint16_t value) override;
            virtual void commit(const char* name, std::uint32_t value) override;
            virtual void commit(const char* name, std::uint64_t value) override;
            virtual void commit(const char* name, bool value) override;
            virtual void commit(const char* name, float value) override;
            virtual void commit(const char* name, double value) override;
            virtual void commit(const char* name, const char* value) override;
            virtual void commit(const char* name, const std::string& value) override;
            virtual void commit(const char* name, const char* value, std::uint64_t size) override;
            virtual void commit(const char* name, const Buffer& value) override;
            virtual void commit(const char* name, const void* value, std::uint64_t size) override;

        protected:

            BinaryWriter(std::auto_ptr<TStream> & stream)
                : m_stream(stream)
            {
            }

        private:

            std::auto_ptr<TStream> m_stream;
    };
}
#endif

