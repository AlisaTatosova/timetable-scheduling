#include "university.h"

void University::add_course(const Course& course) {
    courses.push_back(course);  
}

void University::add_timeslot(const TimeSlot& time) {
    timeslots.push_back(time);
}

void University::add_instructor(const Instructor& instructor) {
    instructors.push_back(instructor);
}

std::vector<TimeSlot> University::get_timeslots() const {
    return timeslots;
}

std::vector<Course> University::get_courses() const {
    return courses;
}

std::vector<Instructor> University::get_instructors() const {
    return instructors;
}

void University::create_map_with_instructor_avalabilities() {
    for (const auto& instructor : instructors) {
        const auto& availabilities_of_instructor = instructor.get_availabilty();
        for (const auto& available : availabilities_of_instructor) {
            if (std::find(timeslots.begin(), timeslots.end(), available) != timeslots.end()) {
                slots_with_available_instructors[available].insert(instructor);
            }
        }
    }
}

bool University::preferred_course(const std::vector<PossibleCombination>& possible, const PossibleCombination& possible_comb) {
    if (!not_exist(possible, possible_comb)) {
        return false;
    }

    const auto& preferences = possible_comb.get_instructor().get_preferred_courses();
    const auto& existing_course = possible_comb.get_course();
    for (const auto& pref_course : preferences) {
        if (pref_course == existing_course) {
            return true;
        }
    }

    return false;
}

bool University::not_occupied(const TimeSlot& slot) {
    for (const auto& it : possible_timetable.first) {
        if (it.get_slot().get_day() == slot.get_day() &&
            it.get_slot().get_start_time() == slot.get_start_time() &&
            it.get_slot().get_end_time() == slot.get_end_time()) {
            return false;
        }
    }

    return true;
}

void University::serialize_courses(nlohmann::json& j) {
    for (const auto& course : courses) {
        nlohmann::json j_course;
        j_course["course_name"] = course.get_course_name();
        for (const auto& slot : course.get_preferred_slots()) {
            nlohmann::json j_slot;
            j_slot["day"] = slot.get_day();
            j_slot["start_time"] = slot.get_start_time();
            j_slot["end_time"] = slot.get_end_time();
            j_course["preferred_slots"].push_back(j_slot);
        }

        j["courses"].push_back(j_course);
    }
}

void University::serialize_instructors(nlohmann::json& j) {
    for (const auto& instructor : instructors) {
        nlohmann::json j_instructor;
        j_instructor["name"] = instructor.get_name();
        for (const auto& slot : instructor.get_availabilty()) {
            nlohmann::json j_slot;
            j_slot["day"] = slot.get_day();
            j_slot["start_time"] = slot.get_start_time();
            j_slot["end_time"] = slot.get_end_time();
            j_instructor["availability"].push_back(j_slot);
        }

        for (const auto& course : instructor.get_preferred_courses()) {
            nlohmann::json j_course;
            j_course["course_name"] = course.get_course_name();
            for (const auto& slot : course.get_preferred_slots()) {
                nlohmann::json j_slot;
                j_slot["day"] = slot.get_day();
                j_slot["start_time"] = slot.get_start_time();
                j_slot["end_time"] = slot.get_end_time();
                j_course["preferred_slots"].push_back(j_slot);
            }

            j_instructor["preferred_courses"].push_back(j_course);
        }

        j["instructors"].push_back(j_instructor);
    }
}

void University::serialize_timeslots(nlohmann::json& j) {
    for (const auto& slot : timeslots) {
        nlohmann::json j_slot;
        j_slot["day"] = slot.get_day();
        j_slot["start_time"] = slot.get_start_time();
        j_slot["end_time"] = slot.get_end_time();
        j["timeslots"].push_back(j_slot);
    }
}

void University::deserialize_courses(nlohmann::json& j) {
    for (const auto& j_course : j["courses"]) {
        std::string course_name = j_course["course_name"];
        std::vector<TimeSlot> preferred_slots;
        for (const auto& j_slot : j_course["preferred_slots"]) {
            TimeSlot slot(j_slot["day"], j_slot["start_time"], j_slot["end_time"]);
            preferred_slots.push_back(slot);
        }
        courses.push_back({course_name, preferred_slots});
    }
}

void  University::deserialize_instructors(nlohmann::json& j) {
    for (const auto& j_instructor : j["instructors"]) {
        std::string name = j_instructor["name"];
        std::vector<TimeSlot> availability;
        for (const auto& j_slot : j_instructor["availability"]) {
            TimeSlot slot(j_slot["day"], j_slot["start_time"], j_slot["end_time"]);
            availability.push_back(slot);
        }

        std::vector<Course> preferred_courses;
        for (const auto& course : j_instructor["preferred_courses"]) {
            std::string course_name = course["course_name"];
            std::vector<TimeSlot> preferred_slots;
            for (const auto& j_slot : course["preferred_slots"]) {
                TimeSlot slot(j_slot["day"], j_slot["start_time"], j_slot["end_time"]);
                preferred_slots.push_back(slot);
            }

            preferred_courses.push_back({course_name, preferred_slots});
        }

        instructors.push_back({name, availability, preferred_courses});
    }
}

void  University::deserialize_timeslots(nlohmann::json& j) {
    for (const auto& j_slot : j["timeslots"]) {
        TimeSlot slot(j_slot["day"], j_slot["start_time"], j_slot["end_time"]);
        timeslots.push_back(slot);
    }
}

void University::save_state(const std::string& filename) {
    nlohmann::json j;
    serialize_timeslots(j); 
    serialize_courses(j); 
    serialize_instructors(j);

    std::ofstream file(filename);
    file << j.dump(4);
}

void University::load_state(const std::string& filename) {
    std::ifstream file(filename);
    nlohmann::json j;
    file >> j;

    courses.clear();
    instructors.clear();
    timeslots.clear();

    deserialize_courses(j);
    deserialize_instructors(j);
    deserialize_timeslots(j);
}

void University::found_best_solution(int& best) {
    if (possible_timetable.second > best) {
        best_timetable.clear();
        best = possible_timetable.second;
        for (const auto& it : possible_timetable.first) {
            best_timetable.push_back(it);
        }
    }
}

void University::schedule() {
    create_map_with_instructor_avalabilities();
    int best = -1;
    make_memo();
    schedule_course(0, best);
}

void University::print_timetable() const {
    std::cout << "Timetable" << std::endl;
    if (!best_timetable.size()) {
        std::cout << "There is no way for valid scheduling" << std::endl;
        return;
    }

    for (const auto& it : best_timetable) {
        it.get_course().display_info();
        std::cout << "- ";
        it.get_instructor().display_info();
        std::cout << "- ";
        it.get_slot().display_info();
        std::cout << std::endl;
    }
}

bool University::not_exist(const std::vector<PossibleCombination>& possible, const PossibleCombination& possible_comb) {
    for (const auto& it : possible) {
        if (it == possible_comb) {
            return false;
        }
    }

    return true;
}

// preferred course for instructor and preferred slot for course 
void University::two_soft_constraints_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course) {
    const auto& preferred_slots = current_course.get_preferred_slots(); 
    for (const auto& slot : preferred_slots) {
        for (const auto& instructor : slots_with_available_instructors[slot]) {
            PossibleCombination possible_comb(current_course, instructor, slot, 2);
            if (preferred_course(possible, possible_comb)) { 
                possible.push_back(possible_comb);  
            }
        }
    }
}

// preferred course for instructor, but not preferred slot for course 
void University::preferred_course_soft_constraint_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course) {
    const auto& preferred_slots = current_course.get_preferred_slots(); 
    for (const auto& slot : timeslots) {  
        if (!(std::find(preferred_slots.begin(), preferred_slots.end(), slot) != preferred_slots.end())) {
            for (const auto& instructor : slots_with_available_instructors[slot]) { 
                PossibleCombination possible_comb(current_course, instructor, slot, 1);
                if (preferred_course(possible, possible_comb)) { 
                    possible.push_back(possible_comb); 
                }
            }
        }
    }
}

// not preferred course for instructor, but preferred slot for course 
void University::preferred_slot_soft_constraint_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course) {
    const auto& preferred_slots = current_course.get_preferred_slots();
    for (const auto& slot : preferred_slots) {   
        for (const auto& instructor : slots_with_available_instructors[slot]) { 
            PossibleCombination possible_comb(current_course, instructor, slot, 1);
            if (not_exist(possible, possible_comb)) { 
                possible.push_back(possible_comb);     
            }                   
        }   
    }
}

// not preferred course for instructor, not preferred slot for course (but some slot and course that exist)
void University::two_soft_constraints_not_satisfy(std::vector<PossibleCombination>& possible, const Course& current_course) {
    const auto& preferred_slots = current_course.get_preferred_slots(); 
    for (const auto& slot : timeslots) {
        if (!(std::find(preferred_slots.begin(), preferred_slots.end(), slot) != preferred_slots.end())) {
            for (const auto& instructor : slots_with_available_instructors[slot]) { 
                PossibleCombination possible_comb(current_course, instructor, slot, 0);
                if (not_exist(possible, possible_comb)) { 
                    possible.push_back(possible_comb);     
                }   
            }
        }
    }
}

void University::make_memo() { 
    std::vector<PossibleCombination> possible;
    for (const auto& current_course : courses) {
        possible.clear();
        two_soft_constraints_satisfy(possible, current_course); // preferred course for instructor and preferred slot for course 
        preferred_course_soft_constraint_satisfy(possible, current_course); // preferred course for instructor, but not preferred slot for course 
        preferred_slot_soft_constraint_satisfy(possible, current_course); // not preferred course for instructor, but preferred slot for course         
        two_soft_constraints_not_satisfy(possible, current_course); // not preferred course for instructor, not preferred slot for course (but some slot and course that exist)
        memo[current_course] = possible;
    }
}

void University::schedule_course(int i, int& best) { 
    Course& current_course = courses[i];
    if (i == courses.size()) {
        found_best_solution(best);
        return;
    } 
     
    for (const auto& current_course_possible_combination : memo[current_course]) { 
        if (!not_occupied(current_course_possible_combination.get_slot())) { // checking that it doesnt be in possible_timetable
            continue;
        }
        possible_timetable.first.push_back(current_course_possible_combination);
        possible_timetable.second += current_course_possible_combination.get_softs_preserved_count();
        schedule_course(i + 1, best);   
        possible_timetable.second -= possible_timetable.first.back().get_softs_preserved_count();
        possible_timetable.first.pop_back(); 
    }
}