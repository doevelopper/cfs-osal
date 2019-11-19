

#ifndef CFS_OSAL_SERIALIZABLE_HPP
#define CFS_OSAL_SERIALIZABLE_HPP

#include <cfs/osal/Reader.hpp>
#include <cfs/osal/Writer.hpp>

namespace cfs::osal
{
    class Serializable
    {
        public:

            Serializable();
            Serializable(const Serializable&) = delete;
            Serializable(Serializable&&) = delete;
            Serializable& operator=(const Serializable&) = delete;
            Serializable& operator=(Serializable&&) = delete;
            virtual ~Serializable();

            Writer & operator>>(Writer & stream) const
            {
                serialize(stream);

                return(stream);
            }

            Reader & operator<<(Reader & stream)
            {
                deSerialize(stream);

                return(stream);
            }

        protected:

            virtual void serialize(Writer & writer) const = 0;
            virtual void deSerialize(Reader & reader) = 0;

        private:
    };
}

#endif

