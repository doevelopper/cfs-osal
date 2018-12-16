

#ifndef CFS_OSAL_THREAD_WORKERTHREADTEST_HPP
#define CFS_OSAL_THREAD_WORKERTHREADTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/thread/WorkerThread.hpp>

namespace cfs::osal::thread::test
{
    class WorkerThreadTest : public ::testing::Test
    {
        public:

            WorkerThreadTest();
            WorkerThreadTest(const WorkerThreadTest&) = default;
            WorkerThreadTest(WorkerThreadTest&&) = default;
            WorkerThreadTest& operator=(const WorkerThreadTest&) = default;
            WorkerThreadTest& operator=(WorkerThreadTest&&) = default;
            virtual ~WorkerThreadTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

