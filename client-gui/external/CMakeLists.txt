cmake_minimum_required(VERSION 3.10)

set(IMGUI_SUBMODULE "imgui-submodule")
project(${IMGUI_SUBMODULE} NONE)

set(IMGUI_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/imgui)

file(GLOB IMGUI_SRC
    "${IMGUI_SOURCE_DIR}/*.cpp"
)
set(IMGUI_BACKEND_SRC
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

set(IMGUI_BACKEND_HEADERS
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.h
    ${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.h
)

add_library(${IMGUI_SUBMODULE} STATIC 
    ${IMGUI_SRC}
    ${IMGUI_BACKEND_SRC}
    ${IMGUI_BACKEND_HEADERS}
)

target_include_directories(${IMGUI_SUBMODULE} PUBLIC
    ${IMGUI_SOURCE_DIR}
    ${IMGUI_SOURCE_DIR}/backends
)

target_link_libraries(${IMGUI_SUBMODULE} PUBLIC
    glfw
    OpenGL::GL
)

