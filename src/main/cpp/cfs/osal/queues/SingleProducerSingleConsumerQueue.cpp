

#include <cfs/osal/queues/SingleProducerSingleConsumerQueue.hpp>

using namespace cfs::osal::queues;

template<typename T>
SingleProducerSingleConsumerQueue<T>::SingleProducerSingleConsumerQueue()
    : m_head(reinterpret_cast<Buffer *>(new BufferAligned))
    , m_tail(m_head)
{
    m_head->next = nullptr;
}

template<typename T>
SingleProducerSingleConsumerQueue<T>::~SingleProducerSingleConsumerQueue()
{
    T output;
    while (this->dequeue(output)) {}
    delete m_head;
}

template<typename T>
void SingleProducerSingleConsumerQueue<T>::enqueue(const T& input)
{
    Buffer* node = reinterpret_cast<Buffer*>(new BufferAligned);
    node->data = input;
    node->next = nullptr;

    std::atomic_thread_fence(std::memory_order_acq_rel);
    m_head->next = node;
    m_head = node;
}

template<typename T>
bool SingleProducerSingleConsumerQueue<T>::dequeue(T& output)
{
    std::atomic_thread_fence(std::memory_order_consume);
    if (!m_tail->next)
    {
        return false;
    }

    output = m_tail->next->data;
    std::atomic_thread_fence(std::memory_order_acq_rel);
    m_back = m_tail;
    m_tail = m_back->next;

    delete m_back;

    return true;
}

