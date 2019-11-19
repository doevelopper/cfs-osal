

#include <atomic>
#include <cfs/osal/Message.hpp>

using namespace cfs::osal;

Message::Message()
{
}

Message::~Message()
{
}

Message::MsgUID Message::generateUniqueId()
{
    static std::atomic<MsgUID> i(0);

    return (++i);
}

Message::Message(int msgId)
    : m_msgId(msgId)
    , m_uniqueId(generateUniqueId())
{
}

/*
   std::unique_ptr<Message> Message::move()
   {
    return std::unique_ptr<Message>(new Message(std::move(*this)));
   }
 */

int Message::getMsgId() const
{
    return m_msgId;
}

Message::MsgUID Message::getUniqueId() const
{
    return m_uniqueId;
}

