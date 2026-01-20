cmake_minimum_required(VERSION 3.2)
project(maths)

# Optional :  We can also define C++ Standards
set(CMAKE_CXX_STANDARD 17)
# It will throw error if we are not using the minimum 
set(CMAKE_CXX_STANDARD_REQUIRED True)

# include_directories(include/)

set(SOURCES 
src/maths.cpp
)

add_library(maths STATIC ${SOURCES}) #on windows it will create .lib bu ton linux it will create .so 

target_include_directories(maths PUBLIC include)
# target_include_directories(maths PRIVATE include)