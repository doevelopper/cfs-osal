

#ifndef CFS_OSAL_MAILBOX_HPP
#define CFS_OSAL_MAILBOX_HPP

#include <memory>
#include <mutex>
#include <queue>
#include <cstdint>

#include <cfs/osal/Export.hpp>

namespace cfs::osal
{
    class CFS_OSAL_MAIN_EXPORT Mailbox : public std::enable_shared_from_this<Mailbox>
    {
        enum class Command : std::uint16_t
        {
            STOP = 0,
            BIND = 1,
            DONE = 2
        };

        public:

            virtual ~Mailbox(){
            }

            std::shared_ptr<Mailbox> getMailbox()
            {
                return shared_from_this();
            }

            void *mapmem(std::uint32_t base, std::uint32_t size);
            void *unmapmem(void *addr, std::uint32_t sizea);
            static std::int16_t property(std::uint32_t fdesc, void *buf);
            std::uint32_t memoryAllocate(std::int32_t fdesc, std::uint32_t size, std::uint32_t align, std::uint32_t
                                         flags);
            std::uint32_t memoryFree(std::int32_t fdesc, std::uint32_t handle);
            std::uint32_t memoryLock(std::int32_t fdesc, std::uint32_t handle);
            std::uint32_t memoryUnLock(std::int32_t fdesc, std::uint32_t handle);

        protected:

            virtual void send (const Command &cmd) = 0;
            virtual int recv (Command *cmd, int timeout) = 0;

        private:

            std::uint32_t              m_pages;
            std::uint32_t              m_pagesSize;
            static const std::uint32_t PAGE_SIZE = (4*1024);
    };
}
#endif

