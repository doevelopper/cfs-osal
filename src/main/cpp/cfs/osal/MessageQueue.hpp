

#ifndef CFS_OSAL_MESSAGEQUEUE_HPP
#define CFS_OSAL_MESSAGEQUEUE_HPP

#include <cstdint>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>
#include <utility>
#include <string>

#include <cfs/osal/FileDescriptor.hpp>

namespace cfs::osal
{
    struct MQAttrribute
    {
        long mq_flags;      /* Queue's Flags */
        long mq_maxmsg;     /* Maximum number of  messages in the queue */
        long mq_msgsize;    /* Maximal size of each message in bytes*/
        long mq_curmsgs;    /* Number of messages actually in the queue */

        MQAttrribute(long flag = 0L, long mxmsg = 10L, long msgSize = 8192L, long currentMsg = 0L)
            : mq_flags(flag)
            , mq_maxmsg(mxmsg)
            , mq_msgsize(msgSize)
            , mq_curmsgs(currentMsg)
        {
        }
    };

    /*!
     * @enum flags
     * @brief Note that all RW flags have O_CREAT. This is to uncouple the idea
     *        of parent/child (creator/slave, master/slave) relationships.
     *        The creator is the one who opens first.
     */
    enum class flags : std::uint32_t
    {
        MQ_READ = O_CREAT | O_CLOEXEC | O_RDONLY,
        MQ_RW = O_CREAT | O_CLOEXEC | O_RDWR,
        MQ_WRITE = O_CREAT | O_CLOEXEC | O_WRONLY,
        /**< Mainly used single-mode where a single message queue is used for both send and recv */
        MQ_ERROR_ON_EXIST = O_EXCL,
        MQ_NONBLOCK = O_NONBLOCK,
        /**< Removes file handle when message_queue is closed */
        MQ_UNLINK_ON_CLOSE = 0x0800000,
        /**< If a message_queue is opened and contains a read flag, this
         * will flush out all unread messages at construction and destruction time */
        MQ_FLUSH = 0x1000000,
    };

    class MessageQueue
    {
        public:

            MessageQueue() = delete;
            MessageQueue(const char *name, int oflag);
            MessageQueue(const char *name, int oflag, mode_t mode,
                         struct mq_attr *attr);
            MessageQueue(const MessageQueue&) = delete;
            MessageQueue(MessageQueue&&) = delete;
            MessageQueue& operator=(const MessageQueue&) = delete;
            MessageQueue& operator=(MessageQueue&&) = delete;

            /*!
             * @brief Destructor.
             * Flushes and/or unlinks the queue if the flags allow
             */
            virtual ~MessageQueue();
            /*!
             * @brief Sends a message to this message queue.
             *
             * @param message_data the message data
             * @param message_size the message size in bytes
             * @param message_priority the message priority (defaults to zero)
             * @param send_timeout the send timeout in milliseconds, or -1 for a blocking send
             * @pre `message_data` must not be `nullptr`.
             */
            void send ( const void* messageData,
                        std::size_t messageSize,
                        std::uint32_t messagePriority = 0,
                        std::int64_t sendTimeout = -1);
            /*!
             * @brief Receives a message from this message queue.
             *
             * @param message_data the message data
             * @param message_size the message size in bytes
             * @param message_priority the message priority (optionally)
             * @param recv_timeout the receive timeout in milliseconds, or -1 for a blocking receive
             * @pre `message_data` must not be `nullptr`.
             */
            std::size_t receive( void* messageData,
                                 std::size_t messageSize,
                                 std::uint32_t * messagePriority = nullptr,
                                 std::int64_t recvTimeout = -1);
            /*!
             * @brief allows the calling process to register or unregister for
             *        delivery of an asynchronous notification when a new message arrives
             *        on the empty message queue referred to by the message queue
             *        descriptor mqdes.
             * @param [in,out] sevp Argument is a pointer to a sigevent structure.
             * @retval  0: On success.
             * @retval -1: on error. And errno set to indicate the error.
             */

            std::int32_t notify(mqd_t mqdes, const struct sigevent *sevp);

            /*!
             * @brief Retrieve attributes of the message queue referred to by the message queue
             *        descriptor mqdes.
             * @param [in] mqdes ...
             * @param [in,out] attr ...
             * @retval  0: On success...
             * @retval -1: on error. And errno set to indicate the error.
             */
            std::int32_t getAttributes(mqd_t mqdes, struct mq_attr *attr) const;
            /*!
             * @brief Modify attributes of the message queue referred to by the message queue
             *        descriptor mqdes.
             * @param [in] mqdes ...
             * @param [in,out] newattr ...
             * @param [in,out] oldattr ...
             * @retval  0: On success...
             * @retval -1: on error. And errno set to indicate the error.
             */
            std::int32_t setAttributes(mqd_t mqdes, const struct mq_attr *newattr,
                                       struct mq_attr *oldattr);
            /*!
             * @brief removes the specified message queue name.  The message
             *         queue name is removed immediately.  The queue itself is destroyed
             *         once any other processes that have the queue open close their
             *          descriptors referring to the queue.
             * @param [in,out] name.  Name of message queue to remove.
             * @retval  0: On success.
             * @retval -1: on error. And errno set to indicate the error.
             */

            void unlink(const char * name);

        private:

            int send(mqd_t mqdes, const char *msg_ptr,
                     size_t msg_len, unsigned int msg_prio);

            ssize_t receive(mqd_t mqdes, char *msg_ptr,
                            size_t msg_len, unsigned int *msg_prio);
            /**
             * @brief MQ flush implementation. Calls recv and throws away all
             *          current messages. Note, uses new[recv_buffer_size()]
             * @todo avoid allocation.
             */
            void flush();

            struct mq_attr                    m_mqAttribute;
            std::underlying_type<flags>::type m_flags;
            mqd_t                             m_queue;
    };
}
#endif

