# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/saliy/proga2sem/rgr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saliy/proga2sem/rgr/build

# Include any dependencies generated for this target.
include CMakeFiles/matrix_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/matrix_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix_lib.dir/flags.make

CMakeFiles/matrix_lib.dir/matrix.c.o: CMakeFiles/matrix_lib.dir/flags.make
CMakeFiles/matrix_lib.dir/matrix.c.o: /home/saliy/proga2sem/rgr/matrix.c
CMakeFiles/matrix_lib.dir/matrix.c.o: CMakeFiles/matrix_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saliy/proga2sem/rgr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/matrix_lib.dir/matrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/matrix_lib.dir/matrix.c.o -MF CMakeFiles/matrix_lib.dir/matrix.c.o.d -o CMakeFiles/matrix_lib.dir/matrix.c.o -c /home/saliy/proga2sem/rgr/matrix.c

CMakeFiles/matrix_lib.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/matrix_lib.dir/matrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/saliy/proga2sem/rgr/matrix.c > CMakeFiles/matrix_lib.dir/matrix.c.i

CMakeFiles/matrix_lib.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/matrix_lib.dir/matrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/saliy/proga2sem/rgr/matrix.c -o CMakeFiles/matrix_lib.dir/matrix.c.s

# Object files for target matrix_lib
matrix_lib_OBJECTS = \
"CMakeFiles/matrix_lib.dir/matrix.c.o"

# External object files for target matrix_lib
matrix_lib_EXTERNAL_OBJECTS =

libmatrix_lib.so: CMakeFiles/matrix_lib.dir/matrix.c.o
libmatrix_lib.so: CMakeFiles/matrix_lib.dir/build.make
libmatrix_lib.so: CMakeFiles/matrix_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/saliy/proga2sem/rgr/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libmatrix_lib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix_lib.dir/build: libmatrix_lib.so
.PHONY : CMakeFiles/matrix_lib.dir/build

CMakeFiles/matrix_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix_lib.dir/clean

CMakeFiles/matrix_lib.dir/depend:
	cd /home/saliy/proga2sem/rgr/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saliy/proga2sem/rgr /home/saliy/proga2sem/rgr /home/saliy/proga2sem/rgr/build /home/saliy/proga2sem/rgr/build /home/saliy/proga2sem/rgr/build/CMakeFiles/matrix_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/matrix_lib.dir/depend

