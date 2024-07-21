#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <vector>
#include "time_slot.h"
#include "course.h"

class Instructor {
public:
    Instructor(const std::string& instructor_name, const std::vector<TimeSlot>& availabilty, const std::vector<Course>& preferred_courses);

    std::vector<TimeSlot> get_availabilty() const;
    std::string get_name() const;
    std::vector<Course> get_preferred_courses() const;
    bool operator==(const Instructor& other) const;
    bool operator<(const Instructor& other) const;
    void display_info() const;
 
private:
    std::string instructor_name;
    std::vector<TimeSlot> availabilty;
    std::vector<Course> preferred_courses;
};

#endif