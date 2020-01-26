

#ifndef CFS_OSAL_RESOURCELIMIT_HPP
#define CFS_OSAL_RESOURCELIMIT_HPP

#include <cstdint>
#include <sys/resource.h>

#define OS_SUCCESS  ( 0 )
#define OS_ERROR    ( -1 )

// https://www.gnu.org/software/libc/manual/html_node/Limits-on-Resources.html

namespace cfs::osal
{
    class ResourceLimit
    {
        public:

            ResourceLimit();
            ResourceLimit(const ResourceLimit&) = default;
            ResourceLimit(ResourceLimit&&) = default;
            ResourceLimit& operator=(const ResourceLimit&) = default;
            ResourceLimit& operator=(ResourceLimit&&) = default;
            virtual ~ResourceLimit() = default;
            ResourceLimit( std::int8_t );
            ResourceLimit( std::int8_t,rlim_t,rlim_t);
            ResourceLimit(std::int8_t,rlimit & );

            rlim_t soft_limit () const noexcept;
            rlim_t hard_limit () const noexcept;

            const rlimit & to_rlimit () const;

            void limit ();
            void apply ();

            bool operator == ( const ResourceLimit & ) const;
            bool operator < ( const ResourceLimit & ) const;

        protected:

        private:

            std::int8_t m_resourceID;
            rlimit      m_limit;
            bool        m_applied;
    };
}
#endif

/*
 * Example output:
 * RLIMIT_AS         :         -1 soft         -1 hard    //<! address space (resident set size)
 * RLIMIT_CORE       :          0 soft         -1 hard    //<! core file size
 * RLIMIT_CPU        :         -1 soft         -1 hard    //<! cpu time per process
 * RLIMIT_DATA       :         -1 soft         -1 hard    //<! data segment size
 * RLIMIT_FSIZE      :         -1 soft         -1 hard    //<! file size
 * RLIMIT_LOCKS      :         -1 soft         -1 hard    //<!
 * RLIMIT_MEMLOCK    :      65536 soft      65536 hard    //<! locked-in-memory address space
 * RLIMIT_MSGQUEUE   :     819200 soft     819200 hard
 * RLIMIT_NICE       :          0 soft          0 hard
 * RLIMIT_NOFILE     :       1024 soft       4096 hard    //<! number of open files
 * RLIMIT_NPROC      :      63003 soft      63003 hard    //<! number of processes
 * RLIM_NLIMITS                                           //<! total number of resource limits
 * RLIMIT_RSS        :         -1 soft         -1 hard    //<! source compatibility alias
 * RLIMIT_RTPRIO     :          0 soft          0 hard
 * RLIMIT_RTTIME     :         -1 soft         -1 hard
 * RLIMIT_SIGPENDING :      63003 soft      63003 hard
 * RLIMIT_STACK      :    8388608 soft         -1 hard
 */

