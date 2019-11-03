

#ifndef CFS_OSAL_RESOURCE_HPP
#define CFS_OSAL_RESOURCE_HPP

#include <mutex>
#include <utility>
#include <cstdlib>
#include <memory>


namespace cfs::osal
{
    constexpr std::size_t MSG_Q_TICK_TIMEOUT = 10;

    template<class T>
    class Resource
    {
        public:

            virtual ~Resource<T>() = default;

            /*!
             * @brief Get the Rsc Instance object
             *
             * @return Resource<T>&
             */
            static Resource<T>& getRscInstance()
            {
                std::call_once(m_once, []() {
                m_instance.reset(new T);
            });

                return *m_instance.get();
            }

            /**
             * @brief
             *
             * @return T*
             */
            T* operator->()
            {
                return m_instance;
            }

            /*!
             * @brief
             *
             * @return const T*
             */
            const T* operator->() const
            {
                return m_instance;
            }

            /*!
             * @brief
             *
             * @return T&
             */
            T& operator*()
            {
                return *m_instance;
            }

            /*!
             * @brief
             *
             * @return const T&
             */
            const T& operator*() const
            {
                return *m_instance;
            }

        private:

            Resource<T>(const Resource<T>&) = delete;
            Resource<T>& operator=(const Resource<T>&) = delete;
            Resource<T>() = default;
            static std::unique_ptr<Resource<T> > m_instance;
            static std::once_flag                m_once;
    };
}
#endif

