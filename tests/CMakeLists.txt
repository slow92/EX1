cmake_minimum_required(VERSION 2.6)

add_subdirectory(googletest)

add_executable(RangeValueTest RangeValueTest.cpp)

target_include_directories(RangeValueTest PRIVATE ${gtest_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR})

target_link_libraries(RangeValueTest gtest_main RangeValue)
