cmake_minimum_required(VERSION 2.8)

project(FTP)

set(executable_name "FTP")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-std=c++11)
add_definitions(-DFTP_SYST_NAME="${CMAKE_SYSTEM_NAME}")

include_directories(include)

file(
	GLOB_RECURSE
	
	include_files

	include/core/*.h
	include/exception/*.h
	include/network/*.h
	include/system/*.h
)

file(
	GLOB_RECURSE
	
	source_files

	src/core/*.cpp
	src/exception/*.cpp
	src/network/*.cpp
	src/system/*.cpp
)

file(
        GLOB_RECURSE

        test_files

        test/*.cpp
)


find_package(Threads)

configure_file("user.conf" "user.conf" COPYONLY)

add_subdirectory(test)

add_executable(${executable_name} ${include_files} ${source_files} src/main.cpp)
target_link_libraries (${executable_name} ${CMAKE_THREAD_LIBS_INIT})
