

#ifndef CFS_OSAL_MESSAGEDATA_HPP
#define CFS_OSAL_MESSAGEDATA_HPP

#include <memory>
#include <utility>

#include <cfs/osal/Message.hpp>

namespace cfs::osal
{
    /*!
     * MessageData<PayloadType> is a Message with payload of type PayloadType.
     * Payload is constructed when MessageData is created and the MessageData instance owns the payload data.
     */
    template <typename PayloadType>
    class MessageData : public cfs::osal::Message
    {
        public:

            /*!
             * Construct MessageData
             * @param msgId Message ID
             * @param args Arguments for PayloadType ctor
             */
            template <typename ... Args>
            MessageData(int msgId, Args&& ... args)
                : cfs::osal::Message(msgId)
                ,m_payLoad(new PayloadType(std::forward<Args>(args) ...))
            {
            }

            virtual ~MessageData() = default;
            MessageData(const MessageData&) = delete;
            MessageData& operator=(const MessageData&) = delete;

            /*! "Virtual move constructor" */
            virtual std::unique_ptr<Message> move() override
            {
                return std::unique_ptr<Message>(new MessageData<PayloadType>(std::move(*this)));
            }

            /*! Get the payload data */
            PayloadType& getPayload() const
            {
                return *m_payLoad;
            }

        protected:

            MessageData(MessageData&&) = default;
            MessageData& operator=(MessageData&&) = default;

        private:

            std::unique_ptr<PayloadType> m_payLoad;
    };
}

#endif

