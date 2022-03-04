cmake_minimum_required(VERSION 3.10)

project(Machi_Koro VERSION 0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(Machi_Koro.exe ${SRC_FILES})
target_include_directories(Machi_Koro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)