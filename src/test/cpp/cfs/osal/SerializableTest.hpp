

#ifndef CFS_OSAL_TASK_SERIALIZABLETEST_HPP
#define CFS_OSAL_TASK_SERIALIZABLETEST_HPP

#include <cfs/osal/Serializable.hpp>
#include <cfs/osal/log/TestLogger.hpp>

#include <gmock/gmock.h>

namespace cfs::osal::test
{
    class SerializableTest : public ::testing::Test
    {
        public:

            SerializableTest() = default;
            SerializableTest(const SerializableTest&) = default;
            SerializableTest(SerializableTest&&) = default;
            SerializableTest& operator=(const SerializableTest&) = default;
            SerializableTest& operator=(SerializableTest&&) = default;
            virtual ~SerializableTest() = default;

            void SetUp() override;
            void TearDown() override;

        protected:

            static log4cxx::LoggerPtr logger;
    };
}

#endif

