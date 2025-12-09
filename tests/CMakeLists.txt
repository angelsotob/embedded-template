add_executable(test_control
    test_control.c
    mocks/Mockgpio.c
)

target_include_directories(test_control PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    ${PROJECT_SOURCE_DIR}/external/Unity/src
    ${PROJECT_SOURCE_DIR}/external/CMock/src
)

target_link_libraries(test_control
    domain
)

target_sources(test_control PRIVATE
    ${PROJECT_SOURCE_DIR}/external/Unity/src/unity.c
    ${PROJECT_SOURCE_DIR}/external/CMock/src/cmock.c
)
