cmake_minimum_required(VERSION 3.23)
project(Wordle)
configure_file(wordList.txt wordList.txt COPYONLY)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wordle main.cpp Wordle.cpp Wordle.h)
