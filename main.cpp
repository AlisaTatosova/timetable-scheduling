#include "university.h"
#include <iostream>

int main() {
    University university;
    int test_num = 1;
    std::cout << "Choose a test file to load (1 to 5): ";
    std::cin >> test_num;

    if (test_num < 1 || test_num > 5) {
        std::cerr << "Invalid selection. Defaulting to test1.json." << std::endl;
        test_num = 1;
    }

    std::string test = "tests/test" + std::to_string(test_num) + ".json";
    university.load_state(test);	
    university.schedule();
    university.print_timetable();
}