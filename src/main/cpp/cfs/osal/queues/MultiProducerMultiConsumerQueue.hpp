

#ifndef CFS_OSAL_QUEUES_MULTIPRODUCERMULTICONSUMERQUEUE_HPP
#define CFS_OSAL_QUEUES_MULTIPRODUCERMULTICONSUMERQUEUE_HPP

#include <atomic>
#include <assert.h>

namespace cfs::osal::queues
{
    /*!
        Implementation of Dmitry Vyukov's MPMC algorithm
        http://www.1024cores.net/home/lock-free-algorithms/queues/bounded-mpmc-queue
     */
    template<typename T>
    class MultiProducerMultiConsumerQueue
    {
        struct Buffer
        {
            T data;
            std::atomic<std::size_t> seq;
        };
        using alignedBuffer = typename std::aligned_storage<sizeof(Buffer), std::alignment_of<Buffer>::value>::type;

        public:

            MultiProducerMultiConsumerQueue(std::size_t size);
            ~MultiProducerMultiConsumerQueue();
            bool enqueue(const T& data);
            bool dequeue(T& data);

        protected:

        private:

            MultiProducerMultiConsumerQueue(const MultiProducerMultiConsumerQueue&)
            {
            }

            void operator=(const MultiProducerMultiConsumerQueue&)
            {
            }

            const std::size_t        m_size;
            const std::size_t        m_mask;
            Buffer * const           m_buffer;
            std::atomic<std::size_t> m_headSequence;
            std::atomic<std::size_t> m_tailSequence;
    };
}
#endif

