# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/black/coding/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/black/coding/test/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include glfw-3.3.9/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.9/CMakeFiles/uninstall.dir/progress.make

glfw-3.3.9/CMakeFiles/uninstall:
	cd /home/black/coding/test/build/glfw-3.3.9 && /usr/bin/cmake -P /home/black/coding/test/build/glfw-3.3.9/cmake_uninstall.cmake

uninstall: glfw-3.3.9/CMakeFiles/uninstall
uninstall: glfw-3.3.9/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
glfw-3.3.9/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : glfw-3.3.9/CMakeFiles/uninstall.dir/build

glfw-3.3.9/CMakeFiles/uninstall.dir/clean:
	cd /home/black/coding/test/build/glfw-3.3.9 && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : glfw-3.3.9/CMakeFiles/uninstall.dir/clean

glfw-3.3.9/CMakeFiles/uninstall.dir/depend:
	cd /home/black/coding/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/black/coding/test /home/black/coding/test/glfw-3.3.9 /home/black/coding/test/build /home/black/coding/test/build/glfw-3.3.9 /home/black/coding/test/build/glfw-3.3.9/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.3.9/CMakeFiles/uninstall.dir/depend

