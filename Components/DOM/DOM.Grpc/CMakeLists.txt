include_guard()

# project name
project(DOM.Grpc)

# project target (same sa project name, but can be anything)
set(DOM.Grpc_TARGET ${PROJECT_NAME})

# creating necessary directories in case they don't exist
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/gen/cpp)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/gen/js)

# set source
set(SOURCE_FILES "")

# generate cpp protobuf/grpc
generate_cpp_proto(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/gen/cpp)
list(APPEND SOURCE_FILES ${GENERATED_SOURCE_FILES})


add_library(${DOM.Grpc_TARGET} SHARED ${SOURCE_FILES})

# find required dependencies
# protobuf
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf 3.17.3 CONFIG REQUIRED)
set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)

# gRPC
find_package(gRPC 1.41 CONFIG REQUIRED)
set(_GRPC_GRPCPP gRPC::grpc++)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

target_include_directories(${DOM.Grpc_TARGET}
        PUBLIC gen/cpp/inc
        PRIVATE gen/cpp/src)

# link required libs
target_link_libraries(${DOM.Grpc_TARGET}
        PUBLIC ${_REFLECTION}
        PUBLIC ${_GRPC_GRPCPP}
        PUBLIC ${_PROTOBUF_LIBPROTOBUF})