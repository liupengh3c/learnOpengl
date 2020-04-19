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
include shader/CMakeFiles/shader.dir/depend.make

# Include the progress variables for this target.
include shader/CMakeFiles/shader.dir/progress.make

# Include the compile flags for this target's objects.
include shader/CMakeFiles/shader.dir/flags.make

shader/CMakeFiles/shader.dir/shader_base.cc.o: shader/CMakeFiles/shader.dir/flags.make
shader/CMakeFiles/shader.dir/shader_base.cc.o: ../shader/shader_base.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liupeng/study/learnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object shader/CMakeFiles/shader.dir/shader_base.cc.o"
	cd /home/liupeng/study/learnOpengl/build/shader && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shader.dir/shader_base.cc.o -c /home/liupeng/study/learnOpengl/shader/shader_base.cc

shader/CMakeFiles/shader.dir/shader_base.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shader.dir/shader_base.cc.i"
	cd /home/liupeng/study/learnOpengl/build/shader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/liupeng/study/learnOpengl/shader/shader_base.cc > CMakeFiles/shader.dir/shader_base.cc.i

shader/CMakeFiles/shader.dir/shader_base.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shader.dir/shader_base.cc.s"
	cd /home/liupeng/study/learnOpengl/build/shader && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/liupeng/study/learnOpengl/shader/shader_base.cc -o CMakeFiles/shader.dir/shader_base.cc.s

shader/CMakeFiles/shader.dir/shader_base.cc.o.requires:

.PHONY : shader/CMakeFiles/shader.dir/shader_base.cc.o.requires

shader/CMakeFiles/shader.dir/shader_base.cc.o.provides: shader/CMakeFiles/shader.dir/shader_base.cc.o.requires
	$(MAKE) -f shader/CMakeFiles/shader.dir/build.make shader/CMakeFiles/shader.dir/shader_base.cc.o.provides.build
.PHONY : shader/CMakeFiles/shader.dir/shader_base.cc.o.provides

shader/CMakeFiles/shader.dir/shader_base.cc.o.provides.build: shader/CMakeFiles/shader.dir/shader_base.cc.o


# Object files for target shader
shader_OBJECTS = \
"CMakeFiles/shader.dir/shader_base.cc.o"

# External object files for target shader
shader_EXTERNAL_OBJECTS =

shader/libshader.a: shader/CMakeFiles/shader.dir/shader_base.cc.o
shader/libshader.a: shader/CMakeFiles/shader.dir/build.make
shader/libshader.a: shader/CMakeFiles/shader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liupeng/study/learnOpengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libshader.a"
	cd /home/liupeng/study/learnOpengl/build/shader && $(CMAKE_COMMAND) -P CMakeFiles/shader.dir/cmake_clean_target.cmake
	cd /home/liupeng/study/learnOpengl/build/shader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
shader/CMakeFiles/shader.dir/build: shader/libshader.a

.PHONY : shader/CMakeFiles/shader.dir/build

shader/CMakeFiles/shader.dir/requires: shader/CMakeFiles/shader.dir/shader_base.cc.o.requires

.PHONY : shader/CMakeFiles/shader.dir/requires

shader/CMakeFiles/shader.dir/clean:
	cd /home/liupeng/study/learnOpengl/build/shader && $(CMAKE_COMMAND) -P CMakeFiles/shader.dir/cmake_clean.cmake
.PHONY : shader/CMakeFiles/shader.dir/clean

shader/CMakeFiles/shader.dir/depend:
	cd /home/liupeng/study/learnOpengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liupeng/study/learnOpengl /home/liupeng/study/learnOpengl/shader /home/liupeng/study/learnOpengl/build /home/liupeng/study/learnOpengl/build/shader /home/liupeng/study/learnOpengl/build/shader/CMakeFiles/shader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : shader/CMakeFiles/shader.dir/depend

