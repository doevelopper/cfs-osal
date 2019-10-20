

#include <cfs/osal/cpumanager/Topology.hpp>

using namespace cfs::osal::cpumanager;

Topology::ProcessorList const & Topology::processors () const
{
    return ( this->m_processors );
}

