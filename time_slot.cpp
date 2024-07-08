#include "time_slot.h"

TimeSlot::TimeSlot(Day day, const std::string& start_time, const std::string& end_time) : day{day}, start_time{start_time}, end_time{end_time} {}

bool TimeSlot::operator<(const TimeSlot& other) const {
    if (day != other.day) {
        return day < other.day;
    }

    if (start_time != other.start_time) {
        return start_time < other.start_time;
    }

    return end_time < other.end_time;
}

Day TimeSlot::get_day() const {
    return day;
}

std::string TimeSlot::day_to_string() const {
    switch (day) {
        case Day::MONDAY:
            return "MONDAY";
        case Day::TUESDAY:
            return "TUESDAY";
        case Day::WEDNESDAY:
            return "WEDNESDAY";
        case Day::THURSDAY:
            return "THURSDAY";
        case Day::FRIDAY:
            return "FRIDAY";
        case Day::SATURDAY:
            return "SATURDAY";
        case Day::SUNDAY:
            return "SUNDAY ";
        default:
            return "NO SUCH DAY";
    }
}

void TimeSlot::display_info() const {
    std::cout << this -> day_to_string() << " " << start_time << " - " << end_time << " ";
}


std::string TimeSlot::get_start_time() const {
    return start_time;
}

std::string TimeSlot::get_end_time() const {
    return end_time;
}
