cmake_minimum_required(VERSION 2.8)

enable_testing()

add_subdirectory(lib/gtest)

include_directories(lib/gtest/include)

add_executable(TestFTPCommands  ${include_files} ${source_files} TestFTPCommands.cpp)
add_test(TestFTPCommands TestFTPCommands)
target_link_libraries(TestFTPCommands gtest ${CMAKE_THREAD_LIBS_INIT})
