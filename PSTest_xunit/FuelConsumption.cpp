// File: runtime_error_with_mathematical_defect_car.cpp

#include <iostream>
#include <string>

class Car {
public:
    Car(std::string model, int year, double fuelConsumed) : model(model), year(year), fuelConsumed(fuelConsumed) {}

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getFuelConsumed() const {
        return fuelConsumed;
    }

    // Introduce a mathematical defect: Incorrect calculation of fuel efficiency
    double calculateFuelEfficiency() const {
        // Incorrect calculation: fuel efficiency = distance / fuelConsumed
        return 1000 / fuelConsumed; // Should be fuelConsumed / distance
    }

    // Introduce a runtime error: Simulate division by zero
    double calculateFuelEfficiencyWithRuntimeError() const {
        if (fuelConsumed == 0) {
            throw std::runtime_error("Division by zero");
        }
        return 1000 / fuelConsumed; // Intentional runtime error if fuelConsumed is 0
    }

    void displayInfo() const {
        std::cout << "Model: " << model << ", Year: " << year << ", Fuel Consumed: " << fuelConsumed << " liters\n";
    }

private:
    std::string model;
    int year;
    double fuelConsumed;
};
