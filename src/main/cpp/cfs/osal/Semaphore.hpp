

#ifndef CFS_OSAL_SEMAPHORE_HPP
#define CFS_OSAL_SEMAPHORE_HPP

#include <semaphore.h>

namespace cfs::osal
{
    class Semaphore
    {
        public:

            Semaphore();
            virtual ~Semaphore();
            void post(); /*!< Increases the semaphore by 1 */

            /*!

               @brief Trys to get the semaphore, blocking

                Takes the semaphore by decreasing the counter by 1, will wait for the semaphore
                to be given if the counter = 0.

             */
            void wait();

            /*!
               \brief Trys to get the semaphore, non-blocking

               Takes the semaphore by decreasing the counter by 1, will return if the counter = 0.

               \return bool false if semaphore was empty, true if semaphore was successfully acquired
             */
            bool tryWait();

        private:

            sem_t m_Sem;

            Semaphore(const Semaphore& arg);
            Semaphore& operator=(const Semaphore& rhs);
    };
}

#endif

