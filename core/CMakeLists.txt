cmake_minimum_required(VERSION 3.21)

set(LIBRARY_NAME "core")

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

add_library(${LIBRARY_NAME} STATIC
    ${SOURCES}
    ${HEADERS}
)
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${LIBRARY_NAME} PUBLIC
    asio
)

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
