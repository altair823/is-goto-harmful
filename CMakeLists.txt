cmake_minimum_required(VERSION 3.10)

project(IsGotoHarmful)

include_directories(include)

file(GLOB SOURCES "src/*.c")
# add_executable(hashmap ${SOURCES})

file(GLOB SOURCES_GOTO "src-goto/*.c")
# add_executable(hashmap-goto ${SOURCES_GOTO})

enable_testing()

add_executable(hashtest tests/hashtest.c ${SOURCES} ${SOURCES_GOTO})
add_executable(maptest tests/maptest.c ${SOURCES} ${SOURCES_GOTO})

add_test(NAME hashtest COMMAND hashtest)
add_test(NAME maptest COMMAND maptest)