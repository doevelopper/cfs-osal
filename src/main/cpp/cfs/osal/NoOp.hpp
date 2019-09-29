#ifndef CFS_OSAL_NOOP_HPP
#define CFS_OSAL_NOOP_HPP
namespace cfs::osal
{
	class NoOp
	{
	public:
		NoOp() = default;
		NoOp(NoOp const&) = delete;
		NoOp(NoOp&&) = delete;
		NoOp& operator =(NoOp const&) = delete;
		NoOp& operator =(NoOp&&) = delete;
		~NoOp() = default;

		/** No-op performed on a lock() operation. */
		void lock()
		{
            [] () {} () ;
//          |  |  |  |
//          |  |  |  The lambda is invoked.
//          |  |  The lambda does not do anything.
//          |  The lambda does not take any arguments.
//          The lambda does not capture anything.
		}

		/** No-op performed on an unlock() operatior. */
		void unlock()
		{
            [] () {} () ;
		}
	};
}
#endif

