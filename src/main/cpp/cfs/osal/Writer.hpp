

#ifndef CFS_OSAL_WRITER_HPP
#define CFS_OSAL_WRITER_HPP

namespace cfs::osal
{
    class Writer
    {
        public:

            Writer(const Writer&) = default;
            Writer(Writer&&) = default;
            Writer& operator=(const Writer&) = default;
            Writer& operator=(Writer&&) = default;
            virtual ~Writer() = default;
            virtual void Write(const char* name, std::uint8_t value) = 0;
            virtual void Write(const char* name, std::int16_t value) = 0;
            virtual void Write(const char* name, std::int32_t value) = 0;
            virtual void Write(const char* name, std::int64_t value) = 0;
            virtual void Write(const char* name, std::uint16_t value) = 0;
            virtual void Write(const char* name, std::uint32_t value) = 0;
            virtual void Write(const char* name, std::uint64_t value) = 0;
            virtual void Write(const char* name, bool value) = 0;
            virtual void Write(const char* name, float value) = 0;
            virtual void Write(const char* name, double value) = 0;
            virtual void Write(const char* name, const char* value) = 0;
            virtual void Write(const char* name, const std::string& value) = 0;
            virtual void Write(const char* name, const char* value, std::uint64_t size) = 0;
            virtual void Write(const char* name, const Buffer& value) = 0;
            virtual void Write(const char* name, const void* value, std::uint64_t size) = 0;
    };
}
#endif

