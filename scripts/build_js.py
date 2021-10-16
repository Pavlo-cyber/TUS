import os
import argparse


def generate_protobuf(inDir, outDir, paths):
    proto_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(inDir) for f in filenames]
    proto_path = " "
    for p in paths:
        if os.path.exists(p):
            proto_path += "--proto_path=" + p + " "
        else:
            raise Exception("Path " + p + " does not exist!")
    command = 'protoc ' + ' --js_out=' + outDir + " --proto_path=" + inDir + " " + proto_path
    for file in proto_files:
        command += ' ' + file
    os.system(command)


def generate_grpc(inDir, outDir, paths):
    proto_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(inDir) for f in filenames]
    proto_path = " "
    for p in paths:
        if os.path.exists(p):
            proto_path += "--proto_path=" + p + " "
        else:
            raise Exception("Path " + p + " does not exist!")
    command = 'protoc ' + ' --grpc_out=' + outDir + " --proto_path=" + inDir + " " + proto_path + \
              " --plugin=protoc-gen-grpc=`which grpc_node_plugin` "
    for file in proto_files:
        command += ' ' + file
    os.system(command)


if __name__ == '__main__':
    # parsing arguments
    parser = argparse.ArgumentParser(description='Building JS with protoc')
    parser.add_argument('--inDir', type=str, help='Input directory where .proto files are lying.')
    parser.add_argument('--outDir', type=str, help='Output directory where files will be generated.')
    parser.add_argument('-path', '--includePaths', type=str, nargs='*',
                        help='Directories where import paths will be resolved', default=[])
    try:
        args = parser.parse_args()

        inputDirectory = args.inDir
        outputDirectory = args.outDir
        includePaths = args.includePaths

        if not os.path.exists(inputDirectory):
            os.makedirs(inputDirectory)
        if not os.path.exists(outputDirectory):
            os.makedirs(outputDirectory)
        generate_protobuf(inputDirectory, outputDirectory, includePaths)
        generate_grpc(inputDirectory, outputDirectory, includePaths)
    except Exception as e:
        print("Exception: ", e)
