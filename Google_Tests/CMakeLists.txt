cmake_minimum_required(VERSION 3.23)
set(CMAKE_OSX_ARCHITECTURES x86_64)

# 'Google_test' is the subproject name
project(Google_Tests)
get_filename_component(DIR_ONE_ABOVE ../ ABSOLUTE)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${DIR_ONE_ABOVE})

configure_file(testWords.txt testWords.txt COPYONLY)

# 'Google_Tests_run' is the target name
add_executable(Google_Tests_run Tests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)
