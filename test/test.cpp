/*
 *  @file test.cpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of all units tests to be conducted.
 */

#include <gtest/gtest.h>
#include <Detect.hpp>

Detect test1, test2, test3, test4;

TEST(DetectTest, DetectModeNameTest) {
  ASSERT_EQ("Default", test1.modeName());
}

TEST(DetectTest, DetectToggleTest) {
  ASSERT_EQ("Default", test2.modeName());
  test2.toggleMode();
  ASSERT_EQ("Daimler", test2.modeName());
}

TEST(DetectTest, DetectHumansTest) {
  cv::Rect orgBox(115,6,238,475);  //[238 x 475 from (115, 6)]
  std::string imageName("../data/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test3.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  std::cout << orgBox.area() - (orgBox & r).area() << std::endl;
  EXPECT_TRUE((orgBox.area() - (orgBox & r).area()) < 10);
}

TEST(DetectTest, DetectAdjustBoxTest) {
  cv::Rect newBox(139,39,190,380);  //[190 x 380 from (139, 39)]
  std::string imageName("../data/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test4.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  test2.adjustBoundingBox(r);
  std::cout << newBox.area() - (newBox & r).area() << std::endl;
  EXPECT_TRUE((newBox.area() - (newBox & r).area()) < 10);
}
