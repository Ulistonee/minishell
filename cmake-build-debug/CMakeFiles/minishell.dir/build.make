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
CMAKE_COMMAND = /snap/clion/158/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/158/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ulistonee/Desktop/minishell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ulistonee/Desktop/minishell/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minishell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minishell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minishell.dir/flags.make

CMakeFiles/minishell.dir/srcs/main.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minishell.dir/srcs/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/main.c.o -c /home/ulistonee/Desktop/minishell/srcs/main.c

CMakeFiles/minishell.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/main.c > CMakeFiles/minishell.dir/srcs/main.c.i

CMakeFiles/minishell.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/main.c -o CMakeFiles/minishell.dir/srcs/main.c.s

CMakeFiles/minishell.dir/srcs/my_echo.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_echo.c.o: ../srcs/my_echo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minishell.dir/srcs/my_echo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_echo.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_echo.c

CMakeFiles/minishell.dir/srcs/my_echo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_echo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_echo.c > CMakeFiles/minishell.dir/srcs/my_echo.c.i

CMakeFiles/minishell.dir/srcs/my_echo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_echo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_echo.c -o CMakeFiles/minishell.dir/srcs/my_echo.c.s

CMakeFiles/minishell.dir/srcs/my_cd.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_cd.c.o: ../srcs/my_cd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minishell.dir/srcs/my_cd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_cd.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_cd.c

CMakeFiles/minishell.dir/srcs/my_cd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_cd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_cd.c > CMakeFiles/minishell.dir/srcs/my_cd.c.i

CMakeFiles/minishell.dir/srcs/my_cd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_cd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_cd.c -o CMakeFiles/minishell.dir/srcs/my_cd.c.s

CMakeFiles/minishell.dir/srcs/my_pwd.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_pwd.c.o: ../srcs/my_pwd.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minishell.dir/srcs/my_pwd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_pwd.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_pwd.c

CMakeFiles/minishell.dir/srcs/my_pwd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_pwd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_pwd.c > CMakeFiles/minishell.dir/srcs/my_pwd.c.i

CMakeFiles/minishell.dir/srcs/my_pwd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_pwd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_pwd.c -o CMakeFiles/minishell.dir/srcs/my_pwd.c.s

CMakeFiles/minishell.dir/srcs/my_export.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_export.c.o: ../srcs/my_export.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minishell.dir/srcs/my_export.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_export.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_export.c

CMakeFiles/minishell.dir/srcs/my_export.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_export.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_export.c > CMakeFiles/minishell.dir/srcs/my_export.c.i

CMakeFiles/minishell.dir/srcs/my_export.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_export.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_export.c -o CMakeFiles/minishell.dir/srcs/my_export.c.s

CMakeFiles/minishell.dir/srcs/my_fork.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_fork.c.o: ../srcs/my_fork.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/minishell.dir/srcs/my_fork.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_fork.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_fork.c

CMakeFiles/minishell.dir/srcs/my_fork.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_fork.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_fork.c > CMakeFiles/minishell.dir/srcs/my_fork.c.i

CMakeFiles/minishell.dir/srcs/my_fork.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_fork.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_fork.c -o CMakeFiles/minishell.dir/srcs/my_fork.c.s

CMakeFiles/minishell.dir/srcs/utils.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/utils.c.o: ../srcs/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/minishell.dir/srcs/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/utils.c.o -c /home/ulistonee/Desktop/minishell/srcs/utils.c

CMakeFiles/minishell.dir/srcs/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/utils.c > CMakeFiles/minishell.dir/srcs/utils.c.i

CMakeFiles/minishell.dir/srcs/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/utils.c -o CMakeFiles/minishell.dir/srcs/utils.c.s

CMakeFiles/minishell.dir/srcs/my_unset.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_unset.c.o: ../srcs/my_unset.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/minishell.dir/srcs/my_unset.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_unset.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_unset.c

CMakeFiles/minishell.dir/srcs/my_unset.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_unset.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_unset.c > CMakeFiles/minishell.dir/srcs/my_unset.c.i

CMakeFiles/minishell.dir/srcs/my_unset.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_unset.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_unset.c -o CMakeFiles/minishell.dir/srcs/my_unset.c.s

CMakeFiles/minishell.dir/srcs/my_env.c.o: CMakeFiles/minishell.dir/flags.make
CMakeFiles/minishell.dir/srcs/my_env.c.o: ../srcs/my_env.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/minishell.dir/srcs/my_env.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minishell.dir/srcs/my_env.c.o -c /home/ulistonee/Desktop/minishell/srcs/my_env.c

CMakeFiles/minishell.dir/srcs/my_env.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minishell.dir/srcs/my_env.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulistonee/Desktop/minishell/srcs/my_env.c > CMakeFiles/minishell.dir/srcs/my_env.c.i

CMakeFiles/minishell.dir/srcs/my_env.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minishell.dir/srcs/my_env.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulistonee/Desktop/minishell/srcs/my_env.c -o CMakeFiles/minishell.dir/srcs/my_env.c.s

# Object files for target minishell
minishell_OBJECTS = \
"CMakeFiles/minishell.dir/srcs/main.c.o" \
"CMakeFiles/minishell.dir/srcs/my_echo.c.o" \
"CMakeFiles/minishell.dir/srcs/my_cd.c.o" \
"CMakeFiles/minishell.dir/srcs/my_pwd.c.o" \
"CMakeFiles/minishell.dir/srcs/my_export.c.o" \
"CMakeFiles/minishell.dir/srcs/my_fork.c.o" \
"CMakeFiles/minishell.dir/srcs/utils.c.o" \
"CMakeFiles/minishell.dir/srcs/my_unset.c.o" \
"CMakeFiles/minishell.dir/srcs/my_env.c.o"

# External object files for target minishell
minishell_EXTERNAL_OBJECTS =

minishell: CMakeFiles/minishell.dir/srcs/main.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_echo.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_cd.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_pwd.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_export.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_fork.c.o
minishell: CMakeFiles/minishell.dir/srcs/utils.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_unset.c.o
minishell: CMakeFiles/minishell.dir/srcs/my_env.c.o
minishell: CMakeFiles/minishell.dir/build.make
minishell: srcs/libft/liblibft.a
minishell: CMakeFiles/minishell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable minishell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minishell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minishell.dir/build: minishell

.PHONY : CMakeFiles/minishell.dir/build

CMakeFiles/minishell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minishell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minishell.dir/clean

CMakeFiles/minishell.dir/depend:
	cd /home/ulistonee/Desktop/minishell/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ulistonee/Desktop/minishell /home/ulistonee/Desktop/minishell /home/ulistonee/Desktop/minishell/cmake-build-debug /home/ulistonee/Desktop/minishell/cmake-build-debug /home/ulistonee/Desktop/minishell/cmake-build-debug/CMakeFiles/minishell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minishell.dir/depend

