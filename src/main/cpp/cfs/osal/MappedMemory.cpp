

#include <utility>

#include <cfs/osal/MappedMemory.hpp>

using namespace cfs::osal;

MappedMemory::MappedMemory(std::size_t len, std::int32_t prot, std::int32_t flags, std::int32_t fd, off_t off)
    : MappedMemory(nullptr, len, prot, flags, fd, off)
{
}

MappedMemory::MappedMemory(void *addr, size_t len, std::int32_t prot, std::int32_t flags, std::int32_t fd, off_t off)
    : m_address(static_cast<char *>(::mmap(addr, len, prot, flags, fd, off)))
    ,m_size(len)
{
    if (m_address == MAP_FAILED)
    {
        //handle erro
    }
}

MappedMemory::MappedMemory(MappedMemory &&other)
    : m_address(other.m_address)
    ,m_size(other.m_size)
{
    other.m_address = nullptr;
    other.m_size = 0;
}

MappedMemory::~MappedMemory()
{
    if (m_address)
        ::munmap(m_address, m_size);
}

MappedMemory &MappedMemory::operator=(MappedMemory &&other)
{
    std::swap(m_address, other.m_address);
    std::swap(m_size, other.m_size);

    return *this;
}

char &MappedMemory::operator[](size_t i)
{
    return m_address[i];
}

const char &MappedMemory::operator[](size_t i) const
{
    return m_address[i];
}

char *MappedMemory::operator+(size_t i)
{
    return m_address + i;
}

const char *MappedMemory::operator+(size_t i) const
{
    return m_address + i;
}

MappedMemory::operator char *()
{
    return m_address;
}

MappedMemory::operator const char *() const
{
    return m_address;
}

std::size_t MappedMemory::size() const
{
    return m_size;
}

