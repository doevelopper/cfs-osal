

#ifndef CFS_OSAL_QUEUES_MULTIPRODUCERSINGLECONSUMERQUEUE_HPP
#define CFS_OSAL_QUEUES_MULTIPRODUCERSINGLECONSUMERQUEUE_HPP

#include <atomic>


namespace cfs::osal::queues
{
    // C++ implementation of Dmitry Vyukov's non-intrusive lock free unbound MPSC queue
    // http://www.1024cores.net/home/lock-free-algorithms/queues/non-intrusive-mpsc-node-based-queue

    template<typename T>
    class MultiProducerSingleConsumerQueue
    {
        struct Buffer
        {
            T data;
            std::atomic<Buffer*> next;
        };

        using bufferAligned = typename std::aligned_storage<sizeof(Buffer), std::alignment_of<Buffer>::value>::type;

        public:

            MultiProducerSingleConsumerQueue();
            ~MultiProducerSingleConsumerQueue();
            void enqueue(const T& input);
            bool dequeue(T& output);

        protected:

        private:

            std::atomic<Buffer*> m_head;
            std::atomic<Buffer*> m_tail;

            MultiProducerSingleConsumerQueue(const MultiProducerSingleConsumerQueue&) {
            }

            void operator=(const MultiProducerSingleConsumerQueue&) {
            }
    };
}

#endif

