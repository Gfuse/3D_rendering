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
CMAKE_SOURCE_DIR = /home/majid/Projects/p_demo_02_3d/3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/majid/Projects/p_demo_02_3d/3d/build

# Utility rule file for demo_3d_autogen.

# Include the progress variables for this target.
include CMakeFiles/demo_3d_autogen.dir/progress.make

CMakeFiles/demo_3d_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/majid/Projects/p_demo_02_3d/3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target demo_3d"
	/usr/bin/cmake -E cmake_autogen /home/majid/Projects/p_demo_02_3d/3d/build/CMakeFiles/demo_3d_autogen.dir Debug

demo_3d_autogen: CMakeFiles/demo_3d_autogen
demo_3d_autogen: CMakeFiles/demo_3d_autogen.dir/build.make

.PHONY : demo_3d_autogen

# Rule to build all files generated by this target.
CMakeFiles/demo_3d_autogen.dir/build: demo_3d_autogen

.PHONY : CMakeFiles/demo_3d_autogen.dir/build

CMakeFiles/demo_3d_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo_3d_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo_3d_autogen.dir/clean

CMakeFiles/demo_3d_autogen.dir/depend:
	cd /home/majid/Projects/p_demo_02_3d/3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/majid/Projects/p_demo_02_3d/3d /home/majid/Projects/p_demo_02_3d/3d /home/majid/Projects/p_demo_02_3d/3d/build /home/majid/Projects/p_demo_02_3d/3d/build /home/majid/Projects/p_demo_02_3d/3d/build/CMakeFiles/demo_3d_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo_3d_autogen.dir/depend

