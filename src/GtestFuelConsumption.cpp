// File: FuelConsumption.cpp

#include "C:/googletest-main/googletest-main/googletest/include/gtest/gtest.h"
#include "FuelConsumption.cpp" // Include the source file with your class

TEST(CarTest, DisplayInfo) {
    Car myCar("Gasoline", 2025, 10.5);

    testing::internal::CaptureStdout();
    myCar.displayInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Check if the expected information is present in the output
    ASSERT_NE(output.find("Model: Gasoline"), std::string::npos);
    ASSERT_NE(output.find("Year: 2025"), std::string::npos);
    ASSERT_NE(output.find("Fuel Consumed: 10.5 liters"), std::string::npos);
}

TEST(CarTest, CalculateFuelEfficiencyWithRuntimeError) {
    Car myCar("Gasoline", 2025, 0.0); // Intentional mathematical defect: fuel efficiency should be undefined (division by zero)

    // Attempting to calculate fuel efficiency with intentional runtime error
    EXPECT_THROW(myCar.calculateFuelEfficiencyWithRuntimeError(), std::runtime_error);
}

TEST(CarTest, CalculateFuelEfficiency) {
    Car myCar("Gasoline", 2025, 10.5);

    // Calculating fuel efficiency (with mathematical defect)
    double efficiency = myCar.calculateFuelEfficiency();

    // Check if the calculated efficiency matches the expected value
    EXPECT_DOUBLE_EQ(efficiency, 1000 / 10.5); // Expected value: 1000 / 10.5
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

