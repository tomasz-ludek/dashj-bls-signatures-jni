# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/osboxes/dev/dashj-bls-signatures-jni

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/osboxes/dev/dashj-bls-signatures-jni

# Include any dependencies generated for this target.
include CMakeFiles/dashjbls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dashjbls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dashjbls.dir/flags.make

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o: CMakeFiles/dashjbls.dir/flags.make
CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o: src/org_dash_bls_DashBlsJni.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/osboxes/dev/dashj-bls-signatures-jni/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o -c /home/osboxes/dev/dashj-bls-signatures-jni/src/org_dash_bls_DashBlsJni.cpp

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/osboxes/dev/dashj-bls-signatures-jni/src/org_dash_bls_DashBlsJni.cpp > CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.i

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/osboxes/dev/dashj-bls-signatures-jni/src/org_dash_bls_DashBlsJni.cpp -o CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.s

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.requires:

.PHONY : CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.requires

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.provides: CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.requires
	$(MAKE) -f CMakeFiles/dashjbls.dir/build.make CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.provides.build
.PHONY : CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.provides

CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.provides.build: CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o


# Object files for target dashjbls
dashjbls_OBJECTS = \
"CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o"

# External object files for target dashjbls
dashjbls_EXTERNAL_OBJECTS =

lib/libdashjbls.so: CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o
lib/libdashjbls.so: CMakeFiles/dashjbls.dir/build.make
lib/libdashjbls.so: src/bls-signatures/build/libbls.a
lib/libdashjbls.so: CMakeFiles/dashjbls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/osboxes/dev/dashj-bls-signatures-jni/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/libdashjbls.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dashjbls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dashjbls.dir/build: lib/libdashjbls.so

.PHONY : CMakeFiles/dashjbls.dir/build

CMakeFiles/dashjbls.dir/requires: CMakeFiles/dashjbls.dir/src/org_dash_bls_DashBlsJni.cpp.o.requires

.PHONY : CMakeFiles/dashjbls.dir/requires

CMakeFiles/dashjbls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dashjbls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dashjbls.dir/clean

CMakeFiles/dashjbls.dir/depend:
	cd /home/osboxes/dev/dashj-bls-signatures-jni && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/osboxes/dev/dashj-bls-signatures-jni /home/osboxes/dev/dashj-bls-signatures-jni /home/osboxes/dev/dashj-bls-signatures-jni /home/osboxes/dev/dashj-bls-signatures-jni /home/osboxes/dev/dashj-bls-signatures-jni/CMakeFiles/dashjbls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dashjbls.dir/depend

