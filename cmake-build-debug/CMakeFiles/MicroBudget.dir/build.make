# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/marosm/Downloads/clion-2021.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/marosm/Downloads/clion-2021.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marosm/CLionProjects/MicroBudget

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marosm/CLionProjects/MicroBudget/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MicroBudget.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MicroBudget.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MicroBudget.dir/flags.make

CMakeFiles/MicroBudget.dir/draw.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/draw.c.o: ../draw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MicroBudget.dir/draw.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/draw.c.o -c /home/marosm/CLionProjects/MicroBudget/draw.c

CMakeFiles/MicroBudget.dir/draw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/draw.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/draw.c > CMakeFiles/MicroBudget.dir/draw.c.i

CMakeFiles/MicroBudget.dir/draw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/draw.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/draw.c -o CMakeFiles/MicroBudget.dir/draw.c.s

CMakeFiles/MicroBudget.dir/eventHandler.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/eventHandler.c.o: ../eventHandler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MicroBudget.dir/eventHandler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/eventHandler.c.o -c /home/marosm/CLionProjects/MicroBudget/eventHandler.c

CMakeFiles/MicroBudget.dir/eventHandler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/eventHandler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/eventHandler.c > CMakeFiles/MicroBudget.dir/eventHandler.c.i

CMakeFiles/MicroBudget.dir/eventHandler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/eventHandler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/eventHandler.c -o CMakeFiles/MicroBudget.dir/eventHandler.c.s

CMakeFiles/MicroBudget.dir/graph.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/graph.c.o: ../graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MicroBudget.dir/graph.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/graph.c.o -c /home/marosm/CLionProjects/MicroBudget/graph.c

CMakeFiles/MicroBudget.dir/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/graph.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/graph.c > CMakeFiles/MicroBudget.dir/graph.c.i

CMakeFiles/MicroBudget.dir/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/graph.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/graph.c -o CMakeFiles/MicroBudget.dir/graph.c.s

CMakeFiles/MicroBudget.dir/helper.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/helper.c.o: ../helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MicroBudget.dir/helper.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/helper.c.o -c /home/marosm/CLionProjects/MicroBudget/helper.c

CMakeFiles/MicroBudget.dir/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/helper.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/helper.c > CMakeFiles/MicroBudget.dir/helper.c.i

CMakeFiles/MicroBudget.dir/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/helper.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/helper.c -o CMakeFiles/MicroBudget.dir/helper.c.s

CMakeFiles/MicroBudget.dir/linuxSpecific.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/linuxSpecific.c.o: ../linuxSpecific.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MicroBudget.dir/linuxSpecific.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/linuxSpecific.c.o -c /home/marosm/CLionProjects/MicroBudget/linuxSpecific.c

CMakeFiles/MicroBudget.dir/linuxSpecific.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/linuxSpecific.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/linuxSpecific.c > CMakeFiles/MicroBudget.dir/linuxSpecific.c.i

CMakeFiles/MicroBudget.dir/linuxSpecific.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/linuxSpecific.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/linuxSpecific.c -o CMakeFiles/MicroBudget.dir/linuxSpecific.c.s

CMakeFiles/MicroBudget.dir/main.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MicroBudget.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/main.c.o -c /home/marosm/CLionProjects/MicroBudget/main.c

CMakeFiles/MicroBudget.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/main.c > CMakeFiles/MicroBudget.dir/main.c.i

CMakeFiles/MicroBudget.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/main.c -o CMakeFiles/MicroBudget.dir/main.c.s

CMakeFiles/MicroBudget.dir/pcg_basic.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/pcg_basic.c.o: ../pcg_basic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/MicroBudget.dir/pcg_basic.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/pcg_basic.c.o -c /home/marosm/CLionProjects/MicroBudget/pcg_basic.c

CMakeFiles/MicroBudget.dir/pcg_basic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/pcg_basic.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/pcg_basic.c > CMakeFiles/MicroBudget.dir/pcg_basic.c.i

CMakeFiles/MicroBudget.dir/pcg_basic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/pcg_basic.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/pcg_basic.c -o CMakeFiles/MicroBudget.dir/pcg_basic.c.s

CMakeFiles/MicroBudget.dir/price_gen.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/price_gen.c.o: ../price_gen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/MicroBudget.dir/price_gen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/price_gen.c.o -c /home/marosm/CLionProjects/MicroBudget/price_gen.c

CMakeFiles/MicroBudget.dir/price_gen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/price_gen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/price_gen.c > CMakeFiles/MicroBudget.dir/price_gen.c.i

CMakeFiles/MicroBudget.dir/price_gen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/price_gen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/price_gen.c -o CMakeFiles/MicroBudget.dir/price_gen.c.s

CMakeFiles/MicroBudget.dir/stonks.c.o: CMakeFiles/MicroBudget.dir/flags.make
CMakeFiles/MicroBudget.dir/stonks.c.o: ../stonks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/MicroBudget.dir/stonks.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MicroBudget.dir/stonks.c.o -c /home/marosm/CLionProjects/MicroBudget/stonks.c

CMakeFiles/MicroBudget.dir/stonks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MicroBudget.dir/stonks.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/marosm/CLionProjects/MicroBudget/stonks.c > CMakeFiles/MicroBudget.dir/stonks.c.i

CMakeFiles/MicroBudget.dir/stonks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MicroBudget.dir/stonks.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/marosm/CLionProjects/MicroBudget/stonks.c -o CMakeFiles/MicroBudget.dir/stonks.c.s

# Object files for target MicroBudget
MicroBudget_OBJECTS = \
"CMakeFiles/MicroBudget.dir/draw.c.o" \
"CMakeFiles/MicroBudget.dir/eventHandler.c.o" \
"CMakeFiles/MicroBudget.dir/graph.c.o" \
"CMakeFiles/MicroBudget.dir/helper.c.o" \
"CMakeFiles/MicroBudget.dir/linuxSpecific.c.o" \
"CMakeFiles/MicroBudget.dir/main.c.o" \
"CMakeFiles/MicroBudget.dir/pcg_basic.c.o" \
"CMakeFiles/MicroBudget.dir/price_gen.c.o" \
"CMakeFiles/MicroBudget.dir/stonks.c.o"

# External object files for target MicroBudget
MicroBudget_EXTERNAL_OBJECTS =

MicroBudget: CMakeFiles/MicroBudget.dir/draw.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/eventHandler.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/graph.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/helper.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/linuxSpecific.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/main.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/pcg_basic.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/price_gen.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/stonks.c.o
MicroBudget: CMakeFiles/MicroBudget.dir/build.make
MicroBudget: CMakeFiles/MicroBudget.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable MicroBudget"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MicroBudget.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MicroBudget.dir/build: MicroBudget

.PHONY : CMakeFiles/MicroBudget.dir/build

CMakeFiles/MicroBudget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MicroBudget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MicroBudget.dir/clean

CMakeFiles/MicroBudget.dir/depend:
	cd /home/marosm/CLionProjects/MicroBudget/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marosm/CLionProjects/MicroBudget /home/marosm/CLionProjects/MicroBudget /home/marosm/CLionProjects/MicroBudget/cmake-build-debug /home/marosm/CLionProjects/MicroBudget/cmake-build-debug /home/marosm/CLionProjects/MicroBudget/cmake-build-debug/CMakeFiles/MicroBudget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MicroBudget.dir/depend

