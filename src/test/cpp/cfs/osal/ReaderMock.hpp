

#ifndef CFS_OSAL_MOCK_READERMOCK_HPP
#define CFs_OSAL_MOCK_READERMOCK_HPP

#include <cfs/osal/Reader.hpp>
#include <cfs/osal/log/TestLogger.hpp>

namespace cfs::osal::test::mock
{
    class ReaderMock : public ::testing::NiceMock<Reader>
    {
        public:

            ReaderMock();
            ~ReaderMock();
            MOCK_METHOD(void, gather,(const char* name, std::int8_t& value),(override));

        protected:

        private:

            static log4cxx::LoggerPtr logger;
    };
}

#endif

