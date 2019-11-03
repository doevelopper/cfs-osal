

#include <cfs/osal/ResourceTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

template <typename V>
log4cxx::LoggerPtr ResourceTest<V>::logger = log4cxx::Logger::getLogger(std::string("cfs.osal.test.ResourceTest"));

template <typename V>
ResourceTest<V>::ResourceTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
ResourceTest<V>::~ResourceTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
void ResourceTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

template <typename V>
void ResourceTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TYPED_TEST_P(ResourceTest, test_dummy)
{
    using namespace cfs::osal::test;
    using namespace cfs::osal::log::test;
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    TypeParam n = 0;
    ASSERT_TRUE(true);
}

REGISTER_TYPED_TEST_SUITE_P(ResourceTest
                            , test_dummy
                            );
INSTANTIATE_TYPED_TEST_SUITE_P(TestResource, ResourceTest, bool);

