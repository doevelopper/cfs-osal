

/***************************************************************************
 * Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
 *                                                                          *
 * Distributed under the terms of the BSD 3-Clause License.                 *
 *                                                                          *
 * The full license is in the file LICENSE, distributed with this software. *
 ****************************************************************************/

#ifndef CFS_OSAL_PROPERTIES_XPROPERTY_HPP
#define CFS_OSAL_PROPERTIES_XPROPERTY_HPP

#include <cstddef>
#include <type_traits>
#include <utility>

//#include "xtl/xfunctional.hpp"

namespace xp
{
    /****************************
    * xoffsetof implementation *
    ****************************/

    #ifdef __clang__
        #define xoffsetof(O, M)                                    \
    _Pragma("clang diagnostic push")                           \
    _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
    __builtin_offsetof(O, M)                                   \
    _Pragma("clang diagnostic pop")
    #else
        #ifdef __GNUC__
            #pragma GCC diagnostic ignored "-Winvalid-offsetof"
        #endif
        #define xoffsetof(O, M) offsetof(O, M)
    #endif

    /*************************
    * XProperty declaration *
    *************************/

    // Type, Owner Type, Derived Type

    template <class T, class O, class D>
    class XProperty
    {
        public:

            using xp_owner_type = O;
            using xp_derived_type = D;

            xp_derived_type& derived_cast() & noexcept;
            const xp_derived_type& derived_cast() const & noexcept;
            xp_derived_type derived_cast() && noexcept;

            using value_type = T;
            using reference = T&;
            using const_reference = const T&;

            constexpr XProperty() noexcept(noexcept(std::is_nothrow_constructible<value_type>::value));
            constexpr XProperty(const_reference
                                value) noexcept(noexcept(std::is_nothrow_constructible<value_type>::value));
            constexpr XProperty(
                value_type&& value) noexcept(noexcept(std::is_nothrow_move_constructible<value_type>::value));

            operator reference() noexcept;
            operator const_reference() const noexcept;

            reference operator()() noexcept;
            const_reference operator()() const noexcept;

            xp_owner_type operator()(value_type& arg) && noexcept;
            xp_owner_type operator()(const value_type& arg) && noexcept;
            xp_owner_type operator()(value_type&& arg) && noexcept;

            template <class Arg1, class Arg2, class... Args>
            xp_owner_type operator()(Arg1&& arg1, Arg2&& arg2, Args&& ... args) && noexcept;


            reference operator=(value_type& value);
            reference operator=(const value_type& value);
            reference operator=(value_type&& value);

            template <class V>
            reference operator=(V&& value);

        private:

            xp_owner_type* owner() noexcept;

            value_type m_value;
    };

    /********************************************************
    * XPROPERTY, XDEFAULT_VALUE, XDEFAULT_GENERATOR macros *
    ********************************************************/

    // XPROPERTY(Type, Owner, Name)
    // XPROPERTY(Type, Owner, Name, Value)
    // XPROPERTY(Type, Owner, Name, Value, Validator)
    //
    // Defines a property of the specified type and name, for the specified owner type.
    //
    // The owner type must have two template methods
    //
    //  - template <std::size_t Offset, class T>
    //    auto invoke_validators(T&& proposal) const;
    //  - template <std::size_t Offset
    //    void invoke_observers() const;
    //
    // The `Offset` integral parameter is the offset of the observed member in the owner class.
    // The `T` typename is a universal reference on the proposed value.
    // The return type of `invoke_validator` must be convertible to the value_type of the property.

    #define XPROPERTY_GENERAL(T, O, D, value, lambda_validator)                                  \
    class D ## _property : public ::xp::XProperty<T, O, D ## _property>                              \
    {                                                                                            \
        public:                                                                                      \
                                                                                                 \
            using base_type = ::xp::XProperty<T, O, D ## _property>;                                   \
                                                                                                 \
            template <class V>                                                                       \
            typename base_type::reference operator=(V&& rhs)                                         \
            {                                                                                        \
                lambda_validator(rhs);                                                               \
                return base_type::operator=(std::forward<V>(rhs));                                   \
            }                                                                                        \
                                                                                                 \
            static inline const std::string& name() noexcept                                         \
            {                                                                                        \
                static const std::string name = #D;                                                  \
                return name;                                                                         \
            }                                                                                        \
                                                                                                 \
            static inline constexpr std::size_t offset() noexcept                                    \
            {                                                                                        \
                return xoffsetof(O, D);                                                              \
            }                                                                                        \
                                                                                                 \
            static inline T default_value()                                                          \
            {                                                                                        \
                return T(value);                                                                     \
            }                                                                                        \
    } D;

    #define XPROPERTY_NODEFAULT(T, O, D)                                                         \
    XPROPERTY_GENERAL(T, O, D, T(), xtl::identity())

    #define XPROPERTY_DEFAULT(T, O, D, V)                                                        \
    XPROPERTY_GENERAL(T, O, D, V, xtl::identity())

    #define XPROPERTY_OVERLOAD(_1, _2, _3, _4, _5, NAME, ...) NAME

    #ifdef _MSC_VER
    // Workaround for MSVC not expanding macros
    #define XPROPERTY_EXPAND(x) x
    #define XPROPERTY(...) XPROPERTY_EXPAND(XPROPERTY_OVERLOAD(__VA_ARGS__, XPROPERTY_GENERAL, XPROPERTY_DEFAULT, \
                                                               XPROPERTY_NODEFAULT)(__VA_ARGS__))
    #else
    #define XPROPERTY(...) XPROPERTY_OVERLOAD(__VA_ARGS__, XPROPERTY_GENERAL, XPROPERTY_DEFAULT, \
                                              XPROPERTY_NODEFAULT)(__VA_ARGS__)
    #endif

    /***********************
    * MAKE_OBSERVED macro *
    ***********************/

    // MAKE_OBSERVED()
    //
    // Adds the required boilerplate for an obsered structure.

    #define MAKE_OBSERVED()                                                                 \
    template <class P>                                                                      \
    inline void notify(const P&) const {}                                                   \
                                                                                            \
    template <class P>                                                                      \
    inline void invoke_observers() const {}                                                 \
                                                                                            \
    template <class P, class V>                                                             \
    inline auto invoke_validators(V&& r) const { return r; }

    /*************************
    * XOBSERVE_STATIC macro *
    *************************/

    // XOBSERVE_STATIC(Type, Owner, Name)
    //
    // Set up the static notifier for the specified property

    #define XOBSERVE_STATIC(T, O, D) \
    template <>                      \
    inline void O::invoke_observers<O::D ## _property>() const

    /**************************
    * XVALIDATE_STATIC macro *
    **************************/

    // XVALIDATE_STATIC(Type, Owner, Name, Proposal Argument Name)
    //
    // Set up the static validator for the specified property

    #define XVALIDATE_STATIC(T, O, D, A) \
    template <>                          \
    inline auto O::invoke_validators<O::D ## _property, T>(T&& A) const

    /****************************
    * XProperty implementation *
    ****************************/

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::derived_cast() & noexcept->xp_derived_type&
    {
        return *static_cast<xp_derived_type*>(this);
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::derived_cast() const & noexcept->const xp_derived_type&
    {
        return *static_cast<const xp_derived_type*>(this);
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::derived_cast() && noexcept->xp_derived_type
    {
        return *static_cast<xp_derived_type*>(this);
    }

    template <class T, class O, class D>
    inline constexpr XProperty<T, O,
                               D>::XProperty() noexcept(noexcept(std::is_nothrow_constructible<value_type>::value))
        : m_value(D::default_value())
    {
    }

    template <class T, class O, class D>
    inline constexpr XProperty<T, O, D>::XProperty(
        value_type&& value) noexcept(noexcept(std::is_nothrow_move_constructible<value_type>::value))
        : m_value(value)
    {
    }

    template <class T, class O, class D>
    inline constexpr XProperty<T, O, D>::XProperty(const_reference
                                                   value) noexcept(noexcept(std::is_nothrow_constructible<value_type>::
                                                                            value))
        : m_value(value)
    {
    }

    template <class T, class O, class D>
    inline XProperty<T, O, D>::operator reference() noexcept
    {
        return m_value;
    }

    template <class T, class O, class D>
    inline XProperty<T, O, D>::operator const_reference() const noexcept
    {
        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator()() noexcept->reference
    {
        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator()() const noexcept->const_reference
    {
        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator()(value_type& arg) && noexcept->xp_owner_type
    {
        m_value = arg;

        return std::move(*owner());
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator()(const value_type& arg) && noexcept->xp_owner_type
    {
        m_value = arg;

        return std::move(*owner());
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator()(value_type&& arg) && noexcept->xp_owner_type
    {
        m_value = std::move(arg);

        return std::move(*owner());
    }

    template <class T, class O, class D>
    template <class Arg1, class Arg2, class... Args>
    inline auto XProperty<T, O, D>::operator()(Arg1&& arg1, Arg2&& arg2, Args&& ... args) && noexcept->xp_owner_type
    {
        m_value = value_type(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Args>(args)...);

        return std::move(*owner());
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator=(value_type& value)->reference
    {
        m_value = owner()->template invoke_validators<xp_derived_type>(value);
        owner()->notify(derived_cast());
        owner()->template invoke_observers<xp_derived_type>();

        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator=(const value_type& value)->reference
    {
        m_value = owner()->template invoke_validators<xp_derived_type>(value);
        owner()->notify(derived_cast());
        owner()->template invoke_observers<xp_derived_type>();

        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::operator=(value_type&& value)->reference
    {
        m_value = owner()->template invoke_validators<xp_derived_type>(std::move(value));
        owner()->notify(derived_cast());
        owner()->template invoke_observers<xp_derived_type>();

        return m_value;
    }

    template <class T, class O, class D>
    template <class V>
    inline auto XProperty<T, O, D>::operator=(V&& value)->reference
    {
        m_value = owner()->template invoke_validators<xp_derived_type>(std::forward<V>(value));
        owner()->notify(derived_cast());
        owner()->template invoke_observers<xp_derived_type>();

        return m_value;
    }

    template <class T, class O, class D>
    inline auto XProperty<T, O, D>::owner() noexcept->xp_owner_type*
    {
        return reinterpret_cast<xp_owner_type*>(reinterpret_cast<char*>(this) - xp_derived_type::offset());
    }
}

#endif

