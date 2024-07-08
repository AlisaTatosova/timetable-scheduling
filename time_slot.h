#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <iostream>
#include <string>
#include <set>

enum class Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
};

class TimeSlot {
public:
    TimeSlot(Day day, const std::string& start_time, const std::string& end_time);

    Day get_day() const;
    std::string get_start_time() const;
    std::string get_end_time() const;
    bool operator<(const TimeSlot& other) const;
    void display_info() const;
    std::string day_to_string() const;
    bool operator==(const TimeSlot& other) const;
 
private:
    Day day;
    std::string start_time;
    std::string end_time;
};

#endif