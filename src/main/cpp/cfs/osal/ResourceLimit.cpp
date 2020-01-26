

#include <system_error>
#include <cerrno>
#include <cfs/osal/ResourceLimit.hpp>

using namespace cfs::osal;

ResourceLimit::ResourceLimit( std::int8_t resource_id )
    : m_resourceID( resource_id )
    , m_limit()
    , m_applied( false )
{
    if ( getrlimit( m_resourceID, &m_limit ) == OS_ERROR )
    {
        throw std::system_error(errno, std::system_category());
    }
    else
    {
    }
}

ResourceLimit::ResourceLimit( std::int8_t resource_id, rlim_t soft_limit,rlim_t hard_limit)
    : m_resourceID( resource_id )
    , m_limit()
    , m_applied( false )
{
    m_limit.rlim_cur = soft_limit;
    m_limit.rlim_max = hard_limit;
}

ResourceLimit::ResourceLimit(std::int8_t resource_id, rlimit & limit )
    : m_resourceID( resource_id )
    , m_limit( limit )
    ,m_applied( false )
{
}

rlim_t ResourceLimit::soft_limit () const noexcept
{
    return m_limit.rlim_cur;
}

rlim_t ResourceLimit::hard_limit () const noexcept
{
    return m_limit.rlim_max;
}

void ResourceLimit::limit ()
{
    if ( getrlimit( m_resourceID, &m_limit ) == OS_ERROR )
    {
        throw std::system_error(errno, std::system_category());
    }
}

void ResourceLimit::apply ()
{
    if ( setrlimit( m_resourceID, &m_limit ) == OS_ERROR )
    {
        throw std::system_error(errno, std::system_category());
    }

    m_applied = true;
}

bool ResourceLimit::operator == ( const ResourceLimit & other ) const
{
    return m_resourceID == other.m_resourceID;
}

bool ResourceLimit::operator < ( const ResourceLimit & other ) const
{
    return m_resourceID < other.m_resourceID;
}

