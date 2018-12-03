

set(FEATURE_TEST_FORMAT --format progress)  #--format pretty OR --format pretty --tags @wip OR ...
set(FEATURE_TEST_OPTION --backtrace --format html --color)

add_executable(cfs.osal.it-test.steps
    cfs/osal/features/step_definitions/ApplicationSteps

)

apply_style_targets_command(cfs.osal.it-test.steps ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cfs.osal.it-test.steps
    PUBLIC  
        cfs.osal.main
#        cfs.osal.test
        CUCUMBER-CPP::CUCUMBER-CPP
#        PUBLIC BENCHMARK::BENCHMARK
)

add_custom_target(cfs.osal.integration-test

    COMMAND
        ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/qa/test-result        
    COMMAND
        cfs.osal.it-test.steps --port 3902  >/dev/null &

    COMMAND 
        cucumber ${FEATURE_TEST_FORMAT} ${FEATURE_TEST_OPTION} 
            --out ${CMAKE_INSTALL_PREFIX}/qa/test-result/cfs.osal.test-report.html 
            --strict ${CMAKE_CURRENT_SOURCE_DIR}/cfs/osal/features

    WORKING_DIRECTORY 
        ${CMAKE_CURRENT_SOURCE_DIR}

    COMMENT 
        "Run cfs osal integration test."
)

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

add_custom_command(TARGET cfs.osal.integration-test 
    POST_BUILD
    COMMAND 
        fuser -k -n  tcp 3902 || true # kill -9 *.Seps which is using port 3902
#        # iptables -I INPUT -p tcp --dport 3902 -j DROP ;# need to be root for this command
    COMMENT
        // check pro opened lsof -i -P -n | grep LISTEN 
        "Killing process to close cucumber wire port. (bind: Address already in use)"
)

#add_dependencies( feature-test cfs.osal.integration-test)

