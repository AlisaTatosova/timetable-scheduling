#ifndef POSSIBLE_COMBINATION_H
#define POSSIBLE_COMBINATION_H
#include "course.h"
#include "instructor.h"
#include "time_slot.h"
#include <iostream>
#include <string>

class PossibleCombination {
public:
    PossibleCombination(const Course& course, const Instructor& instructor, const TimeSlot& slot, int softs_preserved_count);

    Course get_course() const;
    Instructor get_instructor() const;
    TimeSlot get_slot() const;
    int get_softs_preserved_count() const;
    bool operator==(const PossibleCombination& other) const;
    
private:
    Course course;
    Instructor instructor;
    TimeSlot slot;
    int softs_preserved_count;
};

#endif