

#ifndef CFS_OSAL_CPUMANAGER_TOPOLOGY_HPP
#define CFS_OSAL_CPUMANAGER_TOPOLOGY_HPP

#include <cstdint>
#include <vector>
#include <string>

namespace cfs::osal::cpumanager
{
    class Topology
    {
        struct Processor
        {
            std::uint32_t systemId;  /// > Identifier used by the system for this processor. E.g., for processor
            // affinity.
            std::uint32_t threadId;  /// > Thread ID within the the core.
            std::uint32_t coreId;    /// > Core ID within the package.
            std::uint32_t packageId; /// > Package ID within the system.
        };

        using ProcessorList = std::vector < Processor >;

        struct CpuCore
        {
            std::string processor;
            std::string vendor;
            std::string model;
            std::string clockFreqMhz;
            std::string cacheSize;
            std::string flags;
            std::string cpuFamily;
            std::string bogoMips;
        };

        public:

            Topology(const Topology&) = default;
            Topology(Topology&&) = default;
            Topology& operator=(const Topology&) = default;
            Topology& operator=(Topology&&) = default;
            virtual ~Topology() = default;

            ProcessorList const & processors () const;
            ProcessorList const & processorsCore ( std::uint32_t coreId );
            ProcessorList const & processorsPackage ( std::uint32_t packageId );

        protected:

        private:

            ProcessorList m_processors;
    };
}

#endif

