#ifndef CFS_OSAL_SERIALIZABLE_HPP
#define CFS_OSAL_SERIALIZABLE_HPP

#include <cfs/osal/Reader.hpp>
#include <cfs/osal/Writer.hpp>

namespace cfs::osal
{
    class Serializable
    {
    public:
        Serializable(const Serializable&) = default;
        Serializable(Serializable&&) = default;
        Serializable& operator=(const Serializable&) = default;
        Serializable& operator=(Serializable&&) = default;
        virtual ~Serializable() = default;
        virtual void serialize(Writer & writer) const = 0;
        virtual void deserialize(Reader & reader) = 0;
    protected:
    private:
    };
}

#endif
