

#ifndef CFS_OSAL_BIDIRECTIONNALCONTAINERTEST_HPP
#define CFS_OSAL_BIDIRECTIONNALCONTAINERTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/BidirectionnalContainer.hpp>

namespace cfs::osal::test
{
    class BidirectionnalContainerTest : public ::testing::Test
    {
        public:

            BidirectionnalContainerTest();
            BidirectionnalContainerTest(const BidirectionnalContainerTest&) = default;
            BidirectionnalContainerTest(BidirectionnalContainerTest&&) = default;
            BidirectionnalContainerTest& operator=(const BidirectionnalContainerTest&) = default;
            BidirectionnalContainerTest& operator=(BidirectionnalContainerTest&&) = default;
            virtual ~BidirectionnalContainerTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

