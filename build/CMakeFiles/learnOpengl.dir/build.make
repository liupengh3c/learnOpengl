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
CMAKE_SOURCE_DIR = /home/liupeng/study/learnOpengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liupeng/study/learnOpengl/build

# Include any dependencies generated for this target.
include CMakeFiles/learnOpengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learnOpengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learnOpengl.dir/flags.make

CMakeFiles/learnOpengl.dir/main.cc.o: CMakeFiles/learnOpengl.dir/flags.make
CMakeFiles/learnOpengl.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liupeng/study/learnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learnOpengl.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learnOpengl.dir/main.cc.o -c /home/liupeng/study/learnOpengl/main.cc

CMakeFiles/learnOpengl.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learnOpengl.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liupeng/study/learnOpengl/main.cc > CMakeFiles/learnOpengl.dir/main.cc.i

CMakeFiles/learnOpengl.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learnOpengl.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liupeng/study/learnOpengl/main.cc -o CMakeFiles/learnOpengl.dir/main.cc.s

CMakeFiles/learnOpengl.dir/main.cc.o.requires:

.PHONY : CMakeFiles/learnOpengl.dir/main.cc.o.requires

CMakeFiles/learnOpengl.dir/main.cc.o.provides: CMakeFiles/learnOpengl.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/learnOpengl.dir/build.make CMakeFiles/learnOpengl.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/learnOpengl.dir/main.cc.o.provides

CMakeFiles/learnOpengl.dir/main.cc.o.provides.build: CMakeFiles/learnOpengl.dir/main.cc.o


# Object files for target learnOpengl
learnOpengl_OBJECTS = \
"CMakeFiles/learnOpengl.dir/main.cc.o"

# External object files for target learnOpengl
learnOpengl_EXTERNAL_OBJECTS =

learnOpengl: CMakeFiles/learnOpengl.dir/main.cc.o
learnOpengl: CMakeFiles/learnOpengl.dir/build.make
learnOpengl: steps/libsteps.a
learnOpengl: libsrc/liblibsrc.a
learnOpengl: shader/libshader.a
learnOpengl: CMakeFiles/learnOpengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liupeng/study/learnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learnOpengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learnOpengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learnOpengl.dir/build: learnOpengl

.PHONY : CMakeFiles/learnOpengl.dir/build

CMakeFiles/learnOpengl.dir/requires: CMakeFiles/learnOpengl.dir/main.cc.o.requires

.PHONY : CMakeFiles/learnOpengl.dir/requires

CMakeFiles/learnOpengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learnOpengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learnOpengl.dir/clean

CMakeFiles/learnOpengl.dir/depend:
	cd /home/liupeng/study/learnOpengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liupeng/study/learnOpengl /home/liupeng/study/learnOpengl /home/liupeng/study/learnOpengl/build /home/liupeng/study/learnOpengl/build /home/liupeng/study/learnOpengl/build/CMakeFiles/learnOpengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learnOpengl.dir/depend

