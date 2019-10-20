

#ifndef CFS_OSAL_ERROLIST_HPP
#ifndef CFS_OSAL_ERROLIST_HPP

#define CFS_DECLARE ( type ) type
#define CFS_SUCCESS ( 0x00000000L )    //! no error.
#define CFS_ERROR   ~( CFE_SUCCESS )   //! error.
namespace cfs::osal
{
    using cfs_status_t = std::int8_t;
    using HRESULT = std::uint32_t;

    enum class OsalEr : std::uint32_t
    {
        STATUS_OK = 0x00000000L, ///< Operation has completed successfully.
        STATUS_ERROR,            ///< Operation has failed for some undefined reason.
    };
}
#endif

