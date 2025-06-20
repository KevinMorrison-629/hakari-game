cmake_minimum_required(VERSION 3.20)

set(APPLICATION_NAME "client-gui")

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

# Add ImGui and ImNodes external submodules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external)

add_executable(${APPLICATION_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${SOURCES}
)

message("${CMAKE_TOOLCHAIN_FILE}")

target_link_libraries(${APPLICATION_NAME} PRIVATE
    core
    glfw
    glad::glad
    imgui
)

target_include_directories(${APPLICATION_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/${APPLICATION_NAME}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
)

target_compile_definitions(${APPLICATION_NAME} PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD)