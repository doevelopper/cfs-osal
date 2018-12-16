

#ifndef CFS_OSAL_SPINLOCK_HPP
#define CFS_OSAL_SPINLOCK_HPP

#include <atomic>

namespace cfs::osal
{
    class SpinLock final
    {
        public:

            SpinLock(void)
                : atomicLock(false)
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
                while (atomicLock.exchange(true));
            }

            void unlock(void)
            {
                atomicLock = false;
            }

            bool isLocked(void) const
            {
                return atomicLock;
            }

        private:

            std::atomic_bool atomicLock;
    };
}

#endif

