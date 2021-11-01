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

if(APPLE)
    set(OPENSSL_ROOT_DIR "/usr/local/openssl@1.1")
    set(OPENSSL_CRYPTO_LIBRARY "/usr/local/openssl@1.1/1.1.1l_1/lib/libcrypto.1.1.dylib")
    set(OPENSSL_SSL_LIBRARY "/usr/local/openssl@1.1/1.1.1l_1/lib/libssl.1.1.dylib")
    set( OPENSSL_INCLUDE_DIR /usr/local/openssl@1.1/1.1.1l_1/include)
    find_package(OpenSSL REQUIRED)
    message("----${OPENSSL_LIBRARIES}")
    target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENSSL_LIBRARIES})
endif()


target_link_libraries(${DSS.Core_TARGET}
        PUBLIC ${MYSQLCONNECTOR_LIBRARY})
