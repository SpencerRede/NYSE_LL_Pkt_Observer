# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/spencer/Repositories/NYSE_LL_Pkt_Observer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build

# Include any dependencies generated for this target.
include CMakeFiles/pcap_replay.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pcap_replay.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pcap_replay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pcap_replay.dir/flags.make

CMakeFiles/pcap_replay.dir/codegen:
.PHONY : CMakeFiles/pcap_replay.dir/codegen

CMakeFiles/pcap_replay.dir/src/main.cpp.o: CMakeFiles/pcap_replay.dir/flags.make
CMakeFiles/pcap_replay.dir/src/main.cpp.o: /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/main.cpp
CMakeFiles/pcap_replay.dir/src/main.cpp.o: CMakeFiles/pcap_replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pcap_replay.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_replay.dir/src/main.cpp.o -MF CMakeFiles/pcap_replay.dir/src/main.cpp.o.d -o CMakeFiles/pcap_replay.dir/src/main.cpp.o -c /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/main.cpp

CMakeFiles/pcap_replay.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcap_replay.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/main.cpp > CMakeFiles/pcap_replay.dir/src/main.cpp.i

CMakeFiles/pcap_replay.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcap_replay.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/main.cpp -o CMakeFiles/pcap_replay.dir/src/main.cpp.s

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o: CMakeFiles/pcap_replay.dir/flags.make
CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o: /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Reader.cpp
CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o: CMakeFiles/pcap_replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o -MF CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o.d -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o -c /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Reader.cpp

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Reader.cpp > CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.i

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Reader.cpp -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.s

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o: CMakeFiles/pcap_replay.dir/flags.make
CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o: /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Server.cpp
CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o: CMakeFiles/pcap_replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o -MF CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o.d -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o -c /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Server.cpp

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Server.cpp > CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.i

CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/Server.cpp -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.s

CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o: CMakeFiles/pcap_replay.dir/flags.make
CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o: /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/shared_mutex.cpp
CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o: CMakeFiles/pcap_replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o -MF CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o.d -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o -c /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/shared_mutex.cpp

CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/shared_mutex.cpp > CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.i

CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/PCAP_Server/shared_mutex.cpp -o CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.s

CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o: CMakeFiles/pcap_replay.dir/flags.make
CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o: /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/Pkt_Observer/Ring_Buff_Forwarder.cpp
CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o: CMakeFiles/pcap_replay.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o -MF CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o.d -o CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o -c /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/Pkt_Observer/Ring_Buff_Forwarder.cpp

CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/Pkt_Observer/Ring_Buff_Forwarder.cpp > CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.i

CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/src/Pkt_Observer/Ring_Buff_Forwarder.cpp -o CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.s

# Object files for target pcap_replay
pcap_replay_OBJECTS = \
"CMakeFiles/pcap_replay.dir/src/main.cpp.o" \
"CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o" \
"CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o" \
"CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o" \
"CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o"

# External object files for target pcap_replay
pcap_replay_EXTERNAL_OBJECTS =

pcap_replay: CMakeFiles/pcap_replay.dir/src/main.cpp.o
pcap_replay: CMakeFiles/pcap_replay.dir/src/PCAP_Server/Reader.cpp.o
pcap_replay: CMakeFiles/pcap_replay.dir/src/PCAP_Server/Server.cpp.o
pcap_replay: CMakeFiles/pcap_replay.dir/src/PCAP_Server/shared_mutex.cpp.o
pcap_replay: CMakeFiles/pcap_replay.dir/src/Pkt_Observer/Ring_Buff_Forwarder.cpp.o
pcap_replay: CMakeFiles/pcap_replay.dir/build.make
pcap_replay: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libpcap.tbd
pcap_replay: CMakeFiles/pcap_replay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable pcap_replay"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pcap_replay.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pcap_replay.dir/build: pcap_replay
.PHONY : CMakeFiles/pcap_replay.dir/build

CMakeFiles/pcap_replay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pcap_replay.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pcap_replay.dir/clean

CMakeFiles/pcap_replay.dir/depend:
	cd /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/spencer/Repositories/NYSE_LL_Pkt_Observer /Users/spencer/Repositories/NYSE_LL_Pkt_Observer /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build /Users/spencer/Repositories/NYSE_LL_Pkt_Observer/build/CMakeFiles/pcap_replay.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/pcap_replay.dir/depend

