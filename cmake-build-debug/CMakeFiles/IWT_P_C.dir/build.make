# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IWT_P_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IWT_P_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IWT_P_C.dir/flags.make

CMakeFiles/IWT_P_C.dir/list.c.o: CMakeFiles/IWT_P_C.dir/flags.make
CMakeFiles/IWT_P_C.dir/list.c.o: ../list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IWT_P_C.dir/list.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IWT_P_C.dir/list.c.o   -c /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/list.c

CMakeFiles/IWT_P_C.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IWT_P_C.dir/list.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/list.c > CMakeFiles/IWT_P_C.dir/list.c.i

CMakeFiles/IWT_P_C.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IWT_P_C.dir/list.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/list.c -o CMakeFiles/IWT_P_C.dir/list.c.s

CMakeFiles/IWT_P_C.dir/list.c.o.requires:

.PHONY : CMakeFiles/IWT_P_C.dir/list.c.o.requires

CMakeFiles/IWT_P_C.dir/list.c.o.provides: CMakeFiles/IWT_P_C.dir/list.c.o.requires
	$(MAKE) -f CMakeFiles/IWT_P_C.dir/build.make CMakeFiles/IWT_P_C.dir/list.c.o.provides.build
.PHONY : CMakeFiles/IWT_P_C.dir/list.c.o.provides

CMakeFiles/IWT_P_C.dir/list.c.o.provides.build: CMakeFiles/IWT_P_C.dir/list.c.o


CMakeFiles/IWT_P_C.dir/main.c.o: CMakeFiles/IWT_P_C.dir/flags.make
CMakeFiles/IWT_P_C.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/IWT_P_C.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/IWT_P_C.dir/main.c.o   -c /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/main.c

CMakeFiles/IWT_P_C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IWT_P_C.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/main.c > CMakeFiles/IWT_P_C.dir/main.c.i

CMakeFiles/IWT_P_C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IWT_P_C.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/main.c -o CMakeFiles/IWT_P_C.dir/main.c.s

CMakeFiles/IWT_P_C.dir/main.c.o.requires:

.PHONY : CMakeFiles/IWT_P_C.dir/main.c.o.requires

CMakeFiles/IWT_P_C.dir/main.c.o.provides: CMakeFiles/IWT_P_C.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/IWT_P_C.dir/build.make CMakeFiles/IWT_P_C.dir/main.c.o.provides.build
.PHONY : CMakeFiles/IWT_P_C.dir/main.c.o.provides

CMakeFiles/IWT_P_C.dir/main.c.o.provides.build: CMakeFiles/IWT_P_C.dir/main.c.o


# Object files for target IWT_P_C
IWT_P_C_OBJECTS = \
"CMakeFiles/IWT_P_C.dir/list.c.o" \
"CMakeFiles/IWT_P_C.dir/main.c.o"

# External object files for target IWT_P_C
IWT_P_C_EXTERNAL_OBJECTS =

IWT_P_C: CMakeFiles/IWT_P_C.dir/list.c.o
IWT_P_C: CMakeFiles/IWT_P_C.dir/main.c.o
IWT_P_C: CMakeFiles/IWT_P_C.dir/build.make
IWT_P_C: CMakeFiles/IWT_P_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable IWT_P_C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IWT_P_C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IWT_P_C.dir/build: IWT_P_C

.PHONY : CMakeFiles/IWT_P_C.dir/build

CMakeFiles/IWT_P_C.dir/requires: CMakeFiles/IWT_P_C.dir/list.c.o.requires
CMakeFiles/IWT_P_C.dir/requires: CMakeFiles/IWT_P_C.dir/main.c.o.requires

.PHONY : CMakeFiles/IWT_P_C.dir/requires

CMakeFiles/IWT_P_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IWT_P_C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IWT_P_C.dir/clean

CMakeFiles/IWT_P_C.dir/depend:
	cd /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug /Users/jeffreyquicken/Documents/Programming/IWT-practicum-C/IWT-P-C/cmake-build-debug/CMakeFiles/IWT_P_C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IWT_P_C.dir/depend

