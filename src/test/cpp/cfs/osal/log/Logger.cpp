

#include <string>
#include <cfs/osal/log/Logger.hpp>

using namespace cfs::osal::log::test;
using namespace cfs::osal::log::internal::test;

Logger::Logger(unsigned long loggerWatchDelay )
    : d_ptr( new LoggerPrivate(loggerWatchDelay))
{
    //Q_D( Logger );

    // d->loggerSvce = log4cxx::Logger::getLogger (name.toStdString().c_str());
}

Logger::~Logger( )
{
    //Q_D( Logger );
}

void
Logger::configure( )
{
    //::BasicConfigurator::configure();
}

void
Logger::debug( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->debug( s.toStdString( ) );
}

void
Logger::info( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->info( s.toStdString( ) );
}

void
Logger::trace( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->trace( s.toStdString( ) );
}

void
Logger::warn( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->warn( s.toStdString( ) );
}

void
Logger::error( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->error( s.toStdString( ) );
}

void
Logger::fatal( const std::string & s )
{
    // Q_D( Logger );
    // d->loggerSvce->fatal( s.toStdString( ) );
}

