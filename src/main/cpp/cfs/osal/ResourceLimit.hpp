

#ifndef CFS_OSAL_RESOURCELIMIT_HPP
#define CFS_OSAL_RESOURCELIMIT_HPP

#include <sys/resource.h>

#define OS_SUCCESS  ( 0 )
#define OS_ERROR    ( -1 )

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
            ResourceLimit( int );
            ResourceLimit(int,rlim_t,rlim_t);
            ResourceLimit(int,rlimit & );

            rlim_t soft_limit () const noexcept;
            rlim_t hard_limit () const noexcept;

            const rlimit & to_rlimit () const;

            void limit ();
            void apply ();

            bool operator == ( const ResourceLimit & ) const;
            bool operator < ( const ResourceLimit & ) const;

        protected:

        private:

            int    m_resourceID;
            rlimit m_limit;
            bool   m_applied;
    };
}
#endif

