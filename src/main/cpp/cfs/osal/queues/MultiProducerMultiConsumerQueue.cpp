

#include <cfs/osal/queues/MultiProducerMultiConsumerQueue.hpp>

using namespace cfs::osal::queues;

template<typename T>
MultiProducerMultiConsumerQueue<T>::MultiProducerMultiConsumerQueue(std::size_t size)
    : m_size(size)
    , m_mask(size - 1)
    ,m_buffer (reinterpret_cast<Buffer*>(new alignedBuffer[m_size]))
    ,m_headSequence(0)
    ,m_tailSequence(0)
{
    // make sure it's a power of 2
    assert((m_size != 0) && ((m_size & (~m_size + 1)) == m_size));

    // populate the sequence initial values

    for (std::size_t i = 0; i < m_size; ++i)
    {
        m_buffer[i].seq.store(i, std::memory_order_relaxed);
    }
}

template<typename T>
MultiProducerMultiConsumerQueue<T>::~MultiProducerMultiConsumerQueue()
{
    delete m_buffer;
}

template<typename T>
bool MultiProducerMultiConsumerQueue<T>::enqueue(const T& data)
{
    // m_headSequence only wraps at MAX(m_headSequence) instead we use a mask to convert the sequence to an array index
    // this is why the ring buffer must be a size which is a power of 2. this also allows the sequence to double as a
    // ticket/lock.
    std::size_t headSeqence = m_headSequence.load(std::memory_order_relaxed);

    for (;;)
    {
        Buffer *  node = &m_buffer[headSeqence & m_mask];
        std::size_t node_seq = node->seq.load(std::memory_order_acquire);
        intptr_t dif = ( static_cast<intptr_t>( node_seq) - static_cast<intptr_t>(headSeqence));

        if (!dif)
        {
            // claim our spot by moving head
            // if head isn't the same as we last checked then that means someone beat us to the punch
            // weak compare is faster, but can return spurious results
            // which in this instance is OK, because it's in the loop
            if (m_headSequence.compare_exchange_weak(headSeqence, headSeqence + 1, std::memory_order_relaxed))
            {
                // set the data
                node->data = data;
                // increment the sequence so that the tail knows it's accessible
                node->seq.store(headSeqence + 1, std::memory_order_release);

                return true;
            }
        }
        else if (dif < 0)
        {
            // if seq is less than head seq then it means this slot is full and therefore the buffer is full
            return false;
        }
        else
        {
            // under normal circumstances this branch should never be taken
            headSeqence = m_headSequence.load(std::memory_order_relaxed);
        }
    }

    return (false);
}

template<typename T>
bool MultiProducerMultiConsumerQueue<T>::dequeue(T& data)
{
    std::size_t tailSeqence = m_tailSequence.load(std::memory_order_relaxed);

    for (;;)
    {
        Buffer*  node = &m_buffer[tailSeqence & m_mask];
        std::size_t node_seq = node->seq.load(std::memory_order_acquire);
        intptr_t dif = ( static_cast<intptr_t>( node_seq) - static_cast<intptr_t>(tailSeqence + 1));
        // if seq and head_seq are the same then it means this slot is empty
        if (!dif)
        {
            // claim our spot by moving head
            // if head isn't the same as we last checked then that means someone beat us to the punch
            // weak compare is faster, but can return spurious results
            // which in this instance is OK, because it's in the loop
            if (m_tailSequence.compare_exchange_weak(tailSeqence, tailSeqence + 1, std::memory_order_relaxed)) {
                // set the output
                data = node->data;
                // set the sequence to what the head sequence should be next time around
                node->seq.store(tailSeqence + m_mask + 1, std::memory_order_release);

                return true;
            }
        }
        else if (dif < 0)
        {
            // if seq is less than head seq then it means this slot is full and therefore the buffer is full
            return false;
        }
        else
        {
            // under normal circumstances this branch should never be taken
            tailSeqence = m_tailSequence.load(std::memory_order_relaxed);
        }
    }

    return (false);
}

