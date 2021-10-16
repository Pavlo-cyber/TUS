include_guard()

project(CMS.Core)

set(CMS.Core_TARGET CMS.Core)

find_files(${CMAKE_CURRENT_SOURCE_DIR}/src "*.cpp")
set(SOURCE_FILES "${Files}")

add_library(${CMS.Core_TARGET} SHARED ${SOURCE_FILES})

target_include_directories(${CMS.Core_TARGET}
        PUBLIC inc
        PRIVATE src)

target_link_libraries(${CMS.Core_TARGET}
        PUBLIC CMS.Grpc)