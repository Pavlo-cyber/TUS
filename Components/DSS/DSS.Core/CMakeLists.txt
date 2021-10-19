include_guard()

project(DSS.Core)

set(DSS.Core_TARGET DSS.Core)

set(Files "")
find_files(${CMAKE_CURRENT_SOURCE_DIR}/src "*.cpp")

add_library(${DSS.Core_TARGET} SHARED ${Files})

target_include_directories(${DSS.Core_TARGET}
        PUBLIC inc
        PRIVATE src
        PUBLIC $ENV{HOME}/.local/include/jdbc)


# mysql connector
find_library(MYSQLCONNECTOR_LIBRARY NAMES mysqlcppconn REQUIRED)

target_link_libraries(${DSS.Core_TARGET}
        PUBLIC ${MYSQLCONNECTOR_LIBRARY})
