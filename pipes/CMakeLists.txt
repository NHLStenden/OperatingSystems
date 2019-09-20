set(CMAKE_LEGACY_CYGWIN_WIN32 0)
cmake_minimum_required(VERSION 3.14)
#project(pipes C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES readpipe.c writepipe.c)

#add_executable(pipes ${SOURCE_FILES})
add_executable(readpipe readpipe.c)
add_executable(writepipe writepipe.c)
