

#include <cfs/osal/cpumanager/Topology.hpp>

using namespace cfs::osal::cpumanager;

Topology::Topology()
: m_processors()
{

}

Topology::~Topology()
{
     delete m_processors;
}

Topology::ProcessorList const & Topology::processors () const
{
    return *this->m_processors;
}

