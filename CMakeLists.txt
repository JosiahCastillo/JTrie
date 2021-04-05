cmake_minimum_required(VERSION 3.14)
project(JTrie)
set (EXE_NAME JTrie)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_executable(${EXE_NAME} main.cpp JTrie.cpp JTrie.h)