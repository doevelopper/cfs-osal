#ifndef CFS_OSAL_DRIVER_HWDRIVER_HPP
#define CFS_OSAL_DRIVER_HWDRIVER_HPP

#include <future>
#include <cfs/osal/Message.hpp>

namespace cfs::osal::driver
{
	  class HWDriver
	  {

	  public:
        using Promise = std::future<std::uint32_t>;
    	/// Remote device connection state
    		enum class Connection : std::uint8_t
				{
        	Undef,                              ///< Connection is undefined
        	Connected,                          ///< Connection is established
        	Disconnected,                       ///< No connection
        	Connecting,                         ///< Connecting in process
        	Disconnecting                       ///< Disconnection in process
    		};

		    HWDriver()
        {

        }

		    HWDriver(const HWDriver&) = delete;
		    HWDriver(HWDriver&&) = delete;
		    HWDriver& operator=(const HWDriver&) = delete;
		    HWDriver& operator=(HWDriver&&) = delete;
		    virtual ~HWDriver()
        {

        }

        virtual Promise & send(const cfs::osal::Message & message) = 0;
				virtual Connection connectionState() = 0;
				virtual int id() = 0;
				virtual bool start() = 0;
				virtual bool stop() = 0;
				virtual std::string name() const = 0;
	  protected:
	  private:
	};
}
#endif
