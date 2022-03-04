cmake_minimum_required(VERSION 3.10)

project(Machi_Koro LANGUAGES C VERSION 0.1)

if (WIN32)
    set(CMAKE_GENERATOR MSYS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SRC_FILES src/*.c)
add_executable(Machi_Koro.exe ${SRC_FILES})
target_include_directories(Machi_Koro.exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)