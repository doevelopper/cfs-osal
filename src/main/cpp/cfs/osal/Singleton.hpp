

#ifndef CFS_OSAL_SINGLETON_HPP
#define CFS_OSAL_SINGLETON_HPP

#include <mutex>
#include <utility>
#include <cstdlib>

#include <cfs/osal/SpinLock.hpp>

namespace cfs::osal
{
    template <class Derived>
    class Singleton
    {
        public:

            template <typename ... Args>
            static inline Derived &GetInstance(Args && ... args)
            {
                return *GetInstancePointer(std::forward<Args>(args)...);
            }

            template <typename ... Args>
            static inline Derived *GetInstancePointer(Args && ... args)
            {
                static Derived * instancePointer = CreateInstance(std::forward<Args>(args)...);
                //m_instancePointer = CreateInstance(std::forward<Args>(args)...);

                return instancePointer;
            }

        protected:

            using Access = Singleton<Derived>;

            Singleton(void) = default;
            Singleton(Singleton const &) = default;
            Singleton(Singleton &&) = default;
            Singleton &operator=(Singleton const &) = default;
            Singleton &operator=(Singleton &&) = default;
            virtual ~Singleton(void) = default;

        private:

            template <typename ... Args>
            static inline Derived *CreateInstance(Args && ... args)
            {
                if (Singleton::m_instancePointer == nullptr)
                {
                    std::lock_guard<decltype(Singleton::m_lock)> lock(Singleton::m_lock);
                    if (Singleton::m_instancePointer == nullptr)
                    {
                        void *data = static_cast<void *>(getData());
                        new (data) Derived(std::forward<Args>(args)...);
                        Singleton::m_instancePointer = reinterpret_cast<Derived *>(data);
                        std::atexit(&Singleton::DestroyInstance);
                    }
                }

                return Singleton::m_instancePointer;
            }

            static inline void DestroyInstance(void)
            {
                reinterpret_cast<Derived *>(getData())->~Derived();
            }

            static inline unsigned char *getData(void)
            {
                static unsigned char data[sizeof(Derived)];

                return data;
            }

            static Derived * m_instancePointer;
            static SpinLock  m_lock;
    };

    template <class Derived>
    Derived *Singleton<Derived>::m_instancePointer = nullptr;

    template <class Derived>
    SpinLock Singleton<Derived>::m_lock;
}
#endif

