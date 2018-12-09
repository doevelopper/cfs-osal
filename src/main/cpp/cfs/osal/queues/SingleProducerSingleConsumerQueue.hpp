

#ifndef CFS_OSAL_QUEUES_SINGLEPRODUCERSINGLECONSUMERQUEUE_HPP
#define CFS_OSAL_QUEUES_SINGLEPRODUCERSINGLECONSUMERQUEUE_HPP

#include <atomic>


namespace cfs::osal::queues
{
    // non-intrusive lock free unbounded SPSC queue
    // the algorithm was taken from the blog post below, and converted to C++11
    // http://cbloomrants.blogspot.com/2009/02/02-26-09-low-level-threading-part-51.html

    template<typename T>
    class SingleProducerSingleConsumerQueue
    {
        struct Buffer
        {
            Buffer * next;
            T data;
        };

        using BufferAligned = typename std::aligned_storage<sizeof(Buffer), std::alignment_of<Buffer>::value>::type;

        public:

            SingleProducerSingleConsumerQueue();
            ~SingleProducerSingleConsumerQueue();
            void  enqueue(const T& input);
            bool dequeue(T& output);

        protected:

        private:

            SingleProducerSingleConsumerQueue(const SingleProducerSingleConsumerQueue&) {
            }

            void operator=(const SingleProducerSingleConsumerQueue&) {
            }

            Buffer * m_head;
            Buffer * m_tail;
            Buffer * m_back;
    };
}
#endif

