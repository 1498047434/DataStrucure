# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\c++\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\c++\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\c++\Project\DataStrucure\Graph\MinimumSpanTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MinimumSpanTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MinimumSpanTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MinimumSpanTree.dir/flags.make

CMakeFiles/MinimumSpanTree.dir/main.cpp.obj: CMakeFiles/MinimumSpanTree.dir/flags.make
CMakeFiles/MinimumSpanTree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MinimumSpanTree.dir/main.cpp.obj"
	G:\c++\mingw-w64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MinimumSpanTree.dir\main.cpp.obj -c G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\main.cpp

CMakeFiles/MinimumSpanTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MinimumSpanTree.dir/main.cpp.i"
	G:\c++\mingw-w64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\main.cpp > CMakeFiles\MinimumSpanTree.dir\main.cpp.i

CMakeFiles/MinimumSpanTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MinimumSpanTree.dir/main.cpp.s"
	G:\c++\mingw-w64\x86_64-7.3.0-posix-seh-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\main.cpp -o CMakeFiles\MinimumSpanTree.dir\main.cpp.s

# Object files for target MinimumSpanTree
MinimumSpanTree_OBJECTS = \
"CMakeFiles/MinimumSpanTree.dir/main.cpp.obj"

# External object files for target MinimumSpanTree
MinimumSpanTree_EXTERNAL_OBJECTS =

MinimumSpanTree.exe: CMakeFiles/MinimumSpanTree.dir/main.cpp.obj
MinimumSpanTree.exe: CMakeFiles/MinimumSpanTree.dir/build.make
MinimumSpanTree.exe: CMakeFiles/MinimumSpanTree.dir/linklibs.rsp
MinimumSpanTree.exe: CMakeFiles/MinimumSpanTree.dir/objects1.rsp
MinimumSpanTree.exe: CMakeFiles/MinimumSpanTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MinimumSpanTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MinimumSpanTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MinimumSpanTree.dir/build: MinimumSpanTree.exe

.PHONY : CMakeFiles/MinimumSpanTree.dir/build

CMakeFiles/MinimumSpanTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MinimumSpanTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MinimumSpanTree.dir/clean

CMakeFiles/MinimumSpanTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\c++\Project\DataStrucure\Graph\MinimumSpanTree G:\c++\Project\DataStrucure\Graph\MinimumSpanTree G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug G:\c++\Project\DataStrucure\Graph\MinimumSpanTree\cmake-build-debug\CMakeFiles\MinimumSpanTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MinimumSpanTree.dir/depend

