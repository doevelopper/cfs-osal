#ifndef CFS_OSAL_DRIVER_ABSTRACTHWDRIVER_HPP
#define CFS_OSAL_DRIVER_ABSTRACTHWDRIVER_HPP

#include <cfs/osal/driver/HWDriver.hpp>

namespace cfs::osal::driver
{
	  class AbstractHWDriver : public HWDriver
	  {

	  public:
		    AbstractHWDriver();
		    AbstractHWDriver(const AbstractHWDriver&) = delete;
		    AbstractHWDriver(AbstractHWDriver&&) = delete;
		    AbstractHWDriver& operator=(const AbstractHWDriver&) = delete;
		    AbstractHWDriver& operator=(AbstractHWDriver&&) = delete;
				virtual ~AbstractHWDriver();
        //virtual cfs::osal::driver::HWDriver::Promise & send(const cfs::osal::Message & message) override final;

	  protected:
      void txRun();
      void rxRun();
      void error(const std::exception & exception);
	  private:
	};
}
#endif
