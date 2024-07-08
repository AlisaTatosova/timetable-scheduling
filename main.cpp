#include "university.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main() {
    TimeSlot t1(Day::MONDAY, "12:00", "13:00");
    TimeSlot t2(Day::MONDAY, "13:00", "14:00");
    TimeSlot t3(Day::MONDAY, "15:00", "16:00");


    Course c1{"math", {t1, t2}};
    Course c2{"english", {t2, t3}};
    Course c3{"programming", {t3}};

    Instructor i1{"ani", {t3, t1}, {c1, c2}};
    Instructor i2{"anna", {t1, t2}, {c1, c2}};
    Instructor i3{"alis", {t1, t2, t3}, {c3}};

    // Instructor c4{"vardan", {t7, t8}, {}};

    University u;
    
    u.add_timeslot(t1);
    u.add_timeslot(t2);
    u.add_timeslot(t3);

    u.add_course(c1);
    u.add_course(c2);
    u.add_course(c3);
    u.add_instructor(i1);
    u.add_instructor(i2);
    u.add_instructor(i3);
    // a.add_instructor(i4);
    u.schedule();

}