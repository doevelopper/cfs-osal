

#ifndef CFS_OSAL_MESSAGE_HPP
#define CFS_OSAL_MESSAGE_HPP

#include <memory>
#include <utility>
#include <functional>
#include <mutex>
#include <queue>

namespace cfs::osal
{
    /*!
     * Message represents a simple message that doesn't have any payload data.
     * Message ID identifies the type of the message. Message ID can be queried with getMsgId().
     */
    class Message
    {
        /*! Type for Message unique identifiers */
        using MsgUID = std::uint64_t;

        public:

            /*!
             * Construct a Message.
             *
             * @param msgId Message ID of this Message.
             */
            Message(int msgId);

            virtual ~Message() = default;
            Message(const Message&) = delete;
            Message& operator=(const Message&) = delete;

            /*!
             * @brief Virtual move constructor
             */
            virtual std::unique_ptr<Message> move();

            /*!
             * Get Message ID.
             * Message ID identifies message type.
             * Multiple Message instances can have the same Message ID.
             */
            int getMsgId() const;

            /*!
             * Get Message UID.
             * Message UID is the unique ID associated with this message.
             * All Message instances have a unique Message UID.
             */
            MsgUID getUniqueId() const;

        protected:

            Message(Message&&) = default;
            Message& operator=(Message&&) = default;

        private:

            static MsgUID generateUniqueId();
            MsgUID m_msgId;
            MsgUID m_uniqueId;
            std::mutex m_queueMutex;
            std::queue<std::unique_ptr<Message>> m_MessageQueue;
    };
}
#endif

