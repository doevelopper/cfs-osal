

#include <cfs/osal/ResourceLimitTest.hpp>

using namespace cfs::osal::test;
using namespace cfs::osal::log::test;

log4cxx::LoggerPtr ResourceLimitTest::logger = log4cxx::Logger::getLogger(std::string(
                                                                              "cfs.osal.test.ResourceLimitTest"));


ResourceLimitTest::ResourceLimitTest()
    : testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ResourceLimitTest::~ResourceLimitTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void ResourceLimitTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    //testee = new cfs::osal::ResourceLimit();
}

void ResourceLimitTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete testee;
}

TEST_F(ResourceLimitTest, rsc_limit)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    LOG4CXX_TRACE(logger, "Size of size_t = " << sizeof(std::size_t));
    LOG4CXX_TRACE(logger, "Minimum value for bool: " << std::numeric_limits<bool>::min());
    LOG4CXX_TRACE(logger, "Maximum value for bool: " << std::numeric_limits<bool>::max());
    LOG4CXX_TRACE(logger, "bool is signed: " << std::numeric_limits<bool>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in bool: " << std::numeric_limits<bool>::digits);
    LOG4CXX_TRACE(logger, "bool has infinity: " << std::numeric_limits<bool>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for char: " << std::numeric_limits<char>::min());
    LOG4CXX_TRACE(logger, "Maximum value for char: " << std::numeric_limits<char>::max());
    LOG4CXX_TRACE(logger, "char is signed: " << std::numeric_limits<char>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in char: " << std::numeric_limits<char>::digits);
    LOG4CXX_TRACE(logger, "char has infinity: " << std::numeric_limits<char>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for signed char: " << std::numeric_limits<signed char>::min());
    LOG4CXX_TRACE(logger, "Maximum value for signed char: " << std::numeric_limits<signed char>::max());
    LOG4CXX_TRACE(logger, "signed char is signed: " << std::numeric_limits<signed char>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in signed char: " << std::numeric_limits<signed char>::digits);
    LOG4CXX_TRACE(logger, "signed char has infinity: " << std::numeric_limits<signed char>::has_infinity);

    LOG4CXX_TRACE(logger, "Lowest value for unsigned char: " << std::numeric_limits<unsigned char>::lowest());
    LOG4CXX_TRACE(logger, "Minimum value for unsigned char: " << std::numeric_limits<unsigned char>::min());
    LOG4CXX_TRACE(logger, "Maximum value for unsigned char: " << std::numeric_limits<unsigned char>::max());
    LOG4CXX_TRACE(logger, "unsigned char is signed: " << std::numeric_limits<unsigned char>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in unsigned char: " << std::numeric_limits<unsigned char>::digits);
    LOG4CXX_TRACE(logger, "unsigned char has infinity: " << std::numeric_limits<unsigned char>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for wchar_t: " << std::numeric_limits<wchar_t>::min());
    LOG4CXX_TRACE(logger, "Maximum value for wchar_t: " << std::numeric_limits<wchar_t>::max());
    LOG4CXX_TRACE(logger, "wchar_t is signed: " << std::numeric_limits<wchar_t>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in wchar_t: " << std::numeric_limits<wchar_t>::digits);
    LOG4CXX_TRACE(logger, "wchar_t has infinity: " << std::numeric_limits<wchar_t>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for short: " << std::numeric_limits<short>::min());
    LOG4CXX_TRACE(logger, "Maximum value for short: " << std::numeric_limits<short>::max());
    LOG4CXX_TRACE(logger, "short is signed: " << std::numeric_limits<short>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in short: " << std::numeric_limits<short>::digits);
    LOG4CXX_TRACE(logger, "short has infinity: " << std::numeric_limits<short>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for unsigned short: " << std::numeric_limits<unsigned short>::min());
    LOG4CXX_TRACE(logger, "Maximum value for unsigned short: " << std::numeric_limits<unsigned short>::max());
    LOG4CXX_TRACE(logger, "unsigned short is signed: " << std::numeric_limits<unsigned short>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in unsigned short: " << std::numeric_limits<unsigned short>::digits);
    LOG4CXX_TRACE(logger, "unsigned short has infinity: " << std::numeric_limits<unsigned short>::has_infinity);

    LOG4CXX_TRACE(logger, "Lowest value for int: " << std::numeric_limits<int>::lowest());
    LOG4CXX_TRACE(logger, "Minimum value for int: " << std::numeric_limits<int>::min());
    LOG4CXX_TRACE(logger, "Maximum value for int: " << std::numeric_limits<int>::max());
    LOG4CXX_TRACE(logger, "int is signed: " << std::numeric_limits<int>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in int: " << std::numeric_limits<int>::digits);
    LOG4CXX_TRACE(logger, "int has infinity: " << std::numeric_limits<int>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for unsigned int: " << std::numeric_limits<unsigned int>::min());
    LOG4CXX_TRACE(logger, "Maximum value for unsigned int: " << std::numeric_limits<unsigned int>::max());
    LOG4CXX_TRACE(logger, "unsigned int is signed: " << std::numeric_limits<unsigned int>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in unsigned int: " << std::numeric_limits<unsigned int>::digits);
    LOG4CXX_TRACE(logger, "unsigned int has infinity: " << std::numeric_limits<unsigned int>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for long: " << std::numeric_limits<long>::min());
    LOG4CXX_TRACE(logger, "Maximum value for long: " << std::numeric_limits<long>::max());
    LOG4CXX_TRACE(logger, "long is signed: " << std::numeric_limits<long>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in long: " << std::numeric_limits<long>::digits);
    LOG4CXX_TRACE(logger, "long has infinity: " << std::numeric_limits<long>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for unsigned long: " << std::numeric_limits<unsigned long>::min());
    LOG4CXX_TRACE(logger, "Maximum value for unsigned long: " << std::numeric_limits<unsigned long>::max());
    LOG4CXX_TRACE(logger, "unsigned long is signed: " << std::numeric_limits<unsigned long>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in unsigned long: " << std::numeric_limits<unsigned long>::digits);
    LOG4CXX_TRACE(logger, "unsigned long has infinity: " << std::numeric_limits<unsigned long>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for long long: " << std::numeric_limits<long long>::min());
    LOG4CXX_TRACE(logger, "Maximum value for long long: " << std::numeric_limits<long long>::max());
    LOG4CXX_TRACE(logger, "long long is signed: " << std::numeric_limits<long long>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in long long: " << std::numeric_limits<long long>::digits);
    LOG4CXX_TRACE(logger, "long long has infinity: " << std::numeric_limits<long long>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for unsigned long long: " << std::numeric_limits<unsigned long long>::min());
    LOG4CXX_TRACE(logger, "Maximum value for unsigned long long: " << std::numeric_limits<unsigned long long>::max());
    LOG4CXX_TRACE(logger, "unsigned long long is signed: " << std::numeric_limits<unsigned long long>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in unsigned long long: " << std::numeric_limits<unsigned long long>::digits);
    LOG4CXX_TRACE(logger, "unsigned long long has infinity: " << std::numeric_limits<unsigned long long>::has_infinity);

    LOG4CXX_TRACE(logger, "Lowest value for float: " << std::numeric_limits<float>::lowest());
    LOG4CXX_TRACE(logger, "Minimum value for float: " << std::numeric_limits<float>::min());
    LOG4CXX_TRACE(logger, "Maximum value for float: " << std::numeric_limits<float>::max());
    LOG4CXX_TRACE(logger, "float is signed: " << std::numeric_limits<float>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in float: " << std::numeric_limits<float>::digits);
    LOG4CXX_TRACE(logger, "float has infinity: " << std::numeric_limits<float>::has_infinity);

    LOG4CXX_TRACE(logger, "Lowest value for double: " << std::numeric_limits<double>::lowest());
    LOG4CXX_TRACE(logger, "Minimum value for double: " << std::numeric_limits<double>::min());
    LOG4CXX_TRACE(logger, "Maximum value for double: " << std::numeric_limits<double>::max());
    LOG4CXX_TRACE(logger, "double is signed: " << std::numeric_limits<double>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in double: " << std::numeric_limits<double>::digits);
    LOG4CXX_TRACE(logger, "double has infinity: " << std::numeric_limits<double>::has_infinity);

    LOG4CXX_TRACE(logger, "Minimum value for long double: " << std::numeric_limits<long double>::min());
    LOG4CXX_TRACE(logger, "Maximum value for long double: " << std::numeric_limits<long double>::max());
    LOG4CXX_TRACE(logger, "long double is signed: " << std::numeric_limits<long double>::is_signed);
    LOG4CXX_TRACE(logger, "Non-sign bits in long double: " << std::numeric_limits<long double>::digits);
    LOG4CXX_TRACE(logger, "long double has infinity: " << std::numeric_limits<long double>::has_infinity);
}

