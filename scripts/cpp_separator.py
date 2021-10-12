import os, sys, glob, shutil
"""
takes string directory path were separation is needed.
On specified directory creates two folders: inc and src.
Every [.c | .cc | cpp] file is moved into src and every
[h | hh | hpp] file is moved to inc
"""
def separate_cpp_with_header(directory):
    files_h = []
    files_c = []
    if not os.path.exists(directory + "/inc/"):
        os.makedirs(directory + "/inc/")
    if not os.path.exists(directory + "/src/"):
        os.makedirs(directory + "/src/")

    for filename in glob.iglob(directory + "/**", recursive=True):
        if not os.path.isfile(filename):
            continue
        if filename.endswith(".c") or filename.endswith(".cpp") or filename.endswith(".cc"):
            files_c.append(filename)
        if filename.endswith(".h") or filename.endswith(".hpp") or filename.endswith(".hh"):
            files_h.append(filename)
    for filename in files_h:
        new_file = filename.replace(directory, directory + "/inc/")
        if not os.path.exists(os.path.dirname(new_file)):
            os.makedirs(os.path.dirname(new_file))
        os.rename(filename, new_file)
    for filename in files_c:
        new_file = filename.replace(directory, directory + "/src/")
        if not os.path.exists(os.path.dirname(new_file)):
            os.makedirs(os.path.dirname(new_file))
        os.rename(filename, new_file)
    for dir in os.listdir(directory):
        if dir == "src" or dir == "inc":
            continue
        shutil.rmtree(directory + "/" + dir)

if __name__ == '__main__':
    separate_cpp_with_header(sys.argv[1])
