

#ifndef CFS_OSAL_OBJECT_HPP
#define CFS_OSAL_OBJECT_HPP

#include <cfs/osal/Export.hpp>

namespace cfs::osal
{
    template< class T >
    class CFS_OSAL_MAIN_EXPORT Object //: public std::enable_shared_from_this<Forte::Object>
    {
        public:

            Object( );
            template< typename ... A >
            Object( A & ... a );
            template< typename ... A >
            Object( const A & ... a );
            /*!
             * @brief       Class copy constructor
             * @param       o   Another object to be used as data source for the initialization
             */
            Object( const Object< T > & o );
            /*!
             * @brief       Class move constructor
             * @param       o   Another object to be used as data source for the initialization
             */
            Object( Object< T > && o );

            /*!
             * @brief       Class destructor
             */
            virtual ~Object( void );

            /*!
             * @brief       Assignment operator
             * @param       o   Another object to use as data source
             */
            Object< T > & operator =( Object< T > o );

            /*!
             * @brief           ADL - Swap function for XS::PIMPL::Object
             * @param           o1  The first object to swap
             * @param           o2  The second object to swap
             */
            template< class U >
            friend void swap( Object< U > & o1, Object< U > & o2 );

        private:

            friend T;
            class IMPL;

            /*!
             * @brief       A pointer to the class' private implementation
             */
            IMPL * impl;
    };
}
#endif

