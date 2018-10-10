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
  test.toggleMode();
}

TEST(DetectTest, DetectHumansTest) {
  cv::Rect orgBox(115,6,238,475);  //[238 x 475 from (115, 6)]
  std::string imageName("../data/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  ASSERT_TRUE(orgBox == r);
}

TEST(DetectTest, DetectAdjustBoxTest) {
  cv::Rect newBox(139,39,190,380);  //[190 x 380 from (139, 39)]
  std::string imageName("../data/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
  test.adjustBoundingBox(r);
  cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
  cv::imshow("People detector", img);
  cv::waitKey(1000);
  ASSERT_TRUE(newBox == r);
}
