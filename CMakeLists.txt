cmake_minimum_required(VERSION 2.8)

project(FuretTP)

set(executable_name "FuretTP")

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

add_executable(${executable_name} ${include_files} ${source_files})
