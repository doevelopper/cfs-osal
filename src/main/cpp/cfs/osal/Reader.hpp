

#ifndef CFs_OSAL_READER_HPP
#define CFs_OSAL_READER_HPP

namespace cfs::osal
{
    class Reader
    {
        public:

            Reader(const Reader&) = default;
            Reader(Reader&&) = default;
            Reader& operator=(const Reader&) = default;
            Reader& operator=(Reader&&) = default;
            virtual ~Reader() = default;
            virtual void Read(const char* name, std::uint8_t& value) = 0;
            virtual void Read(const char* name, std::int16_t& value) = 0;
            virtual void Read(const char* name, std::int32_t& value) = 0;
            virtual void Read(const char* name, std::int64_t& value) = 0;
            virtual void Read(const char* name, std::uint16_t& value) = 0;
            virtual void Read(const char* name, std::uint32_t& value) = 0;
            virtual void Read(const char* name, std::uint64_t& value) = 0;
            virtual void Read(const char* name, bool& value) = 0;
            virtual void Read(const char* name, float& value) = 0;
            virtual void Read(const char* name, double& value) = 0;
            virtual void Read(const char* name, std::string& value) = 0;
            virtual void Read(const char* name, char* value, size_t& size) = 0;
            virtual void Read(const char* name, Buffer& value) = 0;
            virtual void Read(const char* name, void* value, size_t& size) = 0;

        protected:

        private:
    };
}
#endif

