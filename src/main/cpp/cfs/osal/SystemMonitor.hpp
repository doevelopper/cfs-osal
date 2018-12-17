

#ifndef CFS_OSAL_SYSTEMMONITOR_HPP
#define CFS_OSAL_SYSTEMMONITOR_HPP

#include <sys/utsname.h>
#include <sys/sysinfo.h>
namespace cfs::osal
{
    class SystemMonitor
    {
        public:

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

