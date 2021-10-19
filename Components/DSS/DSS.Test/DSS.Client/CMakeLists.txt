include_guard()

project(DSS.Test.Client)

set(DSS.Test.Client_TARGET DSS.Test.Client)

set(Files "")
find_files(${CMAKE_CURRENT_SOURCE_DIR}/src "*.cpp")

add_executable(${DSS.Test.Client_TARGET} ${Files})

target_include_directories(${DSS.Test.Client_TARGET}
        PUBLIC inc
        PRIVATE src)

target_link_libraries(${DSS.Test.Client_TARGET}
        PUBLIC DSS.Core)
