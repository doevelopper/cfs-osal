

#ifndef CFS_OSAL_MESSAGEQUEUE_HPP
#define CFS_OSAL_MESSAGEQUEUE_HPP

#include <cstdint>
#include <mqueue.h>

namespace cfs::osal
{
    class MessageQueue
    {
        public:

            MessageQueue(const MessageQueue&) = default;
            MessageQueue(MessageQueue&&) = default;
            MessageQueue& operator=(const MessageQueue&) = default;
            MessageQueue& operator=(MessageQueue&&) = default;
            virtual ~MessageQueue() = default;
    };
}
#endif

