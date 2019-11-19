

#ifndef CFS_OSAL_BINARYWRITER_HPP
#define CFS_OSAL_BINARYWRITER_HPP

#include <memory>
#include <string>
#include <sstream>
#include <cfs/osal/Writer.hpp>
#include <cfs/osal/Serializable.hpp>

namespace cfs::osal
{
    template<class T>
    class BinaryWriter : public Writer
        , public std::ostringstream
    {
        public:

            BinaryWriter();
            BinaryWriter(const BinaryWriter&);
            BinaryWriter(BinaryWriter&&) = default;
            BinaryWriter& operator=(const BinaryWriter&) = delete;
            BinaryWriter& operator=(BinaryWriter&&) = default;
            virtual ~BinaryWriter();

            virtual void commit(std::int8_t value) override;
            virtual void commit(std::int16_t value) override;
            virtual void commit(std::int32_t value) override;
            virtual void commit(std::int64_t value) override;
            virtual void commit(std::uint8_t value) override;
            virtual void commit(std::uint16_t value) override;
            virtual void commit(std::uint32_t value) override;
            virtual void commit(std::uint64_t value) override;
            virtual void commit(bool value) override;
            virtual void commit(float value) override;
            virtual void commit(double value) override;
            virtual void commit(const char * value) override;
            virtual void commit(const std::string & value) override;
            virtual void commit(const char * value, std::uint64_t size) override;
            virtual void commit(const Buffer & value) override;
            virtual void commit(const void * value, std::uint64_t size) override;
            virtual void commit(const void *& value, std::uint64_t size) override;

            BinaryWriter & operator>>(Serializable & data);
            BinaryWriter & operator>>(void *& data);

            template<typename Ts>
            BinaryWriter & serialize(const Ts & data)
            {
                write(reinterpret_cast<const char *>(&data), sizeof(data));

                return (*this);
            }

        protected:

            BinaryWriter(std::unique_ptr<T> & stream)
                : m_stream(stream)
            {
            }

        private:

            std::unique_ptr<T> m_stream;
    };
}
#endif

