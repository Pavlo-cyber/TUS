cmake_minimum_required(VERSION 3.19)
project(TUS VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ROOT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# include main module functionality
include(CMake/main_module.cmake)

# prevent in-source build
if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(SEND_ERROR "In-source builds are not allowed.")
endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")


add_subdirectory(Components)