cmake_minimum_required(VERSION 3.10)

project(timetable_scheduling)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    course.cpp
    instructor.cpp
    possible_combination.cpp
    time_slot.cpp
    university.cpp
    main.cpp
)

add_executable(timetable_scheduling ${SOURCES})

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
