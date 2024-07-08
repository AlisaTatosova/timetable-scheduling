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

bool University::is_preferred_course_for_instructor(const Instructor& instructor, const Course& course) {
    const auto& preferences = instructor.get_preferred_courses();
    for (const auto& pref_course : preferences) {
        if (pref_course.get_course_name() == course.get_course_name()) {
            return true;
        }
    }

    return false;
}

bool University::not_occupied(const TimeSlot& slot) {
    for (const auto& it : pair) {
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
    
    for (const auto& it : pair) {
        std::get<2>(it).display_info();
        std::get<0>(it).display_info();
        std::get<1>(it).display_info();
        std::cout << std::endl;
    }
}

void University::schedule_course(int i, bool& solution_found) {   
    Course& current_course = courses[i];
    if (i == courses.size()) {
        solution_found = true;
        // for (const auto& it : pair) {
        //     std::cout << std::get<0>(it).get_course_name() << " " <<  std::get<1>(it).get_name() << " " << std::get<2>(it).get_start_time() << " - " << std::get<2>(it).get_end_time() << "        ";
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        return;
    } 

    const auto& preferred_slots = current_course.get_preferred_slots(); 
    for (const auto& slot : preferred_slots) {
        for (const auto& instructor : slots_with_available_instructors[slot]) { // frum enq et jamin azat instructorneri vrayov
            //   std::cout << course.get_course_name() << " " <<   slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
            if (not_occupied(slot) && is_preferred_course_for_instructor(instructor, current_course)) { // nayum enq vor nayev derevs zbaxvac chlini et slots u nayev prefered course lini yntrvac instructori hamar
                // std::cout << "           " << slot.get_start_time() << " " << instructor.get_name() << " " << std::endl;
                std::tuple<Course, Instructor, TimeSlot> tuple = std::make_tuple(current_course, instructor, slot);
                pair.push_back(tuple); 
                schedule_course(i + 1, solution_found);
                //  std::cout << "   returned " << std::endl;
                if (solution_found) { // henc 1 hat chyux gtanq full karanq el mnacacy chnayenq el
                    return;
                }
                pair.pop_back();     //jnjum enq tvyal pahin mejy verjin qcacy u nayum enq mnacac hnaravor tarberaknery      
            }
        }
    }
}
