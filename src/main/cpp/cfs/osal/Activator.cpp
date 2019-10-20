

#include <cfs/osal/Activator.hpp>

using namespace cfs::osal;

template < class T >
Activator < T >::Activator()
    : m_value( T())
    , m_isValid( false )
{
}

template < class T >
Activator < T >::~Activator()
{
}

template < class T >
void Activator < T >::value ( const T & value )
{
    this->m_value = value;
    this->m_isValid = true;
}

template < class T >
T Activator < T >::value () const
{
    return ( this->m_value );
}

template < class T >
const bool Activator < T >::isValid () const
{
    return ( this->m_isValid );
}

template < class T >
void Activator < T >::isValid ( bool value )
{
    this->m_isValid = value;
}

