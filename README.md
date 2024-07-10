## University Timetabling System

University Timetabling System schedules courses, assigns instructors, and timeslots.The scheduling algorithm must satisfy all hard constraints and as many soft constraints as possible. Note that two timeslots can not be intersected.

# Hard constraints:
Each course must be scheduled exactly once in an available time slot and assigned to an instructor
An instructor can only be assigned to a course if they are available during the corresponding time slot
An instructor cannot be scheduled to teach more than one course in the same time slot

# Soft constraints:
Courses should be scheduled in preferred time slots if possible
Instructors should be assigned to their preferred courses if possible 

## Idea of solution

For each course firstly pushing to the vector of possible variants the variant that 2 soft constraints are satisfied, then when 1 of soft constraints is satisfied , then no soft constraints is satisfied for current course, then we are going through that vector of possible variants and recursively calling that same function for next course and doing that continuly untill we find the first combination that satisfy.

## Tests

Here you can find test1.json - test6.json files in which are included tests, for testing just load them with function load_state(filename.json).

