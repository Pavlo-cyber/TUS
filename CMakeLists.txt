cmake_minimum_required(VERSION 3.19)
project(TUS)

set(CMAKE_CXX_STANDARD 17)


include_directories($ENV{HOME}/.local/include;/usr/local/Cellar)
list(APPEND CMAKE_PREFIX_PATH $ENV{HOME}/.local/lib)

find_package(Boost 1.76.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(TUS main.cpp)