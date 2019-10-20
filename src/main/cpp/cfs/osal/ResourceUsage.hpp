

#ifndef CFS_OSAL_RESOURCEUSAGE_HPP
#define CFS_OSAL_RESOURCEUSAGE_HPP

#include <cfs/osal/ResourceLimit.hpp>

namespace cfs::osal
{
    class ResourceUsage
    {
        public:

            ResourceUsage() = default;
            ResourceUsage( int );
            ResourceUsage(const ResourceUsage&) = default;
            ResourceUsage(ResourceUsage&&) = default;
            ResourceUsage& operator=(const ResourceUsage&) = default;
            ResourceUsage& operator=(ResourceUsage&&) = default;
            virtual ~ResourceUsage() = default;

            long maximumResidentSetSize () const;
            long sharingOfTextSegmentMemory () const;
            long dataSegmentMemoryUsed () const;
            long numberOfSoftPageFaults () const;
            long numberOfHardPageFaults () const;
            long timesAProcessWasSwapped () const;
            long numberOfInputOperationsViaTheFileSystem () const;
            long numberOfOutputOperationsViaTheFileSystem () const;
            long numberOfIPCMessagesSent () const;
            long numberOfIPCMessagesReceived () const;
            long numberOfSignalsDelivered () const;
            long numberOfVoluntaryContextSwitches () const;
            long numberOfInvoluntaryContextSwitches () const;
            long stackMemoryUsed () const;
            timeval amountOfUserTimeUsed () const;
            timeval amountOfSystemTimeUsed () const;

        private:

            int     m_appUser;
            timeval m_tv;
            rusage  m_rsrcUsage;
    };
}
#endif

