cmake_minimum_required(VERSION 3.2)
project(simple_calculator) # project and executable should not necessary to match

# Optional :  We can also define C++ Standards
set(CMAKE_CXX_STANDARD 17)
# It will throw error if we are not using the minimum 
set(CMAKE_CXX_STANDARD_REQUIRED True)

# How to set variables. We can also set List as value
set(SOURCES 
src/main.cpp
calculator/src/calculator.cpp
)

include_directories(
    calculator/include
)

add_subdirectory(maths) # Go inside maths directory and look for CmakeLists

# add_executable(name_of_executable all_other_source_files)
add_executable(simplecalculator ${SOURCES})

target_link_libraries(simplecalculator maths) # How to link library