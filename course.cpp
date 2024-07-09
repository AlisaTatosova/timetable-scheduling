#include "course.h"

Course::Course(const std::string& course_name, const std::vector<TimeSlot>& preferred_timeslots)
        : course_name{course_name}, preferred_timeslots{preferred_timeslots} {}

std::string Course::get_course_name() const {
    return course_name;
}

std::vector<TimeSlot> Course::get_preferred_slots() const {
    return preferred_timeslots;
}

void Course::display_info() const {
    std::cout << course_name << " ";
}
