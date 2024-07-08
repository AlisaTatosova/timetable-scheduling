#include "course.h"

Course::Course(const std::string& course_name, const std::set<TimeSlot>& preferred_timeslots)
        : course_name{course_name}, preferred_timeslots{preferred_timeslots} {}

void Course::display_info() const {
    std::cout << course_name << " ";
}

std::string Course::get_course_name() const {
    return course_name;
}

std::set<TimeSlot> Course::get_preferred_slots() const {
    return preferred_timeslots;
}

bool Course::operator==(const Course& other) const {
    return course_name == other.course_name;
}