# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /workspaces/be/lab7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/be/lab7/build

# Include any dependencies generated for this target.
include CMakeFiles/lab5_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab5_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5_exe.dir/flags.make

CMakeFiles/lab5_exe.dir/main.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/main.cpp.o: /workspaces/be/lab7/main.cpp
CMakeFiles/lab5_exe.dir/main.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab5_exe.dir/main.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/main.cpp.o -MF CMakeFiles/lab5_exe.dir/main.cpp.o.d -o CMakeFiles/lab5_exe.dir/main.cpp.o -c /workspaces/be/lab7/main.cpp

CMakeFiles/lab5_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/main.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/main.cpp > CMakeFiles/lab5_exe.dir/main.cpp.i

CMakeFiles/lab5_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/main.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/main.cpp -o CMakeFiles/lab5_exe.dir/main.cpp.s

CMakeFiles/lab5_exe.dir/src/visitor.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/visitor.cpp.o: /workspaces/be/lab7/src/visitor.cpp
CMakeFiles/lab5_exe.dir/src/visitor.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab5_exe.dir/src/visitor.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/visitor.cpp.o -MF CMakeFiles/lab5_exe.dir/src/visitor.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/visitor.cpp.o -c /workspaces/be/lab7/src/visitor.cpp

CMakeFiles/lab5_exe.dir/src/visitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/visitor.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/visitor.cpp > CMakeFiles/lab5_exe.dir/src/visitor.cpp.i

CMakeFiles/lab5_exe.dir/src/visitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/visitor.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/visitor.cpp -o CMakeFiles/lab5_exe.dir/src/visitor.cpp.s

CMakeFiles/lab5_exe.dir/src/factory.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/factory.cpp.o: /workspaces/be/lab7/src/factory.cpp
CMakeFiles/lab5_exe.dir/src/factory.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab5_exe.dir/src/factory.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/factory.cpp.o -MF CMakeFiles/lab5_exe.dir/src/factory.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/factory.cpp.o -c /workspaces/be/lab7/src/factory.cpp

CMakeFiles/lab5_exe.dir/src/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/factory.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/factory.cpp > CMakeFiles/lab5_exe.dir/src/factory.cpp.i

CMakeFiles/lab5_exe.dir/src/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/factory.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/factory.cpp -o CMakeFiles/lab5_exe.dir/src/factory.cpp.s

CMakeFiles/lab5_exe.dir/src/logger.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/logger.cpp.o: /workspaces/be/lab7/src/logger.cpp
CMakeFiles/lab5_exe.dir/src/logger.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab5_exe.dir/src/logger.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/logger.cpp.o -MF CMakeFiles/lab5_exe.dir/src/logger.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/logger.cpp.o -c /workspaces/be/lab7/src/logger.cpp

CMakeFiles/lab5_exe.dir/src/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/logger.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/logger.cpp > CMakeFiles/lab5_exe.dir/src/logger.cpp.i

CMakeFiles/lab5_exe.dir/src/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/logger.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/logger.cpp -o CMakeFiles/lab5_exe.dir/src/logger.cpp.s

CMakeFiles/lab5_exe.dir/src/NPC.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/NPC.cpp.o: /workspaces/be/lab7/src/NPC.cpp
CMakeFiles/lab5_exe.dir/src/NPC.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab5_exe.dir/src/NPC.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/NPC.cpp.o -MF CMakeFiles/lab5_exe.dir/src/NPC.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/NPC.cpp.o -c /workspaces/be/lab7/src/NPC.cpp

CMakeFiles/lab5_exe.dir/src/NPC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/NPC.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/NPC.cpp > CMakeFiles/lab5_exe.dir/src/NPC.cpp.i

CMakeFiles/lab5_exe.dir/src/NPC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/NPC.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/NPC.cpp -o CMakeFiles/lab5_exe.dir/src/NPC.cpp.s

CMakeFiles/lab5_exe.dir/src/orc.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/orc.cpp.o: /workspaces/be/lab7/src/orc.cpp
CMakeFiles/lab5_exe.dir/src/orc.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/lab5_exe.dir/src/orc.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/orc.cpp.o -MF CMakeFiles/lab5_exe.dir/src/orc.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/orc.cpp.o -c /workspaces/be/lab7/src/orc.cpp

CMakeFiles/lab5_exe.dir/src/orc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/orc.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/orc.cpp > CMakeFiles/lab5_exe.dir/src/orc.cpp.i

CMakeFiles/lab5_exe.dir/src/orc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/orc.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/orc.cpp -o CMakeFiles/lab5_exe.dir/src/orc.cpp.s

CMakeFiles/lab5_exe.dir/src/knight.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/knight.cpp.o: /workspaces/be/lab7/src/knight.cpp
CMakeFiles/lab5_exe.dir/src/knight.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/lab5_exe.dir/src/knight.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/knight.cpp.o -MF CMakeFiles/lab5_exe.dir/src/knight.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/knight.cpp.o -c /workspaces/be/lab7/src/knight.cpp

CMakeFiles/lab5_exe.dir/src/knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/knight.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/knight.cpp > CMakeFiles/lab5_exe.dir/src/knight.cpp.i

CMakeFiles/lab5_exe.dir/src/knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/knight.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/knight.cpp -o CMakeFiles/lab5_exe.dir/src/knight.cpp.s

CMakeFiles/lab5_exe.dir/src/bear.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/bear.cpp.o: /workspaces/be/lab7/src/bear.cpp
CMakeFiles/lab5_exe.dir/src/bear.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/lab5_exe.dir/src/bear.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/bear.cpp.o -MF CMakeFiles/lab5_exe.dir/src/bear.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/bear.cpp.o -c /workspaces/be/lab7/src/bear.cpp

CMakeFiles/lab5_exe.dir/src/bear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/bear.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/bear.cpp > CMakeFiles/lab5_exe.dir/src/bear.cpp.i

CMakeFiles/lab5_exe.dir/src/bear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/bear.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/bear.cpp -o CMakeFiles/lab5_exe.dir/src/bear.cpp.s

CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o: CMakeFiles/lab5_exe.dir/flags.make
CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o: /workspaces/be/lab7/src/EventManager.cpp
CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o: CMakeFiles/lab5_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o -MF CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o.d -o CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o -c /workspaces/be/lab7/src/EventManager.cpp

CMakeFiles/lab5_exe.dir/src/EventManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_exe.dir/src/EventManager.cpp.i"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/be/lab7/src/EventManager.cpp > CMakeFiles/lab5_exe.dir/src/EventManager.cpp.i

CMakeFiles/lab5_exe.dir/src/EventManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_exe.dir/src/EventManager.cpp.s"
	/usr/local/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/be/lab7/src/EventManager.cpp -o CMakeFiles/lab5_exe.dir/src/EventManager.cpp.s

# Object files for target lab5_exe
lab5_exe_OBJECTS = \
"CMakeFiles/lab5_exe.dir/main.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/visitor.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/factory.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/logger.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/NPC.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/orc.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/knight.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/bear.cpp.o" \
"CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o"

# External object files for target lab5_exe
lab5_exe_EXTERNAL_OBJECTS =

lab5_exe: CMakeFiles/lab5_exe.dir/main.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/visitor.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/factory.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/logger.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/NPC.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/orc.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/knight.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/bear.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/src/EventManager.cpp.o
lab5_exe: CMakeFiles/lab5_exe.dir/build.make
lab5_exe: CMakeFiles/lab5_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/be/lab7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable lab5_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab5_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5_exe.dir/build: lab5_exe
.PHONY : CMakeFiles/lab5_exe.dir/build

CMakeFiles/lab5_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab5_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab5_exe.dir/clean

CMakeFiles/lab5_exe.dir/depend:
	cd /workspaces/be/lab7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/be/lab7 /workspaces/be/lab7 /workspaces/be/lab7/build /workspaces/be/lab7/build /workspaces/be/lab7/build/CMakeFiles/lab5_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5_exe.dir/depend

