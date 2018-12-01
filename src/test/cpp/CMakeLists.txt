
add_library(cfs.osal.test
    cfs/osal/Test
    cfs/osal/TimeFixtureTest
#    cfs/osal/log/Logger
#    cfs/osal/log/internal/LoggerPrivate
    cfs/osal/log/TestLogger
)

apply_style_targets_command(cfs.osal.test ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(cfs.osal.test 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cfs/osal>
        $<INSTALL_INTERFACE:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/cfs/osal>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<INSTALL_INTERFACE:include/cfs/osal>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(cfs.osal.test
    PUBLIC  
        cfs.osal.main
#        LOG4CXX::LOG4CXX
        GMock::GMock
        GTest::GTest
)

add_executable (cfs.osal.test.bin
    cfs/osal/unitTest
)

target_link_libraries(cfs.osal.test.bin
    PUBLIC cfs.osal.test
)

