include_guard()

project(CMS.exe)

set(CMS.exe_TARGET CMS.exe)

find_files(${CMAKE_CURRENT_SOURCE_DIR}/src "*.cpp")
set(SOURCE_FILES "${Files}")

add_executable(${CMS.exe_TARGET} ${SOURCE_FILES})

target_include_directories(${CMS.exe_TARGET}
        PUBLIC inc
        PRIVATE src)

target_link_libraries(${CMS.exe_TARGET}
        PUBLIC CMS.Core)