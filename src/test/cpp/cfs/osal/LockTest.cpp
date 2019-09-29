

#include <mutex>
#include <string>
#include <type_traits>
#include <cfs/osal/LockTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr LockTest::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.LockTest"));


LockTest::LockTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

LockTest::~LockTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void LockTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void LockTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(LockTest, lockAndUnlock)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Lockable<std::string> s1;
    ASSERT_TRUE(true);
}

/*
   using namespace std::string_literals;

   TEST_F(LockTest, lockAndUnlockManually)
   {
    Lockable<std::string> s1;
    s1.lock();
    s1.unlock();
   }

   TEST_F(LockTest, lockGuard)
   {
    Lockable s1{"asd"s};
    EXPECT_TRUE((std::is_same_v<Lockable<std::string>, decltype(s1)>));
    Lock l1{s1};
    EXPECT_TRUE((std::is_same_v<Lock<Lockable<std::string>>,decltype(l1)>));
    EXPECT_EQ("asd", *l1);
    EXPECT_EQ(3u, l1->size());
   }

   TEST_F(LockTest, initializeByCopy)
   {
    auto s0{"qwe"s};
    Lockable s1{s0};
    EXPECT_TRUE((std::is_same_v<Lockable<std::string>, decltype(s1)>));
    Lock l1{s1};
    EXPECT_TRUE((std::is_same_v<Lock<Lockable<std::string>>,decltype(l1)>));
 * l1 = "asd";
    EXPECT_EQ("qwe", s0);
    EXPECT_EQ("asd", *l1);
   }

   TEST_F(LockTest, lockAndSwap)
   {
    Lockable s1{"asd"s};
    Lockable s2{"qwe"s};
    std::lock(s1, s2);
    Lock l1{s1, std::adopt_lock};
    Lock l2{s2, std::adopt_lock};
    std::swap(*l1, *l2);
    EXPECT_EQ(6u, l1->size() + l2->size());
   }

 */

