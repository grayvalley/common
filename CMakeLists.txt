cmake_minimum_required(VERSION 3.16)
project(common)

set(CMAKE_CXX_STANDARD 17)


# By specifying INTERFACE as the second parameter to add_library, we are no longer allowed to provide source files
# since the library is not meant to generate any build output.
add_library(common INTERFACE)

# We specify INTERFACE again here so that future targets that link with our library
# will inherit our library's include directory. This is extremely convenient and is the main reason we
# are creating an INTERFACE library.
target_include_directories(common INTERFACE inc/)

add_subdirectory(tests)