project(FuretTP)

set(executable_name "FuretTP")

file(
	GLOBAL_RECURSE
	
	include_files

	include/*.h
)

file(
	GLOBAL_RECURSE
	
	source_files

	src/*.cpp	
)

add_executable(${executable_name} ${include_files} ${source_files})
