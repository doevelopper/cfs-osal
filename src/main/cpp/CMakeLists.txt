
add_library(cfs.osal.main
    cfs/osal/TimeFixture
    cfs/osal/task/Runnable
    cfs/osal/properties/XProperty
)

apply_style_targets_command (cfs.osal.main ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cfs.osal.main
    PUBLIC
        LOG4CXX::LOG4CXX
)

include(GenerateExportHeader)
generate_export_header(cfs.osal.main
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/cfs/osal/Export.hpp"
    INCLUDE_GUARD_NAME CFS_OSAL_EXPORT_HPP
    EXPORT_MACRO_NAME API_DECLS
    BASE_NAME cfs-oasl 
    PREFIX_NAME CFS_OSAL_
    STATIC_DEFINE BUILT_AS_STATIC
    DEPRECATED_MACRO_NAME CFS_OSAL_DEPRECATED
    ${NO_BUILD_DEPRECATED}
)

target_compile_features(cfs.osal.main
    PUBLIC
        cxx_std_17
        cxx_strong_enums
        cxx_variadic_templates
        cxx_nullptr
        cxx_alias_templates
        cxx_auto_type
        cxx_constexpr
        cxx_defaulted_functions
        cxx_final
        cxx_lambdas
        cxx_noexcept
        cxx_nullptr
        cxx_rvalue_references
        cxx_thread_local
        cxx_variadic_templates
        cxx_override
    PRIVATE
        cxx_lambdas
        cxx_range_for
        $<$<CXX_COMPILER_ID:GNU>:cxx_attributes>
)

target_compile_definitions(cfs.osal.main
    PRIVATE
        "VERBOSITY=$<IF:$<BOOL:${VERBOSE}>,30,10>"
        $<$<OR:$<CONFIG:Release>,$<CONFIG:Debug>>: -DRELEASE_LEVEL="SNAPSHOOT"> # SNAPSHOOT ,ALPHA , BETA , CANDIDATE , FINAL.
        
)

set_target_properties ( cfs.osal.main PROPERTIES LINK_FLAGS -m64 )

target_compile_options(cfs.osal.main
    INTERFACE
        $<$<CONFIG:Debug>:-g3 -O0 -fstack-protector>
        $<$<CONFIG:Release>:-g0 -O2>
    PUBLIC 
        -m64
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: ${COMMON_CXX_FLAGS}>
        $<IF:$<COMPILE_LANGUAGE:CXX>,-Wold-style-cast,>

        $<$<CONFIG:Release>:${MY_RELEASE_OPTIONS}>
        $<$<CONFIG:Release>:-ffunction-sections>
        $<$<CONFIG:Release>:-fdata-sections>
        $<$<CONFIG:Release>:-Wl,--gc-sections>

        $<$<CONFIG:Debug>: ${MY_DEBUG_OPTIONS}>
        $<$<CONFIG:Debug>: -O0>
        $<$<CONFIG:Debug>: -ggdb3>
        $<$<CONFIG:Debug>: -O0 -g -D_DEBUG -D_FORTIFY_SOURCE=2 -fno-strict-aliasing -fno-omit-frame-pointer>
        
        $<$<OR:$<CONFIG:Release>,$<CONFIG:Profile>>: DISABLE_VAR>
#        $<IF:$<CONFIG:Debug>: helper_debug.cpp,helper_release.cpp>

        $<$<CONFIG:Coverage>: -O0  -fprofile-arcs -ftest-coverage --coverage>

        $<$<CONFIG:Profile>: -fsanitize=memory -fsanitize-memory-track-origins=2 -fno-omit-frame-pointer -fsanitize=null>
        $<$<CONFIG:Profile>: -fsanitize=unreachable -fstack-check -fvtable-verify=std>

)


target_include_directories(cfs.osal.main 
    PUBLIC
         $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cfs/osal>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
         $<INSTALL_INTERFACE:include/cfs/osal>

    SYSTEM 
         PUBLIC
             ${CMAKE_INSTALL_INCLUDEDIR}/cfs/osal
)


