#include "university.h"

void University::add_course(const Course& course) {
    courses.push_back(course);  
}

void University::add_timeslot(const TimeSlot& time) {
    timeslots.insert(time);
}

void University::add_instructor(Instructor& instructor) {
    instructors.push_back(instructor);
    const auto& availabilities_of_instructor = instructor.get_availabilty();
    for (const auto& available : availabilities_of_instructor) {
        if (timeslots.find(available) != timeslots.end()) {
            slots_with_available_instructors[available].insert(instructor);
        }
    }
}

bool University::preferred_course_and_preferred_slot(const Course& course, const Instructor& instructor,const TimeSlot& slot) {
    if (!not_occupied(slot)) {
        return false;
    }

    const auto& preferences = instructor.get_preferred_courses();
    for (const auto& pref_course : preferences) {
        if (pref_course.get_course_name() == course.get_course_name()) {
            return true;
        }
    }

    return false;
}

bool University::not_occupied(const TimeSlot& slot) {
    for (const auto& it : timetable) {
        if (std::get<2>(it).get_day() == slot.get_day() &&
            std::get<2>(it).get_start_time() == slot.get_start_time() &&
            std::get<2>(it).get_end_time() == slot.get_end_time()) {
            return false;
        }
    } 

    return true;
}

void University::schedule() {
    bool solution_found = false;
    schedule_course(0, solution_found);
    
    for (const auto& it : timetable) {
        std::get<2>(it).display_info();
        std::get<0>(it).display_info();
        std::get<1>(it).display_info();
        std::cout << std::endl;
    }
}

void University::schedule_course(int i, bool& solution_found) { 
    if (i == courses.size()) {
        solution_found = true;
        // for (const auto& it : pair) {
        //     std::cout << std::get<0>(it).get_course_name() << " " <<  std::get<1>(it).get_name() << " " << std::get<2>(it).get_start_time() << " - " << std::get<2>(it).get_end_time() << "        ";
        //     std::cout << std::endl;
        // }
        std::cout << std::endl;
        return;
    } 

    Course& current_course = courses[i];
    std::vector<std::tuple<Course, Instructor, TimeSlot>> possible;
    const auto& preferred_slots = current_course.get_preferred_slots(); 

    // possible - i mej skzbum qcum enq nranq voronq ev preferred timeslot en course-i hamar ev preferred course instructori hamar
    for (const auto& slot : preferred_slots) {
        for (const auto& instructor : slots_with_available_instructors[slot]) { // frum enq et jamin azat instructorneri vrayov
            if (preferred_course_and_preferred_slot(current_course, instructor, slot)) { 
                // std::cout << "           " << slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                std::tuple<Course, Instructor, TimeSlot> tuple = std::make_tuple(current_course, instructor, slot);
                possible.push_back(tuple);   
            }
        }
    }

    // heto qcum enq instructori preferred course lini, bayc preferred jami chlini
    for (const auto& slot : timeslots) {
        if (!(preferred_slots.find(slot) != preferred_slots.end())) {
            for (const auto& instructor : slots_with_available_instructors[slot]) { // frum enq et jamin azat instructorneri vrayov
                //   std::cout << course.get_course_name() << " " <<   slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                if (preferred_course_and_preferred_slot(current_course, instructor, slot)) { // nayum enq vor nayev derevs zbaxvac chlini et slots u nayev prefered course lini yntrvac instructori hamar
                    // std::cout << "           " << slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                    std::tuple<Course, Instructor, TimeSlot> tuple = std::make_tuple(current_course, instructor, slot);
                    possible.push_back(tuple);     
                }
            }
        }
    }

    // qcum enq vor preffer slota tvyal course i hamar bayc instructori preffered course chi
    for (const auto& slot : preferred_slots) {   
        for (const auto& instructor : slots_with_available_instructors[slot]) { // frum enq et jamin azat instructorneri vrayov
            //   std::cout << course.get_course_name() << " " <<   slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
            if (not_occupied(slot)) { // nayum enq vor nayev derevs zbaxvac chlini et slots u nayev prefered course lini yntrvac instructori hamar
                // std::cout << "           " << slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                std::tuple<Course, Instructor, TimeSlot> tuple = std::make_tuple(current_course, instructor, slot);
                possible.push_back(tuple);     
            }
        }   
    }

    // voch preffered slota, voch el instructori hamar preffered course
    for (const auto& slot : timeslots) {
        if (!(preferred_slots.find(slot) != preferred_slots.end())) {
            for (const auto& instructor : slots_with_available_instructors[slot]) { // frum enq et jamin azat instructorneri vrayov
                if (not_occupied(slot)) { // nayum enq vor nayev derevs zbaxvac chlini et slots u nayev prefered course lini yntrvac instructori hamar
                    // std::cout << "           " << slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                    std::tuple<Course, Instructor, TimeSlot> tuple = std::make_tuple(current_course, instructor, slot);
                    possible.push_back(tuple);     
                }
            }
        }
    }

    // frum enq current course i hamar hnaravor combinationnerov (skzbum erb bolor softery bavararvuma, heto mekn u meky, ..,)
    for (const auto& current_course_possible_combination : possible) {  
        timetable.push_back(current_course_possible_combination);
        schedule_course(i + 1, solution_found);  // dfs ov bacvuma 
        if (solution_found) {
            return;
        }
        timetable.pop_back();
    }
}