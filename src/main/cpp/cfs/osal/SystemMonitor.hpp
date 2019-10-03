

#ifndef CFS_OSAL_SYSTEMMONITOR_HPP
#define CFS_OSAL_SYSTEMMONITOR_HPP

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <mutex>

namespace cfs::osal
{
    class SystemMonitor
    {
        public:

            /*
                        template <typename T>
                        class Monitor
                        {
                            public:

                                Monitor()
                                    : t{}
                                {
                                }

                                Monitor(T & it)
                                    : t{it}
                                {
                                }

                                Monitor(T const & it)
                                    : t{it}
                                {
                                }

                                Monitor(T && it)
                                    : t{std::move(it)}
                                {
                                }

                                Monitor(Monitor const & mt)
                                    : t{std::move(mt.object())}
                                {
                                }

                                Monitor(Monitor&&) = delete;
                                Monitor& operator =(Monitor const&) = delete;
                                Monitor& operator =(Monitor&&) = delete;
                                T object() const
                                {
                                    std::lock_guard<std::mutex> guard{m_mtx};

                                    return (t);
                                }

                                template <typename F>
                                auto operator ()(F&& f) const
                                ->decltype(std::forward<F>(f)(t))
                                {
                                    std::lock_guard<std::mutex> guard{m_mtx};

                                    return std::forward<F>(f)(t);
                                }

                            protected:

                            private:

                                mutable T          t;
                                mutable std::mutex m_mtx;
                        };
             */
            SystemMonitor();
            SystemMonitor(const SystemMonitor&) = default;
            SystemMonitor(SystemMonitor&&) = default;
            SystemMonitor& operator=(const SystemMonitor&) = default;
            SystemMonitor& operator=(SystemMonitor&&) = default;
            virtual ~SystemMonitor();

        protected:

        private:
    };
}
#endif

