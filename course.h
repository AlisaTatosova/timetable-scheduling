#ifndef COURSE_H
#define COURSE_H
#include "time_slot.h"
#include <string>
#include <vector>

class Course {
public:
    Course(const std::string& course_name, const std::set<TimeSlot>& preferred_timeslots);

    void display_info() const;
    std::string get_course_name() const;
    std::set<TimeSlot> get_preferred_slots() const;
    bool operator==(const Course& other) const;
    
private:
    std::string course_name;
    std::set<TimeSlot> preferred_timeslots;
};

#endif