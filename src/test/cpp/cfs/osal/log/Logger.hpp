

#ifndef CFS_OSAL_LOG_LOGGER_LOGGER_HPP
#define CFS_OSAL_LOG_LOGGER_LOGGER_HPP

#include <memory>
#include <string>
#include <cfs/osal/log/internal/LoggerPrivate.hpp>

namespace cfs::osal::log::test
{
    class cfs::osal::log::internal::test::LoggerPrivate;

    class Logger
    {
        public:

            explicit Logger (unsigned long delay);
            virtual ~Logger ( );

            void configure ( );

            [[deprecated("Replaced by LOG4CXX_TRACE macro, which has an improved interface")]]
            void trace ( const std::string & s );
            [[deprecated("Replaced by LOG4CXX_BEBUG, which has an improved interface")]]
            void debug ( const std::string & s );
            [[deprecated("Replaced by LOG4CXX_INFO, which has an improved interface")]]
            void info ( const std::string & s );
            [[deprecated("Replaced by LOG4CXX_WARN, which has an improved interface")]]
            void warn ( const std::string & s );
            [[deprecated("Replaced by LOG4CXX_ERROR, which has an improved interface")]]
            void error ( const std::string & s );
            [[deprecated("Replaced by LOG4CXX_FATAL, which has an improved interface")]]
            void fatal ( const std::string & s );

        protected:

            std::shared_ptr<cfs::osal::log::internal::test::LoggerPrivate> d_ptr;

        private:

            // DECLARE_PRIVATE( Logger )
            // DISABLE_COPY( Logger )
    };
}
#endif

