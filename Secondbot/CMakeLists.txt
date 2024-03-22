cmake_minimum_required(VERSION 3.16)
project(Demo_Example)

set(TARGET botball_user_program)

find_package(riplib REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC_FILES "src/main.cpp")
add_executable(${TARGET} ${SRC_FILES}
        src/main.cpp
        src/function.cpp)

target_include_directories(${TARGET} PUBLIC include)

target_compile_features(${TARGET} PUBLIC cxx_std_17)
target_compile_options(${TARGET} PRIVATE -O1 -Wall -Wextra)
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

target_link_libraries(${TARGET} PUBLIC rip::riplib Boost::system Threads::Threads ${OpenCV_LIBS})
