

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
            /*!
             * @brief Checks if the error bit is set.
             */
            operator bool() const;
            /*
               Error::operator bool() const
               {
                return error_is_set(std::addressof(error));
               }

             */
            template <typename ... Args>
            raiseError(typename std::remove_reference<decltype(errno)>::type const errval,  Args&&... args)
            {
                throw std::system_error {
                          errval,
                          std::system_category().default_error_condition(errval).category(),
                          std::forward<Args>(args)...};
            }
            void logSystemErrorMsg()
            {
                try
                {
                    throw;
                }
                catch (std::system_error const& e)
                {
                    auto c = e.code();
                    std::cout << "errno = "     << c.value() << "..."  << std::endl
                              << "What: " << e.what()            << std::endl
                              << "Category: " << c.category().name() << std::endl
                              << "Value: " << c.value()           << std::endl
                              << "Message: " << c.message()         << std::endl
                              << std::endl;
                }
            }
    };
}
#endif

