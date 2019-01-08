

#ifndef CFS_OSAL_SEMAPHORE_HPP
#define CFS_OSAL_SEMAPHORE_HPP

#include <cstdint>
#include <semaphore.h>

namespace cfs::osal
{
    class Semaphore
    {
        public:

            Semaphore(std::int32_t pshared = 0, std::uint32_t value = 0);
            virtual ~Semaphore();

            /*!
             * @brief The semaphore referenced by sem is unlocked, the value of the semaphore is incremented, and all
             *        threads which are waiting on the semaphore are awakened.
             * @return 0 if successful, Otherwise, -1 is returned and errno is set
             */
            void post(); /*!< Increases the semaphore by 1 */

            /*!
             * @brief Trys to get the semaphore, blocking
             *        Takes the semaphore by decreasing the counter by 1, will wait for the semaphore
             *        to be given if the counter = 0.
             *  @return If successful (the lock was acquired), wait() and trywait() will return 0.  Otherwise, -1 is
             *            returned and errno is set, and the state
             *  of the semaphore is unchanged.
             */
            void wait();

            /*!
             *  @brief Trys to get the semaphore, non-blocking
             *         Takes the semaphore by decreasing the counter by 1, will return if the counter = 0.
             *  @return bool false if semaphore was empty, true if semaphore was successfully acquired
             */
            bool tryWait();

        private:

            sem_t m_Sem;

            Semaphore(const Semaphore& arg);
            Semaphore& operator=(const Semaphore& rhs);
    };
}

#endif

