# University Timetabling System

University Timetabling System schedules courses, assigns instructors, and timeslots.The scheduling algorithm must satisfy all hard constraints and as many soft constraints as possible. Note that two timeslots can not be intersected.

## Hard constraints:
Each course must be scheduled exactly once in an available time slot and assigned to an instructor
An instructor can only be assigned to a course if they are available during the corresponding time slot
An instructor cannot be scheduled to teach more than one course in the same time slot

## Soft constraints:
Courses should be scheduled in preferred time slots if possible
Instructors should be assigned to their preferred courses if possible 

# Idea of solution

Firstly, I have done memorization, keeping for each course corresponding possible combination of Course, Instructor, Timeslot, and also score(which in this case is the quantity of soft constraints to satisfy).Then having that, I am trying to collect possile timetable, also preserving the current score for it.And then try other possible combinations and get one with best score.

# Tests

Here you can find test1.json - test5.json files in which are included tests, for testing just load them with function load_state(filename.json).

## Build Instructions

1. **Clone the repository**:
    ```sh
    git clone https://github.com/AlisaTatosova/timetable-scheduling.git
    cd timetable-scheduling
    ```

2. **Create a build directory**:
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the project**:
    ```sh
    cmake ..
    ```

4. **Build the project**:
    ```sh
    cmake --build .
    ```

This will compile the source files and create an executable named `timetable_scheduling`.

## Run the Program

To run the program, execute the following command from the `build` directory:

```sh
./timetable_scheduling

