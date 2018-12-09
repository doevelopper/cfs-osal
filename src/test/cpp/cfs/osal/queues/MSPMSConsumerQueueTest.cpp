

#include <cfs/osal/queues/MSPMSConsumerQueueTest.hpp>

using namespace cfs::osal::queues::test;

log4cxx::LoggerPtr MSPMSConsumerQueueTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                                   "cfs.osal.queues.test.MSPMSConsumerQueueTest"));
const unsigned long MSPMSConsumerQueueTest::ITERATION = 100000000;

MSPMSConsumerQueueTest::MSPMSConsumerQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MSPMSConsumerQueueTest::~MSPMSConsumerQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template<typename T>
void MSPMSConsumerQueueTest::consumerFunc( T* queue)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::size_t count = ITERATION;
    std::size_t value = 0;

    while (count > 0)
    {
        LOG4CXX_DEBUG(logger, count );
        if (queue->dequeue(value))
        {
            LOG4CXX_INFO(logger, count );
            --count;
        }
    }
}

template<typename T>
void MSPMSConsumerQueueTest::boundedProducerFunc( T* queue)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    std::size_t count = ITERATION;
    while (count > 0)
    {
        LOG4CXX_DEBUG(logger, count );
        if (queue->enqueue(count))
        {
            LOG4CXX_INFO(logger, count );
            --count;
        }
    }
}

template<typename T>
void MSPMSConsumerQueueTest::producerFunc(T* queue)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    for (int count = 0; count < ITERATION; ++count)
    {
        LOG4CXX_INFO(logger, count );
        queue->enqueue(count);
    }
}

template<typename T>
long double MSPMSConsumerQueueTest::run( T producerFunction, T consumerFunction)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    time_t start;
    time_t end;

    start = clock_t::now();
    LOG4CXX_TRACE(logger, start );
    std::thread producer(producerFunction);
    std::thread consumer(consumerFunction);
    producer.join();
    consumer.join();
    end = clock_t::now();
    LOG4CXX_TRACE(logger, end );

    return
        (end - start).count()
        * (static_cast<double> (std::chrono::high_resolution_clock::period::num)
           / std::chrono::high_resolution_clock::period::den);
}

void MSPMSConsumerQueueTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MSPMSConsumerQueueTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MSPMSConsumerQueueTest, spscTest)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using queue_t = cfs::osal::queues::SingleProducerSingleConsumerQueue<std::size_t>;
    //    queue_t queue(65536);
    long double seconds = 1.;     //run(std::bind(&bounded_producer_func<queue_t>, &queue),
                                  //      std::bind(&consumer_func<queue_t>, &queue));

    LOG4CXX_TRACE(logger, "SPSC bound queue completed "
                  <<  ITERATION
                  << " iterations in "
                  << seconds
                  << " seconds. "
                  << (static_cast<long double>(ITERATION) / seconds) / 1000000
                  << " million enqueue/dequeue pairs per second.");
    ASSERT_TRUE(true);
}

TEST_F(MSPMSConsumerQueueTest, mpmcTest)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using queue_t = cfs::osal::queues::MultiProducerMultiConsumerQueue<std::size_t>;
    //    queue_t queue(65536);
    ASSERT_TRUE(true);
}

TEST_F(MSPMSConsumerQueueTest, spscTest1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using queue_t = cfs::osal::queues::SingleProducerSingleConsumerQueue<std::size_t>;
    //    queue_t queue;
    ASSERT_TRUE(true);
}

TEST_F(MSPMSConsumerQueueTest, mpscTest)

{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    using queue_t = cfs::osal::queues::MultiProducerSingleConsumerQueue<std::size_t>;
    //    queue_t queue;
    ASSERT_TRUE(true);
}

