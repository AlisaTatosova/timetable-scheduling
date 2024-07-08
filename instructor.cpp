#include "instructor.h"

Instructor::Instructor(const std::string& instructor_name, const std::vector<TimeSlot>& availabilty, const std::vector<Course>& preferred_courses)
        : instructor_name{instructor_name}, availabilty{availabilty}, preferred_courses{preferred_courses} {}
        
void Instructor::display_info() const {
    std::cout << instructor_name << " ";
}

bool Instructor::operator<(const Instructor& other) const {
    if (availabilty.size() != other.availabilty.size()) {
        return availabilty.size() < other.availabilty.size();
    }
    if (preferred_courses.size() != other.preferred_courses.size()) {
        return preferred_courses.size() < other.preferred_courses.size();
    }
    return instructor_name < other.instructor_name;
}

std::vector<TimeSlot> Instructor::get_availabilty() const {
    return availabilty;
}

std::string Instructor::get_name() const {
    return instructor_name;
}

std::vector<Course> Instructor::get_preferred_courses() const {
    return preferred_courses;
}