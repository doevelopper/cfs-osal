
add_library(cfs.osal.main
    cfs/osal/ResourceLimit
    cfs/osal/ResourceUsage
    cfs/osal/Activator
    cfs/osal/NoOp
    cfs/osal/Serializable
    cfs/osal/BinaryReader
    cfs/osal/BinaryWriter
    cfs/osal/CharacterDevice
    cfs/osal/FileDescriptor
    cfs/osal/Timer
    cfs/osal/TimeFixture
    cfs/osal/task/Runnable
    cfs/osal/Mailbox
    cfs/osal/Semaphore
    cfs/osal/MessageData
    cfs/osal/Semaphore

    #cfs/osal/properties/Connection

    #cfs/osal/cpumanager/Topology
    #cfs/osal/cpumanager/CpuAffinity
    #cfs/osal/cpumanager/CpuInfo
    # cfs/osal/BlockDevice
    # cfs/osal/ByteStream
    # cfs/osal/Comparator
    # cfs/osal/properties/XProperty
    # cfs/osal/thread/WorkerThread
    # cfs/osal/queues/MultiProducerMultiConsumerQueue
    # cfs/osal/queues/SingleProducerSingleConsumerQueue
    # cfs/osal/queues/MultiProducerSingleConsumerQueue
    # cfs/osal/MessageQueue
    # cfs/osal/Object
    # cfs/osal/BidirectionnalContainer
    # cfs/osal/MappedMemory
    # cfs/osal/Singleton
    # cfs/osal/SpinLock
    # cfs/osal/SystemMonitor
    # cfs/osal/BinaryWriter
    # cfs/osal/task/Task
    # cfs/osal/network/IOService
    # cfs/osal/network/Socket
    # cfs/osal/network/serial/Uart
    # cfs/osal/network/i2c/I2c
    # cfs/osal/network/i2s/I2s
    # cfs/osal/network/spi/Spi
    # cfs/osal/network/rpi/RpiUart
    # cfs/osal/network/can/CAN
    ${CMAKE_BINARY_DIR}/cfs/osal/Version
)

apply_style_targets_command (cfs.osal.main ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cfs.osal.main
    PUBLIC
        $<$<PLATFORM_ID:Linux>:rt>
        $<$<PLATFORM_ID:Linux>:pthread>
        LOG4CXX::LOG4CXX
        $<$<CONFIG:Coverage>:${CPP_COVERAGE_FLAGS}>
        #        $<$<OR:$<CXX_COMPILER_ID:Clang>, $<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:${BLD_FLAGS}>
)

#target_link_options(cfs.osal.main
#    PUBLIC
#        -m64
#)

set_target_properties( cfs.osal.main PROPERTIES
    VERSION
        ${PROJECT_VERSION}
    SOVERSION
        "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
)

include(GenerateExportHeader)
generate_export_header(cfs.osal.main
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/cfs/osal/Export.hpp"
    INCLUDE_GUARD_NAME CFS_OSAL_EXPORT_HPP
#    EXPORT_MACRO_NAME CFS_OSAL_API_DECLS
#    BASE_NAME OSAL
#    PREFIX_NAME CFS_
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
        $<$<CXX_COMPILER_ID:GNU>: NOMINMAX>
        # -D_GLIBCXX_SANITIZE_VECTOR
        #QNX POSIX XENOMAI PREEMPT_RT
)

set_target_properties ( cfs.osal.main PROPERTIES LINK_FLAGS -m64 )
#export ASAN_OPTIONS=strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1
target_compile_options(cfs.osal.main
    INTERFACE
        $<$<CONFIG:Debug>:-g3 -O0 -fstack-protector>
        $<$<CONFIG:Release>:-g0 -O2>
        $<$<CXX_COMPILER_ID:GNU>:$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic>>
    PUBLIC
        -m64
        $<$<CXX_COMPILER_ID:GNU>: ${GNU_CXX_FLAGS} -U_FORTIFY_SOURCE -fsanitize-address-use-after-scope>
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
#        $<IF:$<CONFIG:Debug>: helper_debug.cpp,helper_release.cpp>
        $<$<OR:$<CONFIG:Release>,$<CONFIG:Profile>>: DISABLE_VAR>
        $<$<CONFIG:Coverage>: -O0  ${CPP_COVERAGE_FLAGS}>
        $<$<CONFIG:Profile>: ${CHECK_MEMORY_FLAGS}>
)

target_include_directories(cfs.osal.main
    PUBLIC
#        ${CMAKE_BINARY_DIR}/cfs/osal
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/cfs/osal>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<INSTALL_INTERFACE:include/cfs/osal>
        $<INSTALL_INTERFACE:include>

#    SYSTEM
#     PUBLIC
#        ${CMAKE_INSTALL_INCLUDEDIR}/cfs/osal
)

#add_dependencies(compile cfs.osal.main)

# Support find_package(<target> NO_MODULE).
#configure_package_config_file(${MODULE_NAME}-config.cmake.in ${MODULE_NAME_LOWER}-config.cmake
#	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${MODULE_NAME}-${MODULE_VERSION}
#)

#write_basic_package_version_file(${CMAKE_BINARY_DIR}/${MODULE_NAME_LOWER}-config-version.cmake
#	VERSION ${MODULE_VERSION}
#	COMPATIBILITY ExactVersion
#)


# To make the component usable not only from the install directory but also from the build directory
#export(
#    TARGETS .main.bin
#    FILE .main.bin-export.cmake
#)

#install (
#    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cfs/osal
#    DESTIATION ${CMAKE_INSTALL_INCLUDEDIR}
#    FILE_MATCHING PATTERN "*.hpp"
#)

#install( TARGETS
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    ARCHIVES DESTINATION ${CMAKE_INSTALL_LIBDIR}
#)

#install(
#    FILES
#        ${CMAKE_BINARY_DIR}/l101.main-config.cmake
#        ${CMAKE_BINARY_DIR}/l101.main-config-version.cmake
#    DESTINATION
#        ${CMAKE_INSTALL_LIBDIR}/cmake/${MODULE_NAME}-${MODULE_VERSION}
#    COMPONENT
#        development
#)

#install(EXPORT .main
#	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${MODULE_NAME}-${MODULE_VERSION}
#	NAMESPACE ${PROJECT_NAME}::
#	FILE l101.main-export.cmake
#	COMPONENT development
#)

