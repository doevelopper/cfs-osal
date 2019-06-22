

#ifndef CFS_OSAL_SPINLOCK_HPP
#define CFS_OSAL_SPINLOCK_HPP

#include <atomic>

namespace cfs::osal
{
    class SpinLock final
    {
        public:

            SpinLock(void)
                : m_atomicLock(false)
            {
                return;
            }

            SpinLock(SpinLock const &) = default;

            SpinLock(SpinLock &&) = default;

            SpinLock &operator=(SpinLock const &) = default;

            SpinLock &operator=(SpinLock &&) = default;

            ~SpinLock(void) = default;

            void lock(void)
            {
                while (m_atomicLock.exchange(true));
            }

            void unlock(void)
            {
                m_atomicLock = false;
            }

            bool isLocked(void) const
            {
                return m_atomicLock;
            }

        private:

            std::atomic_bool m_atomicLock;
    };
}

#endif

