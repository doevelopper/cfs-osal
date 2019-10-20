

#include <cfs/osal/ResourceUsage.hpp>

using namespace cfs::osal;

ResourceUsage::ResourceUsage( int app )
    : m_appUser( app )
{
    if ( getrusage( m_appUser, &m_rsrcUsage ))
    {
    }
}

long ResourceUsage::maximumResidentSetSize () const
{
    return m_rsrcUsage.ru_maxrss;
}

long ResourceUsage::sharingOfTextSegmentMemory () const
{
    return m_rsrcUsage.ru_ixrss;
}

long ResourceUsage::dataSegmentMemoryUsed () const
{
    return m_rsrcUsage.ru_idrss;
}

long ResourceUsage::numberOfSoftPageFaults () const
{
    return m_rsrcUsage.ru_minflt;
}

long ResourceUsage::numberOfHardPageFaults () const
{
    return m_rsrcUsage.ru_majflt;
}

long ResourceUsage::timesAProcessWasSwapped () const
{
    return m_rsrcUsage.ru_nswap;
}

long ResourceUsage::numberOfInputOperationsViaTheFileSystem () const
{
    return m_rsrcUsage.ru_inblock;
}

long ResourceUsage::numberOfOutputOperationsViaTheFileSystem () const
{
    return m_rsrcUsage.ru_oublock;
}

long ResourceUsage::numberOfIPCMessagesSent () const
{
    return m_rsrcUsage.ru_msgsnd;
}

long ResourceUsage::numberOfIPCMessagesReceived () const
{
    return m_rsrcUsage.ru_msgrcv;
}

long ResourceUsage::numberOfSignalsDelivered () const
{
    return m_rsrcUsage.ru_nsignals;
}

long ResourceUsage::numberOfVoluntaryContextSwitches () const
{
    return m_rsrcUsage.ru_nvcsw;
}

long ResourceUsage::numberOfInvoluntaryContextSwitches () const
{
    return ( m_rsrcUsage.ru_nivcsw );
}

long ResourceUsage::stackMemoryUsed () const
{
    return ( this->m_rsrcUsage.ru_isrss );
}

timeval ResourceUsage::amountOfSystemTimeUsed () const
{
    return ( this->m_rsrcUsage.ru_utime );
}

timeval ResourceUsage::amountOfUserTimeUsed () const
{
    return ( this->m_rsrcUsage.ru_stime );
}

