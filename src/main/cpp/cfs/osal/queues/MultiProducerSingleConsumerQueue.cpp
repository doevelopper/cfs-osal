

#include <cfs/osal/queues/MultiProducerSingleConsumerQueue.hpp>

using namespace cfs::osal::queues;

template<typename T>
MultiProducerSingleConsumerQueue<T>::MultiProducerSingleConsumerQueue()
    :  m_head(reinterpret_cast<Buffer*>(new bufferAligned))
    ,  m_tail(m_head.load(std::memory_order_relaxed))
{
    Buffer * front = m_head.load(std::memory_order_relaxed);
    front->next.store(nullptr, std::memory_order_relaxed);
}

template<typename T>
MultiProducerSingleConsumerQueue<T>::~MultiProducerSingleConsumerQueue()
{
    T output;
    while (this->dequeue(output)) {}
    Buffer* front = m_head.load(std::memory_order_relaxed);
    delete front;
}

template<typename T>
void MultiProducerSingleConsumerQueue<T>::enqueue(const T& input)
{
    Buffer* node = reinterpret_cast<Buffer*>(new bufferAligned);
    node->data = input;
    node->next.store(nullptr, std::memory_order_relaxed);

    Buffer* prev_head = m_head.exchange(node, std::memory_order_acq_rel);
    prev_head->next.store(node, std::memory_order_release);
}

template<typename T>
bool MultiProducerSingleConsumerQueue<T>::dequeue(T& output)
{
    Buffer* tail = m_tail.load(std::memory_order_relaxed);
    Buffer* next = tail->next.load(std::memory_order_acquire);

    if (next == nullptr)
    {
        return false;
    }

    output = next->data;
    m_tail.store(next, std::memory_order_release);
    delete tail;

    return true;
}

