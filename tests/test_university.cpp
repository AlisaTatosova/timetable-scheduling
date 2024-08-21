#include "../university.h"
#include <gtest/gtest.h>

class UniversityTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        json_file = GetParam();  
        ASSERT_NO_THROW(university.load_state(json_file)) << "Failed to load JSON file: " << json_file; // Testing the loading functionality
        university.schedule();
    }

    bool compare_jsons(const std::string& file1, const std::string& file2) {
        std::ifstream ifs1(file1);
        std::ifstream ifs2(file2);
        nlohmann::json json1, json2;
        ifs1 >> json1;
        ifs2 >> json2;
        return json1 == json2;
    }

protected:
    University university;
    std::string json_file;
};

// Test to check if the instructors are available during their assigned slots
TEST_P(UniversityTest, InstructorsAvailabilityCheck) {
    for (const auto& it : university.best_timetable) {
        auto available_slots = it.get_instructor().get_availabilty();
        auto slot = it.get_slot();
        EXPECT_TRUE(std::find(available_slots.begin(), available_slots.end(), slot) != available_slots.end())
            << "Instructor is not available for the selected slot.";
    }
}

// Testing scheduled timslots to be in university available timeslots 
TEST_P(UniversityTest, AvaiableTimeSlot) {
    auto slots = university.get_timeslots();
    for (const auto& it : university.best_timetable) {
        auto slot = it.get_slot();
        EXPECT_TRUE(std::find(slots.begin(), slots.end(), slot) != slots.end())
            << "Timeslot is not available for University.";
    }
}

// Testing that same slot not be schedulded more than once
TEST_P(UniversityTest, NoDuplicateSlots) {
    std::map<TimeSlot, int> dublicates;
    for (const auto& it : university.best_timetable) {
        auto slot = it.get_slot();
        ++dublicates[slot];
        EXPECT_TRUE(dublicates[slot] == 1) << "Duplicate slot found." << std::endl;
    }
}

// Testing if all courses are scheduled
TEST_P(UniversityTest, AllCoursesAreScheduled) {
    EXPECT_TRUE(university.best_timetable.size() == university.get_courses().size() || university.best_timetable.size() == 0) << "Not all courses are scheduled! " << std::endl;
}

// Testing saving to json functionality
TEST_P(UniversityTest, SaveStateToJson) {
    std::string saved_file = "tests/saved_test.json";
    university.save_state(saved_file); 
    EXPECT_TRUE(compare_jsons(json_file, saved_file))
        << "The saved JSON file does not match the original.";
    std::remove(saved_file.c_str()); 
}

INSTANTIATE_TEST_SUITE_P(
    All,
    UniversityTest,
    ::testing::Values(
        "tests/test1.json",
        "tests/test2.json",
        "tests/test3.json",
        "tests/test4.json",
        "tests/test5.json",
        "tests/test6.json",
        "tests/test7.json",
        "tests/test8.json",
        "tests/test9.json",
        "tests/test10.json"
    )
);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
