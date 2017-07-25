cmake_minimum_required(VERSION 3.7)
project(bemp)

add_executable(bemp bemp.cpp)

target_include_directories(bemp PUBLIC
  "include"
)

target_compile_options(bemp PRIVATE -std=gnu++1z -O3)

file(GLOB_RECURSE all_source_files "include/*[ch]pp" "tests-*.cpp")

find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT AND all_source_files)
  message(STATUS "FOUND clang-format.")
  add_custom_target(clang-format ALL ${CLANG_FORMAT} -style=Google -sort-includes -i ${all_source_files})
endif()
