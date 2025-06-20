cmake_minimum_required(VERSION 3.20)

set(APPLICATION_NAME "client-discord")

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

add_executable(${APPLICATION_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${SOURCES}
)

target_link_libraries(${APPLICATION_NAME} PRIVATE
    core
    dpp::dpp
)

target_include_directories(${APPLICATION_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${APPLICATION_NAME}/include
)