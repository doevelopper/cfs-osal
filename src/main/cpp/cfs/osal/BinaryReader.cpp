

#include <cfs/osal/BinaryReader.hpp>

using namespace cfs::osal;

template <typename T>
BinaryReader<T>::BinaryReader()
    : std::istringstream()
{
}

template <typename T>
BinaryReader<T>::BinaryReader(const BinaryReader & rhs)
    : std::istringstream(rhs.str())
{
}

template <typename T>
BinaryReader<T>::~BinaryReader()
{
    str("");
    clear();
}

template <typename T>
void BinaryReader<T>::gather(std::int8_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::int16_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::int32_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::int64_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::uint8_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::uint16_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::uint32_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::uint64_t& value)
{
}

template <typename T>
void BinaryReader<T>::gather(bool& value)
{
}

template <typename T>
void BinaryReader<T>::gather(float& value)
{
}

template <typename T>
void BinaryReader<T>::gather(double& value)
{
}

template <typename T>
void BinaryReader<T>::gather(std::string& value)
{
}

template <typename T>
void BinaryReader<T>::gather(char* value, std::size_t& size)
{
}

template <typename T>
void BinaryReader<T>::gather(Buffer& value)
{
}

template <typename T>
void BinaryReader<T>::gather(void* value, std::size_t& size)
{
}

template <typename T>
void BinaryReader<T>::gather(void*& value, std::size_t& size)
{
}

