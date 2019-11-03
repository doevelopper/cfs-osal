

#ifndef CFs_OSAL_READER_HPP
#define CFs_OSAL_READER_HPP

#include <cstdint>
#include <vector>

namespace cfs::osal
{
    class Reader
    {
        public:

            using Buffer = std::vector<std::uint8_t>;

            Reader() = default;
            Reader(const Reader&) = default;
            Reader(Reader&&) = default;
            Reader& operator=(const Reader&) = default;
            Reader& operator=(Reader&&) = default;
            virtual ~Reader() = default;
            virtual void gather(const char* name, std::int8_t& value) = 0;
            virtual void gather(const char* name, std::int16_t& value) = 0;
            virtual void gather(const char* name, std::int32_t& value) = 0;
            virtual void gather(const char* name, std::int64_t& value) = 0;
            virtual void gather(const char* name, std::uint8_t& value) = 0;
            virtual void gather(const char* name, std::uint16_t& value) = 0;
            virtual void gather(const char* name, std::uint32_t& value) = 0;
            virtual void gather(const char* name, std::uint64_t& value) = 0;
            virtual void gather(const char* name, bool& value) = 0;
            virtual void gather(const char* name, float& value) = 0;
            virtual void gather(const char* name, double& value) = 0;
            virtual void gather(const char* name, std::string& value) = 0;
            virtual void gather(const char* name, char* value, std::size_t& size) = 0;
            virtual void gather(const char* name, Buffer& value) = 0;
            virtual void gather(const char* name, void* value, std::size_t& size) = 0;

        protected:

        private:
    };
}
#endif

