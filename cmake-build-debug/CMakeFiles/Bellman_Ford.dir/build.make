# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = C:\Users\davla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\davla\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\davla\Documents\GitHub\Bellman_Ford

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Bellman_Ford.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Bellman_Ford.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bellman_Ford.dir/flags.make

CMakeFiles/Bellman_Ford.dir/main.cpp.obj: CMakeFiles/Bellman_Ford.dir/flags.make
CMakeFiles/Bellman_Ford.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bellman_Ford.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Bellman_Ford.dir\main.cpp.obj -c C:\Users\davla\Documents\GitHub\Bellman_Ford\main.cpp

CMakeFiles/Bellman_Ford.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bellman_Ford.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\davla\Documents\GitHub\Bellman_Ford\main.cpp > CMakeFiles\Bellman_Ford.dir\main.cpp.i

CMakeFiles/Bellman_Ford.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bellman_Ford.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\davla\Documents\GitHub\Bellman_Ford\main.cpp -o CMakeFiles\Bellman_Ford.dir\main.cpp.s

# Object files for target Bellman_Ford
Bellman_Ford_OBJECTS = \
"CMakeFiles/Bellman_Ford.dir/main.cpp.obj"

# External object files for target Bellman_Ford
Bellman_Ford_EXTERNAL_OBJECTS =

Bellman_Ford.exe: CMakeFiles/Bellman_Ford.dir/main.cpp.obj
Bellman_Ford.exe: CMakeFiles/Bellman_Ford.dir/build.make
Bellman_Ford.exe: CMakeFiles/Bellman_Ford.dir/linklibs.rsp
Bellman_Ford.exe: CMakeFiles/Bellman_Ford.dir/objects1.rsp
Bellman_Ford.exe: CMakeFiles/Bellman_Ford.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Bellman_Ford.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Bellman_Ford.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bellman_Ford.dir/build: Bellman_Ford.exe
.PHONY : CMakeFiles/Bellman_Ford.dir/build

CMakeFiles/Bellman_Ford.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Bellman_Ford.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Bellman_Ford.dir/clean

CMakeFiles/Bellman_Ford.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\davla\Documents\GitHub\Bellman_Ford C:\Users\davla\Documents\GitHub\Bellman_Ford C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug C:\Users\davla\Documents\GitHub\Bellman_Ford\cmake-build-debug\CMakeFiles\Bellman_Ford.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bellman_Ford.dir/depend
