# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linked_list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linked_list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linked_list.dir/flags.make

CMakeFiles/linked_list.dir/src/LinkedList.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/src/LinkedList.cpp.o: /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/LinkedList.cpp
CMakeFiles/linked_list.dir/src/LinkedList.cpp.o: CMakeFiles/linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linked_list.dir/src/LinkedList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linked_list.dir/src/LinkedList.cpp.o -MF CMakeFiles/linked_list.dir/src/LinkedList.cpp.o.d -o CMakeFiles/linked_list.dir/src/LinkedList.cpp.o -c /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/LinkedList.cpp

CMakeFiles/linked_list.dir/src/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/src/LinkedList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/LinkedList.cpp > CMakeFiles/linked_list.dir/src/LinkedList.cpp.i

CMakeFiles/linked_list.dir/src/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/src/LinkedList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/LinkedList.cpp -o CMakeFiles/linked_list.dir/src/LinkedList.cpp.s

CMakeFiles/linked_list.dir/src/main.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/src/main.cpp.o: /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/main.cpp
CMakeFiles/linked_list.dir/src/main.cpp.o: CMakeFiles/linked_list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linked_list.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/linked_list.dir/src/main.cpp.o -MF CMakeFiles/linked_list.dir/src/main.cpp.o.d -o CMakeFiles/linked_list.dir/src/main.cpp.o -c /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/main.cpp

CMakeFiles/linked_list.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/main.cpp > CMakeFiles/linked_list.dir/src/main.cpp.i

CMakeFiles/linked_list.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/src/main.cpp -o CMakeFiles/linked_list.dir/src/main.cpp.s

# Object files for target linked_list
linked_list_OBJECTS = \
"CMakeFiles/linked_list.dir/src/LinkedList.cpp.o" \
"CMakeFiles/linked_list.dir/src/main.cpp.o"

# External object files for target linked_list
linked_list_EXTERNAL_OBJECTS =

linked_list: CMakeFiles/linked_list.dir/src/LinkedList.cpp.o
linked_list: CMakeFiles/linked_list.dir/src/main.cpp.o
linked_list: CMakeFiles/linked_list.dir/build.make
linked_list: CMakeFiles/linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linked_list.dir/build: linked_list
.PHONY : CMakeFiles/linked_list.dir/build

CMakeFiles/linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linked_list.dir/clean

CMakeFiles/linked_list.dir/depend:
	cd /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug /Users/janamohamed/CLionProjects/Data_Structure-linked-list_project/cmake-build-debug/CMakeFiles/linked_list.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/linked_list.dir/depend

