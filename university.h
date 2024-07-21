#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "time_slot.h"
#include "course.h"
#include "instructor.h"
#include "possible_combination.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "dependencies/single_include/nlohmann/json.hpp"
#include <fstream>

class University {
public:
    void add_course(const Course& course);
    void add_timeslot(const TimeSlot& time);
    void add_instructor(const Instructor& instructor);
    void schedule();
    void save_state(const std::string& filename);
    void load_state(const std::string& filename);

private:
    bool preferred_course(const std::vector<PossibleCombination>& possible, const PossibleCombination& possible_comb);
    bool not_occupied(const TimeSlot& slot);
    bool not_exist(const std::vector<PossibleCombination>& possible, const PossibleCombination& possible_comb);
    void make_memo();
    void schedule_course(int i, int& best);
    void create_map_with_instructor_avalabilities();
    void found_best_solution(int& best);

    void two_soft_constraints_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course);
    void preferred_course_soft_constraint_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course);
    void preferred_slot_soft_constraint_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course);
    void two_soft_constraints_not_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course);

    void serialize_courses(nlohmann::json& j);
    void serialize_instructors(nlohmann::json& j);
    void serialize_timeslots(nlohmann::json& j);

    void deserialize_courses(nlohmann::json& j);
    void deserialize_instructors(nlohmann::json& j);
    void deserialize_timeslots(nlohmann::json& j);
    
private:
    std::vector<Instructor> instructors;
    std::vector<TimeSlot> timeslots;
    std::vector<Course> courses;
    std::map<TimeSlot, std::set<Instructor>> slots_with_available_instructors;
    std::map<Course, std::vector<PossibleCombination>> memo;
    std::pair<std::vector<PossibleCombination>, int> possible_timetable; 
    std::vector<PossibleCombination> best_timetable;
};

#endif