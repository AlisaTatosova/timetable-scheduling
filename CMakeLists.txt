cmake_minimum_required(VERSION 3.10)

project(timetable_scheduling)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    course.cpp
    instructor.cpp
    possible_combination.cpp
    time_slot.cpp
    university.cpp
)

add_library(scheduling_lib STATIC ${SOURCES})

add_executable(timetable_scheduling main.cpp)
target_link_libraries(timetable_scheduling scheduling_lib)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_executable(run_tests tests/test_university.cpp)
target_link_libraries(run_tests scheduling_lib gtest gtest_main)

set(TESTS
    test1.json
    test2.json
    test3.json
    test4.json
    test5.json
)

foreach(file ${TESTS})
    configure_file(${CMAKE_SOURCE_DIR}/tests/${file} ${CMAKE_BINARY_DIR}/tests/${file} COPYONLY)
endforeach()