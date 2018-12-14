

#ifndef CFS_OSAL_QUEUES_MSPMSCONSUMERQUEUETEST_HPP
#define CFS_OSAL_QUEUES_MSPMSCONSUMERQUEUETEST_HPP

#include <thread>
#include <chrono>

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>

#include <cfs/osal/queues/MultiProducerMultiConsumerQueue.hpp>
#include <cfs/osal/queues/MultiProducerSingleConsumerQueue.hpp>
#include <cfs/osal/queues/SingleProducerSingleConsumerQueue.hpp>

namespace cfs::osal::queues::test
{
    class MSPMSConsumerQueueTest : public ::testing::Test
    {
        public:

            MSPMSConsumerQueueTest();
            MSPMSConsumerQueueTest(const MSPMSConsumerQueueTest&) = default;
            MSPMSConsumerQueueTest(MSPMSConsumerQueueTest&&) = default;
            MSPMSConsumerQueueTest& operator=(const MSPMSConsumerQueueTest&) = default;
            MSPMSConsumerQueueTest& operator=(MSPMSConsumerQueueTest&&) = default;
            virtual ~MSPMSConsumerQueueTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            using clock_t = std::chrono::high_resolution_clock;
            using time_t = std::chrono::time_point<clock_t>;

            template<typename T>
            void consumerFunc( T* queue);

            template<typename T>
            void boundedProducerFunc( T* queue);

            template<typename T>
            void producerFunc(T* queue);

            template<typename T>
            long double run( T producerFunc, T consumerFunc);
            /*
                        template<typename T>
                        cfs::osal::queues::MultiProducerMultiConsumerQueue * mpScUnterTest;
                        template<typename T>
                        cfs::osal::queues::MultiProducerSingleConsumerQueue * mpScUnterTest;
                        template<typename T>
                        cfs::osal::queues::SingleProducerSingleConsumerQueue * spscUnterTest;
             */
            static const unsigned long ITERATION;
            static log4cxx::LoggerPtr  logger;

        private:
    };
}
#endif

