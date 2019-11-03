

#include <cfs/osal/ActivatorTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

template <typename V>
log4cxx::LoggerPtr ActivatorTest<V>::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.ActivatorTest"));

template <typename V>
ActivatorTest<V>::ActivatorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
ActivatorTest<V>::~ActivatorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
void ActivatorTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
void ActivatorTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

#include <chrono>
#include <thread>
TYPED_TEST_P(ActivatorTest, test_dummy)
{
    using namespace cfs::osal::test;
    using namespace cfs::osal::log::test;
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    //TypeParam n = 0;

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2s);
    ASSERT_TRUE(true);
}

REGISTER_TYPED_TEST_SUITE_P(ActivatorTest
                            , test_dummy
                            );

INSTANTIATE_TYPED_TEST_SUITE_P(TestActivator, ActivatorTest, ParameterValueTypes);
//INSTANTIATE_TYPED_TEST_SUITE_P(TestActivator, ActivatorTest, bool);

