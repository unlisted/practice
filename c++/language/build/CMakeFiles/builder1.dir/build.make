# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/morgan/work/practice/c++/language

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/morgan/work/practice/c++/language/build

# Include any dependencies generated for this target.
include CMakeFiles/builder1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/builder1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/builder1.dir/flags.make

CMakeFiles/builder1.dir/builder1.cpp.o: CMakeFiles/builder1.dir/flags.make
CMakeFiles/builder1.dir/builder1.cpp.o: ../builder1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morgan/work/practice/c++/language/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/builder1.dir/builder1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/builder1.dir/builder1.cpp.o -c /home/morgan/work/practice/c++/language/builder1.cpp

CMakeFiles/builder1.dir/builder1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/builder1.dir/builder1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/morgan/work/practice/c++/language/builder1.cpp > CMakeFiles/builder1.dir/builder1.cpp.i

CMakeFiles/builder1.dir/builder1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/builder1.dir/builder1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/morgan/work/practice/c++/language/builder1.cpp -o CMakeFiles/builder1.dir/builder1.cpp.s

CMakeFiles/builder1.dir/builder1.cpp.o.requires:

.PHONY : CMakeFiles/builder1.dir/builder1.cpp.o.requires

CMakeFiles/builder1.dir/builder1.cpp.o.provides: CMakeFiles/builder1.dir/builder1.cpp.o.requires
	$(MAKE) -f CMakeFiles/builder1.dir/build.make CMakeFiles/builder1.dir/builder1.cpp.o.provides.build
.PHONY : CMakeFiles/builder1.dir/builder1.cpp.o.provides

CMakeFiles/builder1.dir/builder1.cpp.o.provides.build: CMakeFiles/builder1.dir/builder1.cpp.o


# Object files for target builder1
builder1_OBJECTS = \
"CMakeFiles/builder1.dir/builder1.cpp.o"

# External object files for target builder1
builder1_EXTERNAL_OBJECTS =

builder1: CMakeFiles/builder1.dir/builder1.cpp.o
builder1: CMakeFiles/builder1.dir/build.make
builder1: CMakeFiles/builder1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/morgan/work/practice/c++/language/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable builder1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/builder1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/builder1.dir/build: builder1

.PHONY : CMakeFiles/builder1.dir/build

CMakeFiles/builder1.dir/requires: CMakeFiles/builder1.dir/builder1.cpp.o.requires

.PHONY : CMakeFiles/builder1.dir/requires

CMakeFiles/builder1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/builder1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/builder1.dir/clean

CMakeFiles/builder1.dir/depend:
	cd /home/morgan/work/practice/c++/language/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/morgan/work/practice/c++/language /home/morgan/work/practice/c++/language /home/morgan/work/practice/c++/language/build /home/morgan/work/practice/c++/language/build /home/morgan/work/practice/c++/language/build/CMakeFiles/builder1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/builder1.dir/depend
