

#ifndef CFs_OSAL_READER_HPP
#define CFs_OSAL_READER_HPP

#include <cstdint>
#include <vector>
#include <string>

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
            virtual void gather(std::int8_t& value) = 0;
            virtual void gather(std::int16_t& value) = 0;
            virtual void gather(std::int32_t& value) = 0;
            virtual void gather(std::int64_t& value) = 0;
            virtual void gather(std::uint8_t& value) = 0;
            virtual void gather(std::uint16_t& value) = 0;
            virtual void gather(std::uint32_t& value) = 0;
            virtual void gather(std::uint64_t& value) = 0;
            virtual void gather(bool & value) = 0;
            virtual void gather(float & value) = 0;
            virtual void gather(double & value) = 0;
            virtual void gather(const char * value) = 0;
            virtual void gather(std::string & value) = 0;
            virtual void gather(char* value, std::size_t& size) = 0;
            virtual void gather(Buffer& value) = 0;
            virtual void gather(void* value, std::size_t& size) = 0;
            virtual void gather(void*& value, std::size_t& size) = 0;

        protected:

        private:
    };
}
#endif

