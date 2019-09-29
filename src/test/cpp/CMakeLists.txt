
add_executable (cfs.osal.test.bin
#add_library(cfs.osal.test
    cfs/osal/Test
    cfs/osal/unitTest
    cfs/osal/TimeFixtureTest
    cfs/osal/log/TestLogger
    cfs/osal/queues/MSPMSConsumerQueueTest
    cfs/osal/MessageTest
    cfs/osal/MessageDataTest
    cfs/osal/FileDescriptorTest
    cfs/osal/MappedMemoryTest
    cfs/osal/MailboxTest
    cfs/osal/BidirectionnalContainerTest

    cfs/osal/thread/WorkerThreadTest
    cfs/osal/SpinLockTest
    cfs/osal/SingletonTest
    cfs/osal/SemaphoreTest
    cfs/osal/MessageQueueTest
    cfs/osal/BinaryWriterTest
    cfs/osal/mocks/SystemCallMock
    cfs/osal/VersionTest
)

apply_style_targets_command(cfs.osal.test.bin ${CMAKE_CURRENT_SOURCE_DIR})

#include(GenerateExportHeader)
#generate_export_header(cfs.osal.test
#    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/cfs/osal/TestExport.hpp"
#    INCLUDE_GUARD_NAME TEST_CFS_OSAL_EXPORT_HPP
#    # EXPORT_MACRO_NAME API_DECLS
#    #BASE_NAME CFS_OSAL
#    #PREFIX_NAME CFS_OSAL_
#    #STATIC_DEFINE BUILT_AS_STATIC
#    DEPRECATED_MACRO_NAME TEST_CFS_OSAL_DEPRECATED
#    ${NO_BUILD_DEPRECATED}
#)

target_include_directories(cfs.osal.test.bin
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

target_link_libraries(cfs.osal.test.bin
    PUBLIC
        cfs.osal.main
        GMock::GMock
        GTest::GTest
)

gtest_discover_tests(cfs.osal.test.bin
    TEST_PREFIX "CFS-OSAL:-: "
    TEST_SUFFIX ----
    PROPERTIES LABELS CFS::OSAL TEST
    DISCOVERY_TIMEOUT
        10
    EXTRA_ARGS
        --iterration 1 --gtest_output=xml:${CMAKE_INSTALL_PREFIX}/qa/tr/cfs-osal-Test-Report.xml
    WORKING_DIRECTORY
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

#add_executable (cfs.osal.test.bin
#    cfs/osal/Test
#    cfs/osal/unitTest
#)

#target_link_libraries(cfs.osal.test.bin
#    PUBLIC
#        cfs.osal.test
#)

#add_dependencies(test-compile cfs.osal.test.bin)
