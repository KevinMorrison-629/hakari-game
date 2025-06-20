cmake_minimum_required(VERSION 3.21)

set(PROJECT_NAME "Hakari")
project(${PROJECT_NAME} LANGUAGES C CXX)

# Compile settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Libraries

# Add core static library
add_subdirectory(core)

# Add subprojects
add_subdirectory(server)
add_subdirectory(client-gui)
add_subdirectory(client-discord)