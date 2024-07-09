#include "university.h"
#include <iostream>

int main() {
    University university;
    university.load_state("test1.json");
    // for testing
    // university.load_state("test2.json");
    // university.load_state("test3.json");
    // university.load_state("test4.json");
    // university.load_state("test5.json");
    // university.load_state("test6.json");
    university.schedule();
}