# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /home/bigcubecat/Projects/NSU/Re/au

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bigcubecat/Projects/NSU/Re/au/build

# Include any dependencies generated for this target.
include CMakeFiles/au.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/au.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/au.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/au.dir/flags.make

au_autogen/EWIEGA46WW/qrc_res.cpp: /home/bigcubecat/Projects/NSU/Re/au/res.qrc
au_autogen/EWIEGA46WW/qrc_res.cpp: CMakeFiles/au_autogen.dir/AutoRcc_res_EWIEGA46WW_Info.json
au_autogen/EWIEGA46WW/qrc_res.cpp: /home/bigcubecat/Projects/NSU/Re/au/src/assets/au.png
au_autogen/EWIEGA46WW/qrc_res.cpp: /usr/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for res.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles/au_autogen.dir/AutoRcc_res_EWIEGA46WW_Info.json 

CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o: au_autogen/mocs_compilation.cpp
CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o -MF CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/mocs_compilation.cpp

CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/mocs_compilation.cpp > CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.i

CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/mocs_compilation.cpp -o CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.s

CMakeFiles/au.dir/src/main.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/src/main.cpp.o: /home/bigcubecat/Projects/NSU/Re/au/src/main.cpp
CMakeFiles/au.dir/src/main.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/au.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/src/main.cpp.o -MF CMakeFiles/au.dir/src/main.cpp.o.d -o CMakeFiles/au.dir/src/main.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/src/main.cpp

CMakeFiles/au.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/src/main.cpp > CMakeFiles/au.dir/src/main.cpp.i

CMakeFiles/au.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/src/main.cpp -o CMakeFiles/au.dir/src/main.cpp.s

CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o: /home/bigcubecat/Projects/NSU/Re/au/src/mainwindow/mainwindow.cpp
CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o -MF CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o.d -o CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/src/mainwindow/mainwindow.cpp

CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/src/mainwindow/mainwindow.cpp > CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.i

CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/src/mainwindow/mainwindow.cpp -o CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.s

CMakeFiles/au.dir/src/canvas/canvas.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/src/canvas/canvas.cpp.o: /home/bigcubecat/Projects/NSU/Re/au/src/canvas/canvas.cpp
CMakeFiles/au.dir/src/canvas/canvas.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/au.dir/src/canvas/canvas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/src/canvas/canvas.cpp.o -MF CMakeFiles/au.dir/src/canvas/canvas.cpp.o.d -o CMakeFiles/au.dir/src/canvas/canvas.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/src/canvas/canvas.cpp

CMakeFiles/au.dir/src/canvas/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/src/canvas/canvas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/src/canvas/canvas.cpp > CMakeFiles/au.dir/src/canvas/canvas.cpp.i

CMakeFiles/au.dir/src/canvas/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/src/canvas/canvas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/src/canvas/canvas.cpp -o CMakeFiles/au.dir/src/canvas/canvas.cpp.s

CMakeFiles/au.dir/src/simulation/simulation.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/src/simulation/simulation.cpp.o: /home/bigcubecat/Projects/NSU/Re/au/src/simulation/simulation.cpp
CMakeFiles/au.dir/src/simulation/simulation.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/au.dir/src/simulation/simulation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/src/simulation/simulation.cpp.o -MF CMakeFiles/au.dir/src/simulation/simulation.cpp.o.d -o CMakeFiles/au.dir/src/simulation/simulation.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/src/simulation/simulation.cpp

CMakeFiles/au.dir/src/simulation/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/src/simulation/simulation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/src/simulation/simulation.cpp > CMakeFiles/au.dir/src/simulation/simulation.cpp.i

CMakeFiles/au.dir/src/simulation/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/src/simulation/simulation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/src/simulation/simulation.cpp -o CMakeFiles/au.dir/src/simulation/simulation.cpp.s

CMakeFiles/au.dir/src/utils/utils.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/src/utils/utils.cpp.o: /home/bigcubecat/Projects/NSU/Re/au/src/utils/utils.cpp
CMakeFiles/au.dir/src/utils/utils.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/au.dir/src/utils/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/src/utils/utils.cpp.o -MF CMakeFiles/au.dir/src/utils/utils.cpp.o.d -o CMakeFiles/au.dir/src/utils/utils.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/src/utils/utils.cpp

CMakeFiles/au.dir/src/utils/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/src/utils/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/src/utils/utils.cpp > CMakeFiles/au.dir/src/utils/utils.cpp.i

CMakeFiles/au.dir/src/utils/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/src/utils/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/src/utils/utils.cpp -o CMakeFiles/au.dir/src/utils/utils.cpp.s

CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o: CMakeFiles/au.dir/flags.make
CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o: au_autogen/EWIEGA46WW/qrc_res.cpp
CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o: CMakeFiles/au.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o -MF CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o.d -o CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o -c /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/EWIEGA46WW/qrc_res.cpp

CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/EWIEGA46WW/qrc_res.cpp > CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.i

CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bigcubecat/Projects/NSU/Re/au/build/au_autogen/EWIEGA46WW/qrc_res.cpp -o CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.s

# Object files for target au
au_OBJECTS = \
"CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/au.dir/src/main.cpp.o" \
"CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o" \
"CMakeFiles/au.dir/src/canvas/canvas.cpp.o" \
"CMakeFiles/au.dir/src/simulation/simulation.cpp.o" \
"CMakeFiles/au.dir/src/utils/utils.cpp.o" \
"CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o"

# External object files for target au
au_EXTERNAL_OBJECTS =

au: CMakeFiles/au.dir/au_autogen/mocs_compilation.cpp.o
au: CMakeFiles/au.dir/src/main.cpp.o
au: CMakeFiles/au.dir/src/mainwindow/mainwindow.cpp.o
au: CMakeFiles/au.dir/src/canvas/canvas.cpp.o
au: CMakeFiles/au.dir/src/simulation/simulation.cpp.o
au: CMakeFiles/au.dir/src/utils/utils.cpp.o
au: CMakeFiles/au.dir/au_autogen/EWIEGA46WW/qrc_res.cpp.o
au: CMakeFiles/au.dir/build.make
au: /usr/lib/libQt5Widgets.so.5.15.9
au: /usr/lib/libQt5Gui.so.5.15.9
au: /usr/lib/libQt5Core.so.5.15.9
au: CMakeFiles/au.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable au"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/au.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/au.dir/build: au
.PHONY : CMakeFiles/au.dir/build

CMakeFiles/au.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/au.dir/cmake_clean.cmake
.PHONY : CMakeFiles/au.dir/clean

CMakeFiles/au.dir/depend: au_autogen/EWIEGA46WW/qrc_res.cpp
	cd /home/bigcubecat/Projects/NSU/Re/au/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bigcubecat/Projects/NSU/Re/au /home/bigcubecat/Projects/NSU/Re/au /home/bigcubecat/Projects/NSU/Re/au/build /home/bigcubecat/Projects/NSU/Re/au/build /home/bigcubecat/Projects/NSU/Re/au/build/CMakeFiles/au.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/au.dir/depend
