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

# Include any dependencies generated for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o: ../glfw-3.3.9/examples/offscreen.c
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/black/coding/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o -MF CMakeFiles/offscreen.dir/offscreen.c.o.d -o CMakeFiles/offscreen.dir/offscreen.c.o -c /home/black/coding/test/glfw-3.3.9/examples/offscreen.c

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/black/coding/test/glfw-3.3.9/examples/offscreen.c > CMakeFiles/offscreen.dir/offscreen.c.i

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/black/coding/test/glfw-3.3.9/examples/offscreen.c -o CMakeFiles/offscreen.dir/offscreen.c.s

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: ../glfw-3.3.9/deps/glad_gl.c
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/black/coding/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o -MF CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o -c /home/black/coding/test/glfw-3.3.9/deps/glad_gl.c

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/black/coding/test/glfw-3.3.9/deps/glad_gl.c > CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/black/coding/test/glfw-3.3.9/deps/glad_gl.c -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.o" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

glfw-3.3.9/examples/offscreen: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.o
glfw-3.3.9/examples/offscreen: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o
glfw-3.3.9/examples/offscreen: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build.make
glfw-3.3.9/examples/offscreen: glfw-3.3.9/src/libglfw3.a
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/librt.a
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/libm.so
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/libwayland-client.so
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/libwayland-cursor.so
glfw-3.3.9/examples/offscreen: /usr/lib/x86_64-linux-gnu/libwayland-egl.so
glfw-3.3.9/examples/offscreen: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/black/coding/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable offscreen"
	cd /home/black/coding/test/build/glfw-3.3.9/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offscreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build: glfw-3.3.9/examples/offscreen
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/clean:
	cd /home/black/coding/test/build/glfw-3.3.9/examples && $(CMAKE_COMMAND) -P CMakeFiles/offscreen.dir/cmake_clean.cmake
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/clean

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend:
	cd /home/black/coding/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/black/coding/test /home/black/coding/test/glfw-3.3.9/examples /home/black/coding/test/build /home/black/coding/test/build/glfw-3.3.9/examples /home/black/coding/test/build/glfw-3.3.9/examples/CMakeFiles/offscreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend

