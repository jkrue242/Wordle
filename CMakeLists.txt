cmake_minimum_required(VERSION 3.23)

project(Wordle)
configure_file(wordList.txt wordList.txt COPYONLY)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/Google_Tests)
add_executable(Wordle main.cpp Wordle.cpp Wordle.h)

enable_testing()

add_executable(
        ConstructorTest
        Google_Tests/Tests.cpp
)
target_link_libraries(
        ConstructorTest
        Google_Tests
)

include(GoogleTest)
gtest_discover_tests(ConstructorTest)