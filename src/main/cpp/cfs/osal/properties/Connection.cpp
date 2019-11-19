

#include <cfs/osal/properties/Connection.hpp>

using namespace cfs::osal::properties;

Connection::Connection()
{
}

Connection::~Connection()
{
}

bool Connection::isConnected() const
{
    if (!d)
    {
        return (false);
    }

    return (d->disconnector ? true : false);
}

void Connection::disConnect()
{
    if (d)
    {
        d->disconnect();
    }
}

void Connection::dispatch(const Dispatcher & dispatcher)
{
    if (d && d->dispatcherInstaller)
    {
        d->dispatcherInstaller(dispatcher);
    }
}

