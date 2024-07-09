#include "university.h"
#include <iostream>

int main() {
    TimeSlot timeSlot1("MONDAY", "09:00", "10:00");
    TimeSlot timeSlot2("MONDAY", "11:00", "12:00");
    TimeSlot timeSlot3("TUESDAY", "09:00", "10:00");
    TimeSlot timeSlot4("WEDNESDAY", "11:00", "12:00");
   
    Course course1("Math", {timeSlot1, timeSlot2});
    Course course2("Programming", {timeSlot2, timeSlot3});
    Course course3("English", {timeSlot3, timeSlot4});
    Course course4("History", {timeSlot1, timeSlot3});

    Instructor instructor1("Alisa", {timeSlot1, timeSlot2}, {course4, course2});
    Instructor instructor2("David", {timeSlot1, timeSlot2, timeSlot3}, {course1, course3});
    Instructor instructor3("Anna", {timeSlot2, timeSlot4}, {course1});

    University university;
    university.add_timeslot(timeSlot1);
    university.add_timeslot(timeSlot2);
    university.add_timeslot(timeSlot3);
    university.add_timeslot(timeSlot4);
    university.add_course(course1);
    university.add_course(course2);
    university.add_course(course3);
    university.add_course(course4);
    university.add_instructor(instructor1);
    university.add_instructor(instructor2);
    university.add_instructor(instructor3);
   
    university.schedule();
    university.save_state("state.json");
    university.load_state("state.json");
}