import os


def generate_protobuf(inDir, outDir):
    proto_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(inDir) for f in filenames]
    command = 'protoc -I ' + inDir + ' --js_out=' + outDir + " --proto_path=" + inDir + ' '
    for file in proto_files:
        command += ' ' + file
    os.system(command)


def generate_grpc(inDir, outDir):
    proto_files = [os.path.join(dp, f) for dp, dn, filenames in os.walk(inDir) for f in filenames]
    command = 'protoc -I ' + inDir + ' --grpc_out=' + outDir + " --proto_path=" + inDir + \
              " --plugin=protoc-gen-grpc=`which grpc_node_plugin` "
    for file in proto_files:
        command += ' ' + file
    os.system(command)


if __name__ == '__main__':
    inputDirectory = '/home/ivan/TUS/Components/DOM/DOM.Grpc/src'
    outputDirectory = '/home/ivan/TUS/Components/DOM/DOM.Grpc/gen/js'
    if not os.path.exists(inputDirectory):
        os.makedirs(inputDirectory)
    if not os.path.exists(outputDirectory):
        os.makedirs(outputDirectory)
    generate_protobuf(inputDirectory, outputDirectory)
    generate_grpc(inputDirectory, outputDirectory)
