

set(FEATURE_TEST_FORMAT --format progress)  #--format pretty OR --format pretty --tags @wip OR ...
set(FEATURE_TEST_OPTION --backtrace --format html --color)

add_executable (${PROJECT_NAME}.integration-test)

target_sources(${PROJECT_NAME}.integration-test
    PRIVATE
        cfs/osal/features/step_definitions/ApplicationSteps
)

apply_style_targets_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}.integration-test
    PUBLIC
        ${PROJECT_NAME}.main
#        cfs.osal.test
        CucumberCpp::cucumber-cpp
#        PUBLIC BENCHMARK::BENCHMARK
)

add_feature_test_command(${PROJECT_NAME}.integration-test ${CMAKE_CURRENT_SOURCE_DIR})

#add_custom_target(${PROJECT_NAME}.integration-test
#    COMMAND
#        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/qa/atp
#    COMMAND
#        ${PROJECT_NAME}.integration-test --port 3902  >/dev/null &

#    COMMAND
#        cucumber ${FEATURE_TEST_FORMAT} ${FEATURE_TEST_OPTION}
#            --out ${CMAKE_INSTALL_PREFIX}/qa/atp/cfs.osal.feature-tests-report.html
#            --strict ${CMAKE_CURRENT_SOURCE_DIR}/features

#    WORKING_DIRECTORY
#        ${CMAKE_CURRENT_SOURCE_DIR}

#    COMMENT
#        "Run cfs osal integration test."
#)

#add_custom_command(TARGET cfs.osal.integration-test
#    PRE_BUILD
#    COMMAND
#        cfs.osal.it-test.steps --port 3902  >/dev/null &
#    WORKING_DIRECTORY
#        ${CMAKE_CURRENT_SOURCE_DIR}
#    WORKING_DIRECTORY
#        ${CMAKE_CURRENT_SOURCE_DIR}
#    COMMENT
#        "Start cucumber's wire server on port 3902."
#)

#add_custom_command(TARGET cfs.osal.integration-test
#    POST_BUILD
#    COMMAND
#        kill -9 $(lsof -t -i:3902 -sTCP:LISTEN)  ## best
#        fuser -k -n  tcp 3902 || true # kill -9 *.Seps which is using port 3902
#        iptables -I INPUT -p tcp --dport 3902 -j DROP ;# need to be root for this command
#    COMMENT
#         #// check pro opened lsof -i -P -n | grep LISTEN
#        "Killing process to close cucumber wire port. (bind: Address already in use)"
#)

#add_dependencies( integration-test ${PROJECT_NAME}.integration-test unit-test)
add_dependencies( integration-test ${PROJECT_NAME}.integration-test)

