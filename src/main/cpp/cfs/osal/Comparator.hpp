

#ifndef CFS_OSAL_COMPARATOR_HPP
#define CFS_OSAL_COMPARATOR_HPP

namespace cfs::osal
{
    template <class Derived, class T = Derived>
    class Comparator
    {
        friend bool operator==(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) == 0;
        }

        friend bool operator==(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs.compare(lhs) == 0;
        }

        friend bool operator!=(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) != 0;
        }

        friend bool operator!=(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs.compare(lhs) != 0;
        }

        friend bool operator<(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) < 0;
        }

        friend bool operator>(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) > 0;
        }

        friend bool operator<(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs > lhs;
        }

        friend bool operator>(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs < lhs;
        }

        friend bool operator<=(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) <= 0;
        }

        friend bool operator>=(const Derived& lhs, const T& rhs) noexcept
        {
            return lhs.compare(rhs) >= 0;
        }

        friend bool operator<=(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs >= lhs;
        }

        friend bool operator>=(const T& lhs, const Derived& rhs) noexcept
        {
            return rhs <= lhs;
        }
    };

    template <class Derived>
    class Comparator<Derived, Derived>
    {
        friend bool operator==(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) == 0;
        }

        friend bool operator!=(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) != 0;
        }

        friend bool operator<(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) < 0;
        }

        friend bool operator<=(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) <= 0;
        }

        friend bool operator>(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) > 0;
        }

        friend bool operator>=(const Derived& lhs, const Derived& rhs) noexcept
        {
            return lhs.compare(rhs) >= 0;
        }
    };
}

#endif

