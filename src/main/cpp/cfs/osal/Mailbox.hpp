

#ifndef CFS_OSAL_MAILBOX_HPP
#define CFS_OSAL_MAILBOX_HPP

#include <memory>
#include <mutex>
#include <queue>

namespace cfs::osal
{
    class Mailbox : public std::enable_shared_from_this<Mailbox>
    {
        enum class Command : std::uint16_t
        {
            STOP,
            BIND,
            DONE
        };

        public:

            std::shared_ptr<Mailbox> getMailbox()
            {
                return shared_from_this();
            }

        protected:

            virtual void send (const Command &cmd) = 0;
            virtual int recv (Command *cmd, int timeout) = 0;

        private:

            std::uint32_t m_pages;
            std::uint32_t m_pagesSize;
    }
}
#endif

