#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "time_slot.h"
#include "course.h"
#include "instructor.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class University {
public:
    void add_course(const Course& course);
    void add_timeslot(const TimeSlot& time);
    void add_instructor(Instructor& instructor);
    bool is_preferred_course_for_instructor(const Instructor& instructor, const Course& course);
    bool not_occupied(const TimeSlot& slot);
    void schedule_course(int i, bool& solution_found);
    void schedule();
    
private:
    std::vector<Instructor> instructors;
    std::set<TimeSlot> timeslots;
    std::vector<Course> courses;
    std::map<TimeSlot, std::set<Instructor>> slots_with_available_instructors;
    std::vector<std::tuple<Course, Instructor, TimeSlot>> pair;
};

#endif