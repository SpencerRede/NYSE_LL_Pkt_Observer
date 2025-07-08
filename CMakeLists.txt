cmake_minimum_required(VERSION 3.10)
project(PCAPReplayServer)
set(CMAKE_CXX_STANDARD 17)

find_library(PCAP_LIBRARY pcap REQUIRED PATHS /opt/homebrew/lib)
find_path(PCAP_INCLUDE_DIR pcap.h PATHS /opt/homebrew/include)
include_directories(${PCAP_INCLUDE_DIR})

include_directories(${PCAP_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all .cpp files in src/
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add main.cpp from the project root explicitly as the executable entry point
add_executable(pcap_replay ${CMAKE_SOURCE_DIR}/src/main.cpp ${SRC_FILES})
target_link_libraries(pcap_replay ${PCAP_LIBRARY})

