add_library(domain
    control.c
)

target_include_directories(domain PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(domain PUBLIC
    hal
)