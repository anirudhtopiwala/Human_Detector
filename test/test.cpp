/*
 *  @file test.cpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of all units tests to be conducted.
 */

#include <gtest/gtest.h>
#include <Detect.hpp>

Detect test;

TEST(DetectTest, DetectModeNameTest) {
  ASSERT_EQ("Default", test.modeName());
}

TEST(DetectTest, DetectToggleTest) {
  ASSERT_EQ("Default", test.modeName());
  test.toggleMode();
  ASSERT_EQ("Daimler", test.modeName());
}
