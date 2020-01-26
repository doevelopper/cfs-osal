

#ifndef CFS_OSAL_SPINLOCK_HPP
#define CFS_OSAL_SPINLOCK_HPP

#include <atomic>       // std::atomic_flag, std::memory_order_{acquire,release}
#include <chrono>       // std::chrono::duration
#include <thread>       // std::this_thread::yield
#include <type_traits>  // std::common_type

namespace cfs::osal
{
    template <typename WaitDurationType, typename WaitDurationType::rep delay>
    class SpinLock final
    {
        public:

            using DurationType = typename std::common_type <WaitDurationType, std::chrono::nanoseconds>::type;

            SpinLock(void)
                : m_atomicLock(false)
            {
                return;
            }

            SpinLock(SpinLock const &) = delete;
            SpinLock(SpinLock &&) = delete;
            SpinLock &operator=(SpinLock const &) = delete;
            SpinLock &operator=(SpinLock &&) = delete;
            ~SpinLock(void) noexcept = default;

            void lock(void)
            {
                while (m_atomicLock.exchange(true));
            }

            void unlock(void)
            {
                m_atomicLock = false;
            }

            void unlock (void) & noexcept
            {
                m_lockFlag.clear (std::memory_order_release);
            }

            void lock (DurationType duration = defaultDelay) & noexcept
            {
                while (true)
                {
                    auto const start {std::chrono::steady_clock::now ()};
                    while (m_lockFlag.test_and_set (std::memory_order_acquire))
                    {
                        auto const now {std::chrono::steady_clock::now ()};
                        auto const elapsed {std::chrono::duration_cast <duration_type> (now - start)};

                        if (elapsed >= delay)
                        {
                            std::this_thread::yield ();
                        }
                    }

                    return;
                }
            }

            bool try_lock (void) & noexcept
            {
                return (!m_lockFlag.test_and_set (std::memory_order_acquire));
            }

            bool isLocked(void) const
            {
                return m_atomicLock;
            }

        private:

            std::atomic_bool              m_atomicLock;
            std::atomic_flag              m_lockFlag = ATOMIC_FLAG_INIT;
            static constexpr DurationType defaultDelay
            {
                std::chrono::duration_cast <DurationType> (WaitDurationType {delay})
            };
    };
}

#endif

