# Librería común para todos los tests: Unity + CMock + dominio

set(TEST_SUPPORT_SOURCES
    ${PROJECT_SOURCE_DIR}/external/Unity/src/unity.c
    ${PROJECT_SOURCE_DIR}/external/CMock/src/cmock.c
)

add_library(test_support STATIC
    ${TEST_SUPPORT_SOURCES}
)

target_include_directories(test_support PUBLIC
    ${PROJECT_SOURCE_DIR}/external/Unity/src
    ${PROJECT_SOURCE_DIR}/external/CMock/src
)

# Los tests necesitan el dominio (que ya depende de hal)
target_link_libraries(test_support PUBLIC
    domain
)

# Pequeño helper para crear tests Unity + CMock
function(add_unity_test NAME)
    add_executable(${NAME} ${ARGN})

    target_link_libraries(${NAME} PRIVATE
        test_support
    )

    target_include_directories(${NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/mocks
    )

    add_test(
        NAME ${NAME}
        COMMAND ${NAME}
    )
endfunction()

# Test actual: test_control
add_unity_test(test_control
    test_control.c
    mocks/Mockgpio.c
)
