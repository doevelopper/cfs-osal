

#ifndef CFS_OSAL_WRITER_HPP
#define CFS_OSAL_WRITER_HPP
#include <cstdint>
#include <vector>

namespace cfs::osal
{
    class Writer
    {
        using Buffer = std::vector<std::uint8_t>;

        public:

            Writer() = default;
            Writer(const Writer&) = default;
            Writer(Writer&&) = default;
            Writer& operator=(const Writer&) = default;
            Writer& operator=(Writer&&) = default;
            virtual ~Writer() = default;
            virtual void commit(const char* name, std::int8_t value) = 0;
            virtual void commit(const char* name, std::int16_t value) = 0;
            virtual void commit(const char* name, std::int32_t value) = 0;
            virtual void commit(const char* name, std::int64_t value) = 0;
            virtual void commit(const char* name, std::uint8_t value) = 0;
            virtual void commit(const char* name, std::uint16_t value) = 0;
            virtual void commit(const char* name, std::uint32_t value) = 0;
            virtual void commit(const char* name, std::uint64_t value) = 0;
            virtual void commit(const char* name, bool value) = 0;
            virtual void commit(const char* name, float value) = 0;
            virtual void commit(const char* name, double value) = 0;
            virtual void commit(const char* name, const char* value) = 0;
            virtual void commit(const char* name, const std::string& value) = 0;
            virtual void commit(const char* name, const char* value, std::uint64_t size) = 0;
            virtual void commit(const char* name, const Buffer& value) = 0;
            virtual void commit(const char* name, const void* value, std::uint64_t size) = 0;
    };
}
#endif

