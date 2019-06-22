

#ifndef CFS_OSAL_SINGLETONTEST_HPP
#define CFS_OSAL_SINGLETONTEST_HPP

#include <gmock/gmock.h>
#include <cfs/osal/log/TestLogger.hpp>
#include <cfs/osal/Singleton.hpp>


namespace cfs::osal::test
{
    class SingletonTest : public ::testing::Test
    {
        public:

            SingletonTest();
            SingletonTest(const SingletonTest&) = default;
            SingletonTest(SingletonTest&&) = default;
            SingletonTest& operator=(const SingletonTest&) = default;
            SingletonTest& operator=(SingletonTest&&) = default;
            virtual ~SingletonTest();

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;

        private:
    };
}
#endif

