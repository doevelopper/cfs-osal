

#ifndef CFS_OSAL_BINARYREADER_HPP
#define CFS_OSAL_BINARYREADER_HPP

#include <memory>
#include <string>
#include <cfs/osal/Reader.hpp>

namespace cfs::osal
{
    template<class TStream>
    class BinaryReader : public Reader
    {
        public:

            BinaryReader(const BinaryReader&) = delete;
            BinaryReader(BinaryReader&&) = default;
            BinaryReader& operator=(const BinaryReader&) = delete;
            BinaryReader& operator=(BinaryReader&&) = default;
            virtual ~BinaryReader() = default;

            virtual void read(const char* name, std::uint8_t value) override;
            virtual void read(const char* name, std::int16_t value) override;
            virtual void read(const char* name, std::int32_t value) override;
            virtual void read(const char* name, std::int64_t value) override;
            virtual void read(const char* name, std::uint16_t value) override;
            virtual void read(const char* name, std::uint32_t value) override;
            virtual void read(const char* name, std::uint64_t value) override;
            virtual void read(const char* name, bool value) override;
            virtual void read(const char* name, float value) override;
            virtual void read(const char* name, double value) override;
            virtual void read(const char* name, const char* value) override;
            virtual void read(const char* name, const std::string& value) override;
            virtual void read(const char* name, const char* value, std::uint64_t size) override;
            virtual void read(const char* name, const Buffer& value) override;
            virtual void read(const char* name, const void* value, std::uint64_t size) override;

        protected:
            BinaryReader(std::auto_ptr<TStream> & stream)
            : m_stream(stream)
            {
            }
        private:
            std::auto_ptr<TStream> m_stream;
    };
}
#endif

