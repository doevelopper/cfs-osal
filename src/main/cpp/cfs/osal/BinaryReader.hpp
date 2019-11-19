

#ifndef CFS_OSAL_BINARYREADER_HPP
#define CFS_OSAL_BINARYREADER_HPP

#include <memory>
#include <string>
#include <sstream>
#include <cfs/osal/Reader.hpp>
#include <cfs/osal/Serializable.hpp>

namespace cfs::osal
{
    template<class T>
    class BinaryReader : public Reader
        , public std::istringstream
    {
        public:

            BinaryReader();
            BinaryReader(const BinaryReader&);
            BinaryReader(BinaryReader&&) = default;
            BinaryReader& operator=(const BinaryReader&) = delete;
            BinaryReader& operator=(BinaryReader&&) = default;
            virtual ~BinaryReader();

            virtual void gather(std::int8_t & value) override;
            virtual void gather(std::int16_t & value) override;
            virtual void gather(std::int32_t & value) override;
            virtual void gather(std::int64_t & value) override;
            virtual void gather(std::uint8_t & value) override;
            virtual void gather(std::uint16_t & value) override;
            virtual void gather(std::uint32_t & value) override;
            virtual void gather(std::uint64_t & value) override;
            virtual void gather(bool & value) override;
            virtual void gather(float & value) override;
            virtual void gather(double & value) override;
            virtual void gather(const char * value) override;
            virtual void gather(std::string& value) override;
            virtual void gather(char* value, std::size_t& size) override;
            virtual void gather(Buffer& value) override;
            virtual void gather(void* value, std::size_t& size) override;
            virtual void gather(void*& value, std::size_t& size) override;

            BinaryReader & operator<<(const Serializable & data);
            BinaryReader & operator<<(void * data);

            template<typename Ts>
            BinaryReader & serialize(Ts & data)
            {
                read(reinterpret_cast<char *>(&data), sizeof(data));

                return (*this);
            }

        protected:

            BinaryReader(std::unique_ptr<T> & stream)
                : m_stream(stream)
            {
            }

        private:

            std::unique_ptr<T> m_stream;
    };
}
#endif

