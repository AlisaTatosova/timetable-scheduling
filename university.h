#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "time_slot.h"
#include "course.h"
#include "instructor.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "dependencies/single_include/nlohmann/json.hpp"
#include <fstream>

class University {
public:
    void add_course(const Course& course);
    void add_timeslot(const TimeSlot& time);
    void add_instructor(Instructor& instructor);
    void schedule();
    void save_state(const std::string& filename);
    void load_state(const std::string& filename);

private:
    bool preferred_course_and_preferred_slot(const Course& course, const Instructor& instructor, const TimeSlot& slot);
    bool not_occupied(const TimeSlot& slot);
    void schedule_course(int i, bool& solution_found);
    
    void serialize_courses(nlohmann::json& j);
    void serialize_instructors(nlohmann::json& j);
    void serialize_timeslots(nlohmann::json& j);

    void deserialize_courses(nlohmann::json& j);
    void deserialize_instructors(nlohmann::json& j);
    void deserialize_timeslots(nlohmann::json& j);

private:
    std::vector<Instructor> instructors;
    std::vector<TimeSlot> timeslots;
    std::vector<Course> courses;
    std::map<TimeSlot, std::set<Instructor>> slots_with_available_instructors;
    std::vector<std::tuple<Course, Instructor, TimeSlot>> timetable;
};

#endif