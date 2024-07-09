#ifndef COURSE_H
#define COURSE_H
#include "time_slot.h"
#include <string>
#include <vector>

class Course {
public:
    Course(const std::string& course_name, const std::vector<TimeSlot>& preferred_timeslots);

    std::string get_course_name() const;
    std::vector<TimeSlot> get_preferred_slots() const;
    void display_info() const;
    
private:
    std::string course_name;
    std::vector<TimeSlot> preferred_timeslots;
};

#endif