# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build

# Utility rule file for pio_ws2812_parallel_ws2812_pio_h.

# Include the progress variables for this target.
include CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/progress.make

CMakeFiles/pio_ws2812_parallel_ws2812_pio_h: ../generated/ws2812.pio.h


../generated/ws2812.pio.h: ../ws2812.pio
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../generated/ws2812.pio.h"
	pioasm/pioasm -o c-sdk /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/ws2812.pio /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/generated/ws2812.pio.h

pio_ws2812_parallel_ws2812_pio_h: CMakeFiles/pio_ws2812_parallel_ws2812_pio_h
pio_ws2812_parallel_ws2812_pio_h: ../generated/ws2812.pio.h
pio_ws2812_parallel_ws2812_pio_h: CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/build.make

.PHONY : pio_ws2812_parallel_ws2812_pio_h

# Rule to build all files generated by this target.
CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/build: pio_ws2812_parallel_ws2812_pio_h

.PHONY : CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/build

CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/clean

CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/depend:
	cd /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build /home/arnavgadre/Git-Repos/Lab2b_esp_Arnav/Lab_2B_Parts/Part_3/sequencer_device_keys/build/CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pio_ws2812_parallel_ws2812_pio_h.dir/depend

