# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/tamiroffen/Documents/Winter 2020 - Sem 2/Matam/HW/hw3/code_github/FunctionCaller"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/tamiroffen/Documents/Winter 2020 - Sem 2/Matam/HW/hw3/code_github/FunctionCaller"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.19.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.19.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/tamiroffen/Documents/Winter 2020 - Sem 2/Matam/HW/hw3/code_github/FunctionCaller/CMakeFiles" "/Users/tamiroffen/Documents/Winter 2020 - Sem 2/Matam/HW/hw3/code_github/FunctionCaller//CMakeFiles/progress.marks"
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/tamiroffen/Documents/Winter 2020 - Sem 2/Matam/HW/hw3/code_github/FunctionCaller/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ex3

# Build rule for target.
ex3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ex3
.PHONY : ex3

# fast build rule for target.
ex3/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/build
.PHONY : ex3/fast

Part_A/date_wrap.o: Part_A/date_wrap.cpp.o

.PHONY : Part_A/date_wrap.o

# target to build an object file
Part_A/date_wrap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/date_wrap.cpp.o
.PHONY : Part_A/date_wrap.cpp.o

Part_A/date_wrap.i: Part_A/date_wrap.cpp.i

.PHONY : Part_A/date_wrap.i

# target to preprocess a source file
Part_A/date_wrap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/date_wrap.cpp.i
.PHONY : Part_A/date_wrap.cpp.i

Part_A/date_wrap.s: Part_A/date_wrap.cpp.s

.PHONY : Part_A/date_wrap.s

# target to generate assembly for a file
Part_A/date_wrap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/date_wrap.cpp.s
.PHONY : Part_A/date_wrap.cpp.s

Part_A/main.o: Part_A/main.cpp.o

.PHONY : Part_A/main.o

# target to build an object file
Part_A/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/main.cpp.o
.PHONY : Part_A/main.cpp.o

Part_A/main.i: Part_A/main.cpp.i

.PHONY : Part_A/main.i

# target to preprocess a source file
Part_A/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/main.cpp.i
.PHONY : Part_A/main.cpp.i

Part_A/main.s: Part_A/main.cpp.s

.PHONY : Part_A/main.s

# target to generate assembly for a file
Part_A/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/ex3.dir/build.make CMakeFiles/ex3.dir/Part_A/main.cpp.s
.PHONY : Part_A/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ex3"
	@echo "... Part_A/date_wrap.o"
	@echo "... Part_A/date_wrap.i"
	@echo "... Part_A/date_wrap.s"
	@echo "... Part_A/main.o"
	@echo "... Part_A/main.i"
	@echo "... Part_A/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
