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

## Build Instructions

1. **Clone the repository**:
    ```sh
    git clone https://github.com/AlisaTatosova/timetable-scheduling.git
    cd timetable-scheduling
    git submodule update --init --recursive
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

This will compile the source files and create an executable named `timetable_scheduling` and `run_tests`.

## Run the Program

To run the tests, execute the following command from the `build` directory:

```sh
./run_tests
```

To run the program, execute the following command from the `build` directory:

```sh
./timetable_scheduling
```

## Tests

### test1.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
- **Tuesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
- **Thursday:**
  - 09:00 - 10:35

#### Courses
The courses and their preferred time slots are listed below:
- **Math:** Monday 09:00 - 10:35, Monday 10:45 - 12:20
- **Physics:** Tuesday 09:00 - 10:35, Tuesday 10:45 - 12:20
- **Chemistry:** Monday 12:50 - 14:20, Tuesday 12:50 - 14:20
- **Biology:** Wednesday 09:00 - 10:35
- **Computer Science:** Wednesday 10:45 - 12:20
- **History:** Thursday 09:00 - 10:35
- **Philosophy:** Monday 09:00 - 10:35, Wednesday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Smith:**
  - Available: Monday 09:00 - 10:35
  - Preferred Course: Math
- **Dr. Johnson:**
  - Available: Tuesday 09:00 - 10:35
  - Preferred Course: Physics
- **Dr. Lee:**
  - Available: Monday 12:50 - 14:20, Tuesday 12:50 - 14:20
  - Preferred Course: Computer Science
- **Dr. Brown:**
  - Available: Monday 12:50 - 14:20, Wednesday 09:00 - 10:35
  - Preferred Courses: Biology, Philosophy, Chemistry
- **Dr. Martinez:**
  - Available: Monday 10:45 - 12:20
  - Preferred Course: Computer Science
- **Dr. Allen:**
  - Available: Thursday 09:00 - 10:35
  - Preferred Course: History

### test2.json

#### Time Slots
The available time slots for courses are as follows:
- **Tuesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
  - 14:35 - 16:05

#### Courses
The courses and their preferred time slots are listed below:
- **History:** Tuesday 09:00 - 10:35
- **Philosophy:** Tuesday 10:45 - 12:20
- **Economics:** Tuesday 12:50 - 14:20
- **Psychology:** Tuesday 14:35 - 16:05

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Adams:**
  - Available: Tuesday 09:00 - 10:35
  - Preferred Course: History
- **Dr. Baker:**
  - Available: Tuesday 10:45 - 12:20
  - Preferred Course: Philosophy
- **Dr. Carter:**
  - Available: Monday Tuesday 12:50 - 14:20
  - Preferred Course: Economics Science
- **Dr. Davis:**
  - Available: Tuesday 14:35 - 16:05
  - Preferred Courses: Psychology

### test3.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
- **Tuesday:**
  - 12:50 - 14:20
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
- **Thursday:**
  - 12:50 - 14:20
- **Friday:**
  - 09:00 - 10:35
  - 10:45 - 12:20

#### Courses
The courses and their preferred time slots are listed below:
- **Art History:** Monday 09:00 - 10:35, Wednesday 10:45 - 12:20
- **Philosophy:** Monday 10:45 - 12:20
- **Mathematics:** Tuesday 12:50 - 14:20
- **Biology:** Wednesday 09:00 - 10:35
- **Economics:** Wednesday 10:45 - 12:20
- **Computer Science:** Thursday 12:50 - 14:20, Monday 10:45 - 12:20
- **Chemistry:** Friday 09:00 - 10:35
- **Statistics:** Friday 10:45 - 12:20

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Smith:**
  - Available: Monday 09:00 - 10:35, Monday 10:45 - 12:20, Tuesday 12:50 - 14:20, Friday 09:00 - 10:35
  - Preferred Course: Art History
- **Dr. Johnson:**
  - Available: Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20, Thursday 12:50 - 14:20
  - Preferred Courses: Mathematics, Biology, Economics
- **Dr. Lee:**
  - Available: Friday 09:00 - 10:35, Friday 10:45 - 12:20, Thursday 12:50 - 14:20
  - Preferred Courses: Computer Science, Chemistry, Statistics

### test4.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 09:00 - 10:35
  - 10:45 - 12:25
- **Tuesday:**
  - 09:00 - 10:35
- **Wednesday:**
  - 10:45 - 12:25
  - 12:25 - 14:20
- **Thursday:**
  - 09:00 - 10:35
- **Friday:**
  - 10:45 - 12:25

#### Courses
The courses and their preferred time slots are listed below:
- **History:** Monday 09:00 - 10:35
- **Data Science:** Monday 10:45 - 12:25
- **Literature:** Tuesday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **John Doe:**
  - Available: Monday 09:00 - 10:35, Monday 10:45 - 12:25
  - Preferred Course: Data Science
- **Jane Smith:**
  - Available: Monday 10:45 - 12:25, Tuesday 09:00 - 10:35
  - Preferred Courses: History, Literature
- **Emily Brown:**
  - Available: Tuesday 09:00 - 10:35
  - Preferred Course: History

### test5.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
- **Friday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20

#### Courses
The courses and their preferred time slots are listed below:
- **Math:** Monday 09:00 - 10:35, Monday 10:45 - 12:20
- **Physics:** Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20
- **Chemistry:** Monday 12:50 - 14:20, Wednesday 12:50 - 14:20
- **Biology:** Friday 09:00 - 10:35, Friday 10:45 - 12:20
- **History:** Friday 12:50 - 14:20, Monday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Smith:**
  - Available: Monday 09:00 - 10:35, Monday 10:45 - 12:20, Friday 09:00 - 10:35
  - Preferred Courses: Math, History
- **Dr. Johnson:**
  - Available: Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20, Friday 12:50 - 14:20
  - Preferred Course: Physics
- **Dr. Lee:**
  - Available: Monday 12:50 - 14:20, Wednesday 12:50 - 14:20
  - Preferred Course: Chemistry
- **Dr. Brown:**
  - Available: Friday 10:45 - 12:20
  - Preferred Course: Biology
- **Dr. Davis:**
  - Available: Friday 09:00 - 10:35, Friday 10:45 - 12:20, Friday 12:50 - 14:20
  - Preferred Courses: Math, Biology

### test6.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 12:50 - 14:20
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
  - 12:50 - 14:20
- **Friday:**
  - 09:00 - 10:35

#### Courses
The courses and their preferred time slots are listed below:
- **Physics:** Wednesday 12:50 - 14:20, Friday 09:00 - 10:35
- **Chemistry:** Wednesday 10:45 - 12:20, Wednesday 12:50 - 14:20
- **Biology:** Wednesday 12:50 - 14:20, Wednesday 09:00 - 10:35
- **History:** Monday 12:50 - 14:20, Wednesday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Smith:**
  - Available: Monday 12:50 - 14:20, Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20
  - Preferred Course: Physics
- **Dr. Johnson:**
  - Available: Wednesday 12:50 - 14:20, Friday 09:00 - 10:35
  - Preferred Course: Chemistry
- **Dr. Lee:**
  - Available: Monday 12:50 - 14:20, Wednesday 09:00 - 10:35
  - Preferred Courses: Biology, History

### test7.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 10:45 - 12:20
- **Tuesday:**
  - 09:00 - 10:35
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
- **Thursday:**
  - 09:00 - 10:35
- **Friday:**
  - 09:00 - 10:35

#### Courses
The courses and their preferred time slots are listed below:
- **Computer Science:** Monday 10:45 - 12:20, Tuesday 09:00 - 10:35
- **Physics:** Wednesday 10:45 - 12:20, Thursday 09:00 - 10:35
- **Philosophy:** Wednesday 09:00 - 10:35, Friday 09:00 - 10:35
- **Biology:** Friday 09:00 - 10:35
- **Computer Science:** Monday 10:45 - 12:20
- **History:** Tuesday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Brown:**
  - Available: Tuesday 09:00 - 10:35
  - Preferred Courses: Philosophy, Biology
- **Dr. Martinez:**
  - Available: Tuesday 09:00 - 10:35, Friday 09:00 - 10:35
  - Preferred Courses: Computer Science, History
- **Dr. Allen:**
  - Available: Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20, Thursday 09:00 - 10:35
  - Preferred Courses: Computer Science, Physics

### test8.json

#### Time Slots
The available time slots for courses are as follows:
- **Monday:**
  - 10:45 - 12:20
- **Tuesday:**
  - 09:00 - 10:35
- **Wednesday:**
  - 09:00 - 10:35
  - 10:45 - 12:20
- **Thursday:**
  - 09:00 - 10:35
- **Friday:**
  - 09:00 - 10:35

#### Courses
The courses and their preferred time slots are listed below:
- **Computer Science:** Monday 10:45 - 12:20, Tuesday 09:00 - 10:35
- **Physics:** Wednesday 10:45 - 12:20, Thursday 09:00 - 10:35
- **Philosophy:** Wednesday 09:00 - 10:35, Friday 09:00 - 10:35
- **Biology:** Friday 09:00 - 10:35

#### Instructors
Instructors and their availability, along with preferred courses:
- **Dr. Brown:**
  - Available: Tuesday 09:00 - 10:35
  - Preferred Courses: Philosophy, Biology
- **Dr. Martinez:**
  - Available: Tuesday 09:00 - 10:35, Friday 09:00 - 10:35
  - Preferred Courses: Physics
- **Dr. Allen:**
  - Available: Wednesday 09:00 - 10:35, Wednesday 10:45 - 12:20, Thursday 09:00 - 10:35
  - Preferred Courses: Computer Science, Physics










