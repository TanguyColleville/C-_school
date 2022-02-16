# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/colormap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/colormap.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/colormap.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/colormap.dir/flags.make

src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/flags.make
src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o: ../src/HashTableBasedColorMap.cpp
src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o -MF CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o.d -o CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o -c "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/HashTableBasedColorMap.cpp"

src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.i"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/HashTableBasedColorMap.cpp" > CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.i

src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.s"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/HashTableBasedColorMap.cpp" -o CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.s

src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/flags.make
src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o: ../src/ListBasedColorMap.cpp
src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o -MF CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o.d -o CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o -c "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/ListBasedColorMap.cpp"

src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colormap.dir/ListBasedColorMap.cpp.i"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/ListBasedColorMap.cpp" > CMakeFiles/colormap.dir/ListBasedColorMap.cpp.i

src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colormap.dir/ListBasedColorMap.cpp.s"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/ListBasedColorMap.cpp" -o CMakeFiles/colormap.dir/ListBasedColorMap.cpp.s

src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/flags.make
src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o: ../src/TreeBasedColorMap.cpp
src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o -MF CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o.d -o CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o -c "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/TreeBasedColorMap.cpp"

src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.i"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/TreeBasedColorMap.cpp" > CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.i

src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.s"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/TreeBasedColorMap.cpp" -o CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.s

src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/flags.make
src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o: ../src/VectorBasedColorMap.cpp
src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o: src/CMakeFiles/colormap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o -MF CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o.d -o CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o -c "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/VectorBasedColorMap.cpp"

src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.i"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/VectorBasedColorMap.cpp" > CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.i

src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.s"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/VectorBasedColorMap.cpp" -o CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.s

src/CMakeFiles/colormap.dir/rgb.cpp.o: src/CMakeFiles/colormap.dir/flags.make
src/CMakeFiles/colormap.dir/rgb.cpp.o: ../src/rgb.cpp
src/CMakeFiles/colormap.dir/rgb.cpp.o: src/CMakeFiles/colormap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/colormap.dir/rgb.cpp.o"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/colormap.dir/rgb.cpp.o -MF CMakeFiles/colormap.dir/rgb.cpp.o.d -o CMakeFiles/colormap.dir/rgb.cpp.o -c "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/rgb.cpp"

src/CMakeFiles/colormap.dir/rgb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colormap.dir/rgb.cpp.i"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/rgb.cpp" > CMakeFiles/colormap.dir/rgb.cpp.i

src/CMakeFiles/colormap.dir/rgb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colormap.dir/rgb.cpp.s"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src/rgb.cpp" -o CMakeFiles/colormap.dir/rgb.cpp.s

# Object files for target colormap
colormap_OBJECTS = \
"CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o" \
"CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o" \
"CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o" \
"CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o" \
"CMakeFiles/colormap.dir/rgb.cpp.o"

# External object files for target colormap
colormap_EXTERNAL_OBJECTS =

src/libcolormap.dylib: src/CMakeFiles/colormap.dir/HashTableBasedColorMap.cpp.o
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/ListBasedColorMap.cpp.o
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/TreeBasedColorMap.cpp.o
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/VectorBasedColorMap.cpp.o
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/rgb.cpp.o
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/build.make
src/libcolormap.dylib: src/CMakeFiles/colormap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library libcolormap.dylib"
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/colormap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/colormap.dir/build: src/libcolormap.dylib
.PHONY : src/CMakeFiles/colormap.dir/build

src/CMakeFiles/colormap.dir/clean:
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/colormap.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/colormap.dir/clean

src/CMakeFiles/colormap.dir/depend:
	cd "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap" "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/src" "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build" "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src" "/Users/tanguycolleville/Documents/CS_3A/SDI/C++ Advanced/TP5/Colormap/build/src/CMakeFiles/colormap.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/colormap.dir/depend

