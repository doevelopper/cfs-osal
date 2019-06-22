

#include <functional>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

#include <cfs/osal/MessageTest.hpp>

#include <cfs/osal/MessageTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr MessageTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.MessageTest"));


MessageTest::MessageTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MessageTest::~MessageTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MessageTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(MessageTest, test_1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    const int N = 1000;
    /*
        std::vector<Message::MsgUID> uids1;
        std::vector<Message::MsgUID> uids2;

        auto createMsgs = [](int count, std::vector<Message::MsgUID>& uids)
        {
            for (int i = 0; i < count; ++i)
                uids.push_back(PolyM::Msg(1).getUniqueId());
        };

        std::thread t1(createMsgs, N, std::ref(uids1));
        std::thread t2(createMsgs, N, std::ref(uids2));
        t1.join();
        t2.join();

        for (auto uid1 : uids1)
        {
            for (auto uid2 : uids2)
            {
                NOT_EQUALS(uid1, uid2);
                ASSERT_TRUE(true);
            }
        }
     */
}
TEST_F(MessageTest, test_2)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    ASSERT_TRUE(true);
}

