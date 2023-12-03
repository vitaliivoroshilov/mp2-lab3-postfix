cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME postfix)
project(${PROJECT_NAME})


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

set(PROJECT_LIBRARY "${PROJECT_NAME}")
set(PROJECT_TESTS   "test_${PROJECT_NAME}")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories("${PROJECT_INCLUDE}" gtest)

# BUILD
add_subdirectory(sample)
add_subdirectory(source)
add_subdirectory(gtest)
add_subdirectory(test)