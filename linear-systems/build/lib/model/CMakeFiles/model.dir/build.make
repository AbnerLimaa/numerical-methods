# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build

# Include any dependencies generated for this target.
include lib/model/CMakeFiles/model.dir/depend.make

# Include the progress variables for this target.
include lib/model/CMakeFiles/model.dir/progress.make

# Include the compile flags for this target's objects.
include lib/model/CMakeFiles/model.dir/flags.make

lib/model/CMakeFiles/model.dir/methods.c.o: lib/model/CMakeFiles/model.dir/flags.make
lib/model/CMakeFiles/model.dir/methods.c.o: ../lib/model/methods.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/model/CMakeFiles/model.dir/methods.c.o"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/model.dir/methods.c.o   -c /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/methods.c

lib/model/CMakeFiles/model.dir/methods.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/methods.c.i"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/methods.c > CMakeFiles/model.dir/methods.c.i

lib/model/CMakeFiles/model.dir/methods.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/methods.c.s"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/methods.c -o CMakeFiles/model.dir/methods.c.s

lib/model/CMakeFiles/model.dir/methods.c.o.requires:

.PHONY : lib/model/CMakeFiles/model.dir/methods.c.o.requires

lib/model/CMakeFiles/model.dir/methods.c.o.provides: lib/model/CMakeFiles/model.dir/methods.c.o.requires
	$(MAKE) -f lib/model/CMakeFiles/model.dir/build.make lib/model/CMakeFiles/model.dir/methods.c.o.provides.build
.PHONY : lib/model/CMakeFiles/model.dir/methods.c.o.provides

lib/model/CMakeFiles/model.dir/methods.c.o.provides.build: lib/model/CMakeFiles/model.dir/methods.c.o


lib/model/CMakeFiles/model.dir/matrix.c.o: lib/model/CMakeFiles/model.dir/flags.make
lib/model/CMakeFiles/model.dir/matrix.c.o: ../lib/model/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/model/CMakeFiles/model.dir/matrix.c.o"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/model.dir/matrix.c.o   -c /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/matrix.c

lib/model/CMakeFiles/model.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/matrix.c.i"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/matrix.c > CMakeFiles/model.dir/matrix.c.i

lib/model/CMakeFiles/model.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/matrix.c.s"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && /usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model/matrix.c -o CMakeFiles/model.dir/matrix.c.s

lib/model/CMakeFiles/model.dir/matrix.c.o.requires:

.PHONY : lib/model/CMakeFiles/model.dir/matrix.c.o.requires

lib/model/CMakeFiles/model.dir/matrix.c.o.provides: lib/model/CMakeFiles/model.dir/matrix.c.o.requires
	$(MAKE) -f lib/model/CMakeFiles/model.dir/build.make lib/model/CMakeFiles/model.dir/matrix.c.o.provides.build
.PHONY : lib/model/CMakeFiles/model.dir/matrix.c.o.provides

lib/model/CMakeFiles/model.dir/matrix.c.o.provides.build: lib/model/CMakeFiles/model.dir/matrix.c.o


# Object files for target model
model_OBJECTS = \
"CMakeFiles/model.dir/methods.c.o" \
"CMakeFiles/model.dir/matrix.c.o"

# External object files for target model
model_EXTERNAL_OBJECTS =

lib/model/libmodel.a: lib/model/CMakeFiles/model.dir/methods.c.o
lib/model/libmodel.a: lib/model/CMakeFiles/model.dir/matrix.c.o
lib/model/libmodel.a: lib/model/CMakeFiles/model.dir/build.make
lib/model/libmodel.a: lib/model/CMakeFiles/model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libmodel.a"
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && $(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean_target.cmake
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/model/CMakeFiles/model.dir/build: lib/model/libmodel.a

.PHONY : lib/model/CMakeFiles/model.dir/build

lib/model/CMakeFiles/model.dir/requires: lib/model/CMakeFiles/model.dir/methods.c.o.requires
lib/model/CMakeFiles/model.dir/requires: lib/model/CMakeFiles/model.dir/matrix.c.o.requires

.PHONY : lib/model/CMakeFiles/model.dir/requires

lib/model/CMakeFiles/model.dir/clean:
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model && $(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean.cmake
.PHONY : lib/model/CMakeFiles/model.dir/clean

lib/model/CMakeFiles/model.dir/depend:
	cd /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/lib/model /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model /home/abner/Documents/repositorios/ciencia-da-computacao/numerical-methods/linear-systems/build/lib/model/CMakeFiles/model.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/model/CMakeFiles/model.dir/depend

