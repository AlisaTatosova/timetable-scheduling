#include "possible_combination.h"

PossibleCombination::PossibleCombination(const Course& course, const Instructor& instructor, const TimeSlot& slot, int softs_preserved_count) 
    : course{course}, instructor{instructor}, slot{slot}, softs_preserved_count{softs_preserved_count} {}

Course PossibleCombination::get_course() const {
    return course;
}

Instructor PossibleCombination::get_instructor() const {
    return instructor;
}

TimeSlot PossibleCombination::get_slot() const {
    return slot;
}

int PossibleCombination::get_softs_preserved_count() const {
    return softs_preserved_count;
}

bool PossibleCombination::operator==(const PossibleCombination& other) const {
    return course == other.course && instructor == other.instructor && slot == other.slot;
}