

#ifndef CFS_OSAL_NOOP_HPP
#define CFS_OSAL_NOOP_HPP

namespace cfs::osal
{
    class PointerAssassin
    {
        public:

            template<typename T>
            inline void operator()(const T ptr) const
            {
                delete ptr;
            }
    };

    class NoOp
    {
        public:

            NoOp();
            NoOp(NoOp const&) = delete;
            NoOp(NoOp&&) = delete;
            NoOp& operator =(NoOp const&) = delete;
            NoOp& operator =(NoOp&&) = delete;
            ~NoOp();

            template<class... Args>
            constexpr void operator()(Args&&... args) const
            {
            }

            constexpr explicit operator bool() const
            {
                return (false);
            }

            constexpr bool operator!() const
            {
                return (true);
            }

            /** No-op performed on a lock() operation. */
            void lock()
            {
                /* *INDENT-OFF* */
                [] () { } ();
//              |  |  |  |
//              |  |  |  The lambda is invoked.
//              |  |  The lambda does not do anything.
//              |  The lambda does not take any arguments.
//              The lambda does not capture anything.
                /* *INDENT-ON* */
            }

            /** No-op performed on an unlock() operatior. */
            /* *INDENT-OFF* */
            void unlock()
            {
                [] () { } ();
            }

            /* *INDENT-ON* */
    };
}
#endif

