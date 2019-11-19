

#include <cfs/osal/BinaryWriter.hpp>

using namespace cfs::osal;

template <typename T>
BinaryWriter<T>::BinaryWriter()
    : std::ostringstream()
{
}

template <typename T>
BinaryWriter<T>::BinaryWriter(const BinaryWriter & rhs)
    : std::ostringstream(rhs.str())
{
}

template <typename T>
BinaryWriter<T>::~BinaryWriter()
{
    str("");
    clear();
}

template <typename T>
void BinaryWriter<T>::commit(std::int8_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::int16_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::int32_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::int64_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::uint8_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::uint16_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::uint32_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(std::uint64_t value)
{
}

template <typename T>
void BinaryWriter<T>::commit(bool value)
{
}

template <typename T>
void BinaryWriter<T>::commit(float value)
{
}

template <typename T>
void BinaryWriter<T>::commit(double value)
{
}

template <typename T>
void BinaryWriter<T>::commit(const char * value)
{
}

template <typename T>
void BinaryWriter<T>::commit(const std::string & value)
{
}

template <typename T>
void BinaryWriter<T>::commit(const char * value, std::uint64_t size)
{
}

template <typename T>
void BinaryWriter<T>::commit(const Buffer & value)
{
}

template <typename T>
void BinaryWriter<T>::commit(const void * value, std::uint64_t size)
{
}

template <typename T>
void BinaryWriter<T>::commit(const void *& value, std::uint64_t size)
{
}

