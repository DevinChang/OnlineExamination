# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/devinchang/anaconda3/bin/cmake

# The command to remove a file.
RM = /home/devinchang/anaconda3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/devinchang/Code/WritenExamination/DateStructure/Graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devinchang/Code/WritenExamination/DateStructure/Graph

# Include any dependencies generated for this target.
include CMakeFiles/BG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BG.dir/flags.make

CMakeFiles/BG.dir/BinaryGraph.cpp.o: CMakeFiles/BG.dir/flags.make
CMakeFiles/BG.dir/BinaryGraph.cpp.o: BinaryGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devinchang/Code/WritenExamination/DateStructure/Graph/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BG.dir/BinaryGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BG.dir/BinaryGraph.cpp.o -c /home/devinchang/Code/WritenExamination/DateStructure/Graph/BinaryGraph.cpp

CMakeFiles/BG.dir/BinaryGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BG.dir/BinaryGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devinchang/Code/WritenExamination/DateStructure/Graph/BinaryGraph.cpp > CMakeFiles/BG.dir/BinaryGraph.cpp.i

CMakeFiles/BG.dir/BinaryGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BG.dir/BinaryGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devinchang/Code/WritenExamination/DateStructure/Graph/BinaryGraph.cpp -o CMakeFiles/BG.dir/BinaryGraph.cpp.s

# Object files for target BG
BG_OBJECTS = \
"CMakeFiles/BG.dir/BinaryGraph.cpp.o"

# External object files for target BG
BG_EXTERNAL_OBJECTS =

BG: CMakeFiles/BG.dir/BinaryGraph.cpp.o
BG: CMakeFiles/BG.dir/build.make
BG: CMakeFiles/BG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devinchang/Code/WritenExamination/DateStructure/Graph/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BG.dir/build: BG

.PHONY : CMakeFiles/BG.dir/build

CMakeFiles/BG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BG.dir/clean

CMakeFiles/BG.dir/depend:
	cd /home/devinchang/Code/WritenExamination/DateStructure/Graph && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devinchang/Code/WritenExamination/DateStructure/Graph /home/devinchang/Code/WritenExamination/DateStructure/Graph /home/devinchang/Code/WritenExamination/DateStructure/Graph /home/devinchang/Code/WritenExamination/DateStructure/Graph /home/devinchang/Code/WritenExamination/DateStructure/Graph/CMakeFiles/BG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BG.dir/depend

