#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <iostream>
#include <string>

class TimeSlot {
public:
    TimeSlot(const std::string& day, const std::string& start_time, const std::string& end_time);

    std::string get_day() const;
    std::string get_start_time() const;
    std::string get_end_time() const;
    void display_info() const;
    bool operator<(const TimeSlot& other) const;
    bool operator==(const TimeSlot& other) const;
    
private:
    std::string day;
    std::string start_time;
    std::string end_time;
};

#endif