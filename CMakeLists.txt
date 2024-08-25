cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LeetCodeSolutions)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for the "twosum" program
add_executable(twosum 1/twosum.cpp)

# Add the executable for the "addtwonums" program
add_executable(addtwonums 2/addtwonums.cpp)
