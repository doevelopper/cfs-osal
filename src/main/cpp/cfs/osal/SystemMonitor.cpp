

#include <pwd.h>
#include <grp.h>

#include <cfs/osal/SystemMonitor.hpp>

/*

   size_t System::confstr(int name, char *buf, size_t len, long default_val)
   {
    size_t r;

    errno = 0;
    r = ::confstr(name, buf, len);
    if (r == 0) {
        if (errno != 0)
            throw Error(errno);
        else
            r = default_val;
    }
    return r;
   }

    Calls gethostname.
   void System::gethostname(char *name, size_t namelen)
   {
    if (::gethostname(name, namelen) == -1)
        throw Error(errno);
   }

    Calls sysconf.
   long System::sysconf(int name, long default_val)
   {
    long r;

    errno = 0;
    r = ::sysconf(name);
    if (r == -1) {
        if (errno != 0)
            throw Error(errno);
        else
            r = default_val;
    }
    return r;
   }

    Calls uname.
   void System::uname(struct utsname *name)
   {
    if (::uname(name) == -1)
        throw Error(errno);
   }

    Calls getgrgid.
   struct group *System::getgrgid(gid_t gid)
   {
    struct group *p;

    if ((p = ::getgrgid(gid)) == NULL)
        throw Error(errno);
    return p;
   }

    Calls getlogin.
   char *System::getlogin(void)
   {
    char *p;

    if ((p = ::getlogin()) == NULL)
        throw Error(errno);
    return p;
   }

    Calls getpwuid.
   struct passwd *System::getpwuid(uid_t uid)
   {
    struct passwd *p;

    if ((p = ::getpwuid(uid)) == NULL)
        throw Error(errno);
    return p;
   }


   std::size_t getMemoryAvailable()
   {
    struct sysinfo info;
    const int ret = sysinfo(&info);
    assert(ret == 0);
    return info.freeram*info.mem_unit;
   }

   float getMemoryAvailableGBi()
   {
    float memoryAvailable = getMemoryAvailable();
    return (memoryAvailable /= 1024*1024*1024);

   }

   void SystemMonitor::registerCommands()
   {
   add("sys", "overview", overview, "print system overview");
   add("sys", "loadavg", loadavg, "print /proc/loadavg");
   add("sys", "version", version, "print /proc/version");
   add("sys", "cpuinfo", cpuinfo, "print /proc/cpuinfo");
   add("sys", "meminfo", meminfo, "print /proc/meminfo");
   add("sys", "stat", stat, "print /proc/stat");
   }

   std::string SystemMonitor::loadavg()
   {
   string loadavg;
   ProcFile::readFile("/proc/loadavg", 65536, &loadavg);
   return loadavg;
   }

   std::string SystemMonitor::version()
   {
   string version;
   ProcFile::readFile("/proc/version", 65536, &version);
   return version;
   }

   std::string SystemMonitor::cpuinfo()
   {
   string cpuinfo;
   ProcFile::readFile("/proc/cpuinfo", 65536, &cpuinfo);
   return cpuinfo;
   }

   std::string SystemMonitor::meminfo()
   {
   string meminfo;
   ProcFile::readFile("/proc/meminfo", 65536, &meminfo);
   return meminfo;
   }

   std::string SystemMonitor::stat()
   {
   string stat;
   ProcFile::readFile("/proc/stat", 65536, &stat);
   return stat;
   }

   std::string SystemMonitor::overview()
   {
   string result;
   result.reserve(1024);
   Timestamp now = Timestamp::now();
   result += "Page generated at ";
   result += now.toFormattedString();
   result += " (UTC)\n";
   // Hardware and OS
   {
   struct utsname un;
   if (::uname(&un) == 0)
   {
    stringPrintf(&result, "Hostname: %s\n", un.nodename);
    stringPrintf(&result, "Machine: %s\n", un.machine);
    stringPrintf(&result, "OS: %s %s %s\n", un.sysname, un.release, un.version);
   }
   }
   string stat;
   ProcFile::readFile("/proc/stat", 65536, &stat);
   Timestamp bootTime(Timestamp::kMicroSecondsPerSecond * getLong(stat, "btime "));
   result += "Boot time: ";
   result += bootTime.toFormattedString(false /show microseconds /);
   result += " (UTC)\n";
   result += "Up time: ";
   result += uptime(now, bootTime, false / show microseconds /);
   result += "\n";

   // CPU load
   {
   string loadavg;
   ProcFile::readFile("/proc/loadavg", 65536, &loadavg);
   stringPrintf(&result, "Processes created: %ld\n", getLong(stat, "processes "));
   stringPrintf(&result, "Loadavg: %s\n", loadavg.c_str());
   }

   // Memory
   {
   string meminfo;
   ProcFile::readFile("/proc/meminfo", 65536, &meminfo);
   long total_kb = getLong(meminfo, "MemTotal:");
   long free_kb = getLong(meminfo, "MemFree:");
   long buffers_kb = getLong(meminfo, "Buffers:");
   long cached_kb = getLong(meminfo, "Cached:");

   stringPrintf(&result, "Total Memory: %6ld MiB\n", total_kb / 1024);
   stringPrintf(&result, "Free Memory:  %6ld MiB\n", free_kb / 1024);
   stringPrintf(&result, "Buffers:      %6ld MiB\n", buffers_kb / 1024);
   stringPrintf(&result, "Cached:       %6ld MiB\n", cached_kb / 1024);
   stringPrintf(&result, "Real Used:    %6ld MiB\n", (total_kb - free_kb - buffers_kb - cached_kb) / 1024);
   stringPrintf(&result, "Real Free:    %6ld MiB\n", (free_kb + buffers_kb + cached_kb) / 1024);

   // Swap
   }
   // Disk
   // Network
   return result;
   }
 */

