cmake_minimum_required(VERSION 3.10)

project(FuelConsumptionTest)

# Set path to Google Test library
set(GTEST_DIR "C:/googletest-main/googletest-main/build/lib/Debug" CACHE PATH "Path to the Google Test library")

# Include directories
include_directories(src)

# Add your source files
add_executable(FuelConsumptionTest src/FuelConsumption.cpp src/GtestFuelConsumption.cpp)

# Locate GTest
find_package(GTest REQUIRED)

# Include directories for GTest
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files for GTest
add_executable(FuelConsumptionTestGTest src/GtestFuelConsumption.cpp)

# Link GTest and your code
target_link_libraries(FuelConsumptionTest ${GTEST_DIR}/gtest.lib ${GTEST_DIR}/gtest_main.lib)

# Set the output directory for the executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)

