// File: FuelConsumption.cpp

#include "gtest/gtest.h"
#include "FuelConsumption.cpp" // Include the source file with your class

TEST(CarTest, CalculateFuelEfficiencyWithRuntimeError) {
    // Creating a car object
    Car myCar("Gasoline", 2025, 0.0); // Intentional mathematical defect: fuel efficiency should be undefined (division by zero)

    // Checking initial information
    EXPECT_EQ(myCar.getModel(), "Gasoline");
    EXPECT_EQ(myCar.getYear(), 2025);
    EXPECT_EQ(myCar.getFuelConsumed(), 0.0);

    // Attempting to calculate fuel efficiency with intentional runtime error
    EXPECT_THROW(myCar.calculateFuelEfficiencyWithRuntimeError(), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
