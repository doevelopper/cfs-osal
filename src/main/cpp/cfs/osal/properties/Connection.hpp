

#ifndef CFS_OSAL_PROPERTIES_CONNECTION_HPP
#define CFS_OSAL_PROPERTIES_CONNECTION_HPP

#include <functional>
#include <memory>
#include <mutex>

namespace cfs::osal::properties
{
    class Connection
    {
        using Disconnector = std::function<void ()>;
        using DispatcherInstaller = std::function<void (const Dispatcher&)>;

        struct Internal
        {
            Internal(const Connection::Disconnector& disconnector
                     , const Connection::DispatcherInstaller& dispatcher_installer)
                : disconnector(disconnector)
                ,dispatcherInstaller(dispatcher_installer)
            {
            }

            void reset()
            {
                std::lock_guard<std::mutex> lg(guard);
                reset();
            }

            void reset()
            {
                static const Connection::Disconnector empty_disconnector{};
                static const Connection::DispatcherInstaller empty_dispatcher_installer{};
                disconnector = empty_disconnector;
                dispatcher_installer = empty_dispatcher_installer;
            }

            void disconnect()
            {
                static const Connection::Disconnector empty_disconnector{};
                std::lock_guard<std::mutex> lg(guard);

                if (disconnector)
                {
                    disconnector();
                    reset();
                }
            }

            std::mutex guard;
            Connection::Disconnector disconnector;
            Connection::DispatcherInstaller dispatcherInstaller;
        };

        public:

            using Dispatcher = std::function<void (const std::function<void ()>&)>;
            Connection();
            Connection(const Connection&) = default;
            Connection(Connection&&) = default;
            Connection& operator=(const Connection&) = default;
            Connection& operator=(Connection&&) = default;
            virtual ~Connection();

            bool isConnected() const;
            void disconnect();
            void dispatch(const Dispatcher & dispatcher);

        protected:

        private:

            std::shared_ptr<Internal> d;
    };
}

#endif

