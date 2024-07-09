#include "time_slot.h"

TimeSlot::TimeSlot(const std::string& day, const std::string& start_time, const std::string& end_time) : day{day}, start_time{start_time}, end_time{end_time} {}

std::string TimeSlot::get_day() const {
    return day;
}

std::string TimeSlot::get_start_time() const {
    return start_time;
}

std::string TimeSlot::get_end_time() const {
    return end_time;
}

bool TimeSlot::operator<(const TimeSlot& other) const {
    if (day != other.day) {
        return day < other.day;
    }

    if (start_time != other.start_time) {
        return start_time < other.start_time;
    }

    return end_time < other.end_time;
}

bool TimeSlot::operator==(const TimeSlot& other) const {
    return day == other.day && start_time == other.start_time && end_time == other.end_time;
}

void TimeSlot::display_info() const {
    std::cout << this -> get_day() << " " << start_time << " - " << end_time << " ";
}



