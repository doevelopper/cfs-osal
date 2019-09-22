if(NOT TARGET ${PROJECT_NAME}-${BUILD_TYPE})
    add_custom_target(${PROJECT_NAME}-${BUILD_TYPE}
        COMMAND
            ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ${CMAKE_SOURCE_DIR}
        WORKING_DIRECTORY
            ${CMAKE_SOURCE_DIR}/build-${CMAKE_BUILD_TYPE} #${PROJECT_SOURCE_DIR} vs ${CMAKE_SOURCE_DIR}
        COMMAND
            ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build-${CMAKE_BUILD_TYPE}
        COMMENT
            "Switch CMAKE_BUILD_TYPE to ${BUILD_TYPE}. Building  ${BUILD_TYPE} application"
    )
endif()

# Build goals added hire are an adaptation for maven build licyle
# https://maven.apache.org/guides/introduction/introduction-to-the-lifecycle.html
# common default goals name between maven and make

if(NOT TARGET ${PROJECT_NAME}-pre-clean)
    add_custom_target(pre-clean
        COMMENT "Execute processes needed prior to the actual project cleaning."
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-clean)
    add_custom_target(${PROJECT_NAME}-clean
        COMMENT "Remove all files generated by the previous build."
        DEPENDS ${PROJECT_NAME}-pre-clean
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-post-clean)
    add_custom_target(${PROJECT_NAME}-post-clean
        COMMENT "Execute processes needed to finalize the project cleaning."
        DEPENDS ${PROJECT_NAME}-clean
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-pre-site)
    add_custom_target(${PROJECT_NAME}-pre-site
        COMMENT "Execute processes needed prior to the actual project site generation."
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-site)
    add_custom_target(${PROJECT_NAME}-site
        COMMENT "Generate the project's site documentation."
        DEPENDS ${PROJECT_NAME}-pre-site
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-post-site)
    add_custom_target(${PROJECT_NAME}-post-site
        COMMENT "Execute processes needed to finalize the site generation, and to prepare for site deployment."
        DEPENDS ${PROJECT_NAME}-site
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-site-deploy)
    add_custom_target(${PROJECT_NAME}-site-deploy
        COMMENT "Deploy the generated site documentation to the specified web server."
        DEPENDS ${PROJECT_NAME}-post-site
    )
endif()


if(NOT TARGET ${PROJECT_NAME}-validate)
    add_custom_target(${PROJECT_NAME}-validate
        COMMENT "Validate the project is correct and all necessary information is available."
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-initialize)
    add_custom_target(${PROJECT_NAME}-initialize
        COMMENT "Initialize build state, e.g. set properties or create directories."
        DEPENDS ${PROJECT_NAME}-validate
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-generate-sources)
    add_custom_target(${PROJECT_NAME}-generate-sources
        COMMENT "Generate any source code for inclusion in compilation."
        DEPENDS ${PROJECT_NAME}-initialize
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-sources)
    add_custom_target(${PROJECT_NAME}-process-sources
        COMMENT "Process the source code, for example to filter any values."
        DEPENDS ${PROJECT_NAME}-generate-sources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-generate-resources)
    add_custom_target(${PROJECT_NAME}-generate-resources
        COMMENT "Generate resources for inclusion in the package."
        DEPENDS ${PROJECT_NAME}-process-sources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-resources)
    add_custom_target(${PROJECT_NAME}-process-resources
        COMMENT "Copy and process the resources into the destination directory, ready for packaging."
        DEPENDS ${PROJECT_NAME}-generate-resources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-compile)
    add_custom_target(${PROJECT_NAME}-compile
        COMMENT "Compile the source code of the project."
        DEPENDS ${PROJECT_NAME}-process-resources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-classes)
    add_custom_target(${PROJECT_NAME}-process-classes
        COMMENT "Post-process the generated files from compilation."
        DEPENDS ${PROJECT_NAME}-compile
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-generate-test-sources)
    add_custom_target(${PROJECT_NAME}-generate-test-sources
        COMMENT "Generate any test source code for inclusion in compilation."
        DEPENDS ${PROJECT_NAME}-process-classes
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-test-sources)
    add_custom_target(${PROJECT_NAME}-process-test-sources
        COMMENT "Process the test source code, for example to filter any values."
        DEPENDS ${PROJECT_NAME}-generate-test-sources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-generate-test-resources)
    add_custom_target(${PROJECT_NAME}-generate-test-resources
        COMMENT "Create resources for testing."
        DEPENDS ${PROJECT_NAME}-process-test-sources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-test-resources)
    add_custom_target(${PROJECT_NAME}-process-test-resources
        COMMENT "Copy and process the resources into the test destination directory."
        DEPENDS ${PROJECT_NAME}-generate-test-resources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-test-compile)
    add_custom_target(${PROJECT_NAME}-test-compile
        COMMENT "Compile the test source code into the test destination directory."
        DEPENDS ${PROJECT_NAME}-process-test-resources
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-process-test-classes)
    add_custom_target(${PROJECT_NAME}-process-test-classes
        COMMENT "Post-process the generated files from test compilation."
        DEPENDS ${PROJECT_NAME}-test-compile
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-test)
    add_custom_target(${PROJECT_NAME}-test
        COMMENT "Run tests using a suitable unit testing framework. These tests should not require the code be packaged or deployed."
        DEPENDS ${PROJECT_NAME}-process-test-classes
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-prepare-package)
    add_custom_target(${PROJECT_NAME}-prepare-package
        COMMENT "Perform any operations necessary to prepare a package before the actual packaging."
        DEPENDS ${PROJECT_NAME}-test
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-package)
    add_custom_target(${PROJECT_NAME}-package
        COMMENT "Take the compiled code and package it in its distributable format, such as a ZIP."
        DEPENDS ${PROJECT_NAME}-prepare-package
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-pre-integration-test)
    add_custom_target(${PROJECT_NAME}-pre-integration-test
        COMMENT "Perform actions required before integration tests are executed. This may involve things such as setting up the required environment."
        DEPENDS ${PROJECT_NAME}-package
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-integration-test)
    add_custom_target(${PROJECT_NAME}-integration-test
        COMMENT "Process and deploy the package if necessary into an environment where integration tests can be run."
        DEPENDS ${PROJECT_NAME}-pre-integration-test
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-post-integration-test)
    add_custom_target(${PROJECT_NAME}-post-integration-test
        COMMENT "Perform actions required after integration tests have been executed. This may including cleaning up the environment."
        DEPENDS ${PROJECT_NAME}-integration-test
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-verify)
    add_custom_target(${PROJECT_NAME}-verify
        COMMENT "Rrun any checks to verify the package is valid and meets quality criteria."
        DEPENDS ${PROJECT_NAME}-post-integration-test
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-install)
    add_custom_target(${PROJECT_NAME}-install
        COMMENT "Install the package into the local repository, for use as a dependency in other projects locally."
        DEPENDS ${PROJECT_NAME}-verify
    )
endif()

if(NOT TARGET ${PROJECT_NAME}-deploy)
    add_custom_target(${PROJECT_NAME}-deploy
        COMMENT "Integration or release environment, copies the final package to the remote repository for sharing with other developers and projects."
        DEPENDS ${PROJECT_NAME}-install
    )
endif()

add_custom_target (distclean
    # COMMAND rm -vf ${CMAKE_SOURCE_DIR}/*.log
    # COMMAND rm -vf ${CMAKE_SOURCE_DIR}/Makefile
    # COMMAND rm -vf ${CMAKE_SOURCE_DIR}/install_manifest.txt
    # COMMAND rm -vf ${CMAKE_SOURCE_DIR}/cmake_install.cmake
    # COMMAND find ${CMAKE_SOURCE_DIR} -type f -name CMakeCache.txt | xargs -r rm -vf
    # COMMAND find ${CMAKE_SOURCE_DIR} -type d -name CMakeFiles | xargs -r rm -rvf
    # COMMAND find ${CMAKE_SOURCE_DIR} -type f -name "*.marks" | xargs -r rm -vf
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target rmdotdiles
    COMMAND ${CMAKE_COMMAND} -E remove_directory CMakeFiles
	COMMAND ${CMAKE_COMMAND} -E remove CMakeCache.txt cmake_install.cmake Makefile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
	COMMENT "Cleaning target"
)

add_custom_command(TARGET ${PROJECT_NAME}-process-test-classes
    #COMMAND LD_LIBRARY_PATH=${ROOT_LIBRARY_DIR} ROOTSYS=${ROOTSYS} make
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin/conf
    COMMAND
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin/logs
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different ${PROJECT_SOURCE_DIR}/src/main/resources/configs/log4cxx.xml ${CMAKE_INSTALL_PREFIX}/bin/conf
    COMMENT
        "Copy of files nessesary for application runtime"
)
