cmake_minimum_required(VERSION 3.10)

project(IsGotoHarmful)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(hashmap ${SOURCES})

file(GLOB SOURCES_GOTO "src-goto/*.cpp")
add_executable(hashmap-goto ${SOURCES_GOTO})