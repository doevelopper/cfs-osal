

#ifndef CFS_OSAL_WRITER_HPP
#define CFS_OSAL_WRITER_HPP

#include <cstdint>
#include <vector>

namespace cfs::osal
{
    class Writer
    {
        public:

            using Buffer = std::vector<std::uint8_t>;

            Writer() = default;
            Writer(const Writer&) = default;
            Writer(Writer&&) = default;
            Writer& operator=(const Writer&) = default;
            Writer& operator=(Writer&&) = default;
            virtual ~Writer() = default;
            virtual void commit(std::int8_t value) = 0;
            virtual void commit(std::int16_t value) = 0;
            virtual void commit(std::int32_t value) = 0;
            virtual void commit(std::int64_t value) = 0;
            virtual void commit(std::uint8_t value) = 0;
            virtual void commit(std::uint16_t value) = 0;
            virtual void commit(std::uint32_t value) = 0;
            virtual void commit(std::uint64_t value) = 0;
            virtual void commit(bool value) = 0;
            virtual void commit(float value) = 0;
            virtual void commit(double value) = 0;
            virtual void commit(const char * value) = 0;
            virtual void commit(const std::string & value) = 0;
            virtual void commit(const char * value, std::uint64_t size) = 0;
            virtual void commit(const Buffer & value) = 0;
            virtual void commit(const void * value, std::uint64_t size) = 0;
            virtual void commit(const void *& value, std::uint64_t size) = 0;

        protected:

        private:
    };
}
#endif

