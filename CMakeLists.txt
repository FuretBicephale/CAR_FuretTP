cmake_minimum_required(VERSION 2.8)

project(FuretTP)

set(executable_name "FuretTP")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-std=c++11)

include_directories(include)

file(
	GLOB_RECURSE
	
	include_files

	include/*.h
)

file(
	GLOB_RECURSE
	
	source_files

	src/*.cpp	
)

file(
        GLOB_RECURSE

        tests_files

        tests/*.cpp
)

add_subdirectory(tests)

find_package(Threads)

configure_file("user.conf" "user.conf" COPYONLY)

add_executable(${executable_name} ${include_files} ${source_files})
target_link_libraries (${executable_name} ${CMAKE_THREAD_LIBS_INIT})
