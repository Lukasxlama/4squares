cmake_minimum_required(VERSION 3.16)
project(secondBot_Example)

set(CMAKE_CXX_STANDARD 17)

# Find all source files
file(GLOB SRC_FILES
        "src/*.cpp"
)

include_directories(include)

# Logging
find_package(riplib REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

SET(GCC_COVERAGE_COMPILE_FLAGS "-O1 -std=c++17 -Wall -Wextra")
SET(GCC_COVERAGE_LINK_FLAGS "-lboost_system -lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Add source files to executable
add_executable(botball_user_program ${SRC_FILES}
        src/main.cpp
        src/main.h)

# Link libraries
target_link_libraries(botball_user_program PUBLIC rip::riplib)