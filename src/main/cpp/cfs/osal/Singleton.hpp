

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
                static Derived *instancePointer = CreateInstance(std::forward<Args>(args)...);

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

            static Derived *InstancePointer;

            static SpinLock Lock;

            template <typename ... Args>
            static inline Derived *CreateInstance(Args && ... args)
            {
                if (Singleton::InstancePointer == nullptr)
                {
                    std::lock_guard<decltype(Singleton::Lock)> lock(Singleton::Lock);
                    if (Singleton::InstancePointer == nullptr)
                    {
                        void *data = static_cast<void *>(GetData());
                        new (data) Derived(std::forward<Args>(args)...);
                        Singleton::InstancePointer = reinterpret_cast<Derived *>(data);
                        std::atexit(&Singleton::DestroyInstance);
                    }
                }

                return Singleton::InstancePointer;
            }

            static inline void DestroyInstance(void)
            {
                reinterpret_cast<Derived *>(GetData())->~Derived();
            }

            static inline unsigned char *GetData(void)
            {
                static unsigned char data[sizeof(Derived)];

                return data;
            }
    };

    template <class Derived>
    Derived *Singleton<Derived>::InstancePointer = nullptr;

    template <class Derived>
    SpinLock Singleton<Derived>::Lock;
}
#endif

