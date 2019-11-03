

#ifndef CFS_OSAL_HELPERS_HPP
#define CFS_OSAL_HELPERS_HPP

#define DECLARE(type)  type

namespace cfs::osal
{
    class Helpers
    {
        public:

            Helpers() = default;
            Helpers(const Helpers&) = default;
            Helpers(Helpers&&) = default;
            Helpers& operator=(const Helpers&) = default;
            Helpers& operator=(Helpers&&) = default;
            virtual ~Helpers() = default;

        private:
    };

    template<class T>
    std::string to_string(const T& value)
    {
        std::ostringstream streamOut;
        streamOut << value;

        return (streamOut.str());
    }
}
#endif

