# Function: find_files
# ========================
# Arguments: <dirPath> - desired path of filesystem inside of which we want to
#            search for files that match given <pattern>
#            <pattern> - specifies what we want to search(i.e: .txt or lib*.so)
# Performs:  Recursively iterates through all files inside <dirPath> and searches for files
#            with specified <pattern>
# Returns:   <Files> - all files that were found
# ========================
function(find_files dirPath pattern)
    set(Files "")
    file(GLOB_RECURSE GR "${dirPath}/" "${dirPath}/${pattern}")
    foreach(elem ${GR})
        list(APPEND Files ${elem})
    endforeach()
    set(Files ${Files} PARENT_SCOPE)
endfunction()

# Function: print_list
# ========================
# Arguments: <list> - list to printed
# Performs:  Prints all elements in list by one elem on one row.
# Returns:
# ========================
function(print_list list)
    foreach(elem ${list})
        message(">>>\t ${elem}")
    endforeach()
endfunction()


# Function: generate_protobuf
# ========================
# Arguments: inputDir    - directory where lies .proto files.
#            outputDir   - directory where *.pb.cc & *.pb.h will be generated.
#            additionalIncludePaths - paths to resolve imports in .proto files.
# Performs: Iterates through every .proto file in <inputDir> and generates
#           *.pb.h and *.pb.cc files into <outputDir>. [*.pb.h] files will be put into
#           inc/ directory, [*.pb.cc] files will be put into src directory
# Returns: GENERATED_SOURCE_FILES - list of all generated source files.
# ========================
function(generate_cpp_proto inputDir outputDir additionalIncludePaths)
    set(GENERATED_SOURCE_FILES "")
    file(GLOB_RECURSE PROTO_FILES ${inputDir} ${inputDir}/*.proto)
    foreach(PROTO_FILE ${PROTO_FILES})
        string(REGEX REPLACE ${inputDir} ${outputDir}/src/ OUTPUT_SOURCE ${PROTO_FILE})
        string(REGEX REPLACE "[.]proto$" ".pb.cc" OUTPUT_SOURCE ${OUTPUT_SOURCE})
        list(APPEND GENERATED_SOURCE_FILES ${OUTPUT_SOURCE})
        string(REGEX REPLACE ".pb.cc" ".grpc.pb.cc" OUTPUT_SOURCE ${OUTPUT_SOURCE})
        list(APPEND GENERATED_SOURCE_FILES ${OUTPUT_SOURCE})

    endforeach()

    set(PROTOC_DIRECTORY --proto_path=${inputDir})
    foreach(includePath ${additionalIncludePaths})
        set(PROTOC_DIRECTORY "${PROTOC_DIRECTORY};--proto_path=${includePath}")
    endforeach()

    # OUTPUT field needed for file indexing(if some was changed or removed, it will invoke procedure again)
    add_custom_command(OUTPUT
            ${GENERATED_SOURCE_FILES}
            COMMAND
            rm -rf ${outputDir}/inc &&
            rm -rf ${outputDir}/src &&
            protoc
            --cpp_out=${outputDir}
            ${PROTOC_DIRECTORY}
            ${PROTO_FILES} &&
            protoc
            --grpc_out=${outputDir}
            ${PROTOC_DIRECTORY}
            --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`
            ${PROTO_FILES} &&
            python3 ${ROOT_DIRECTORY}/scripts/cpp_separator.py ${outputDir}
            DEPENDS ${PROTO_FILES})
    # return source files to caller
    set(GENERATED_SOURCE_FILES ${GENERATED_SOURCE_FILES} PARENT_SCOPE)
endfunction()