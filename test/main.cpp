/*
 *  @file main.cpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the main file which commands to run all the tests in test.cpp
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}