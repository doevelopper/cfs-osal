

#ifndef CFS_OSAL_SEMAPHORE_HPP
#define CFS_OSAL_SEMAPHORE_HPP

#include <cstdint>
#include <semaphore.h>

namespace cfs::osal
{
    /*!
     *
     * @brief Class providing implementation of Posix semaphore (both named and unnamed)
     *
     */
    class Semaphore
    {
        enum OpenMode : std::int8_t
        {
            SEM_OPEN = 0,  /*!< Open an existing semaphore (default) */
            SEM_CREATE,    /*!< Create a new semaphore */
            SEM_EXCLUSIVE, /*!< Create a new semaphore in exclusive mode */
            SEM_OPEN_UNKN
        };

        public:

            Semaphore(const Semaphore& arg) = delete;
            Semaphore& operator=(const Semaphore& rhs) = delete;
            /*!
             * @brief Open or create a named semaphore
             * @param [in, out] name Name of Semaphore for a named semaphore
             * @param [in] flag
             * @param [in] mode
             * @param [in] value
             */
            Semaphore(std::string & name,OpenMode flag = SEM_OPEN, std::uint32_t mode = 0666,std::uint32_t value = -1);
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
            /*! @brief It'll be locked when  constructed and released when
             *         goes out of scope.
             *
             */
            class Autolock
            {
                public:

                    Autolock( Semaphore & mutex)
                        : m_mtx(mutex)
                    {
                        m_mtx.wait();
                    }

                    Autolock( Semaphore * mutex)
                        : m_mtx(*mutex)
                    {
                        m_mtx.wait();
                    }

                    ~Autolock()
                    {
                        m_mtx.post();
                    }

                protected:

                private:

                    Semaphore & m_mtx;
            };

        private:

            std::string m_namedSemaphore;
            sem_t       m_Sem;
    };
}

#endif

