# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\CMake\bin\cmake.exe

# The command to remove a file.
RM = F:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\cpp_workspace\datastructed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\cpp_workspace\datastructed\build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cc.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cc.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cc.obj: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\cpp_workspace\datastructed\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cc.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\main.cc.obj -c F:\cpp_workspace\datastructed\main.cc

CMakeFiles/main.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cc.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\cpp_workspace\datastructed\main.cc > CMakeFiles\main.dir\main.cc.i

CMakeFiles/main.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cc.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\cpp_workspace\datastructed\main.cc -o CMakeFiles\main.dir\main.cc.s

CMakeFiles/main.dir/src/sort.cc.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/sort.cc.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/src/sort.cc.obj: ../src/sort.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\cpp_workspace\datastructed\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/sort.cc.obj"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\main.dir\src\sort.cc.obj -c F:\cpp_workspace\datastructed\src\sort.cc

CMakeFiles/main.dir/src/sort.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/sort.cc.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\cpp_workspace\datastructed\src\sort.cc > CMakeFiles\main.dir\src\sort.cc.i

CMakeFiles/main.dir/src/sort.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/sort.cc.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\cpp_workspace\datastructed\src\sort.cc -o CMakeFiles\main.dir\src\sort.cc.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cc.obj" \
"CMakeFiles/main.dir/src/sort.cc.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

../bin/main.exe: CMakeFiles/main.dir/main.cc.obj
../bin/main.exe: CMakeFiles/main.dir/src/sort.cc.obj
../bin/main.exe: CMakeFiles/main.dir/build.make
../bin/main.exe: CMakeFiles/main.dir/linklibs.rsp
../bin/main.exe: CMakeFiles/main.dir/objects1.rsp
../bin/main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\cpp_workspace\datastructed\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ..\bin\main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: ../bin/main.exe

.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\cpp_workspace\datastructed F:\cpp_workspace\datastructed F:\cpp_workspace\datastructed\build F:\cpp_workspace\datastructed\build F:\cpp_workspace\datastructed\build\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

