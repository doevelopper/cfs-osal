

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

        struct CpuCache
        {
            std::uint32_t size; /** Cache size in bytes */
            std::uint32_t associativity; /** Number of ways of associativity */
            std::uint32_t sets; /** Number of sets */
            std::uint32_t partitions; /** Number of partitions */
            std::uint32_t line_size; /** Line size in bytes */
            std::uint32_t flags;
            std::uint32_t processorStart; /** Index of the first logical processor that shares this cache */
            std::uint32_t processorCount; /** Number of logical processors that share this cache */
        };

        public:

            Topology();
            Topology(const Topology&) = default;
            Topology(Topology&&) = default;
            Topology& operator=(const Topology&) = default;
            Topology& operator=(Topology&&) = default;
            virtual ~Topology();

            ProcessorList const & processors () const;
            ProcessorList const & processorsCore ( std::uint32_t coreId );
            ProcessorList const & processorsPackage ( std::uint32_t packageId );

        protected:

        private:

            ProcessorList * m_processors;
    };
}

#endif

