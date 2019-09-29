

#ifndef CFS_OSAL_ERROR_HPP
#define CFS_OSAL_ERROR_HPP

#include <cfs/osal/Comparator.hpp>

namespace cfs::osal
{
    template <class T>
    struct ErrorBuilder
    {
        public:

            static constexpr bool value = std::is_enum<T>::value && std::is_same<Error, type>::value;

        private:

            template <class U>
            static auto isPossible(U* x) -> decltype(make_error(*x));
            template <class U>
            static auto isPossible(...) -> void;
            using type = decltype(isPossible<T>(nullptr));
    };

    class Error : cfs::osal::Comparator<Error>
    {
        public:

            Error() noexcept;
            Error(Error&&) noexcept;
            Error& operator=(Error&&) noexcept;
            Error(const Error&);
            Error& operator=(const Error&);
    };
}
#endif

