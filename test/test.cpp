/*
 *  @file test.cpp
 *  Copyright [2018]
 *  @author Ghost1995 [Ashwin Goyal]
 *  @author anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of all units tests to be conducted.
 */

#include <gtest/gtest.h>
#include <Data.hpp>
#include <Train.hpp>
#include <Detect.hpp>

// Unit test for first method of class Data
TEST(DataTest, DataLoadPosImagesTest) {
  Data test;
  test.loadPosImages("../data/test/annotations", "../data/test/pos",
                                          cv::Size(200, 200), false);
  // Check if the images were read
  ASSERT_GT(test.posImgList.size(), 0);
  bool sizeMatch = true;
  for (auto img : test.posImgList)
    if (img.size() != cv::Size(200, 200)) {
      sizeMatch = false;
      break;
    }
  // Check if the images read have a size of 200 x 200
  ASSERT_TRUE(sizeMatch);
}

// Unit test for second method of class Data
TEST(DataTest, DataLoadNegImagesTest) {
  Data test;
  test.loadNegImages("../data/test/imgs", cv::Size(200, 200));
  // Check if the images were read
  ASSERT_GT(test.negImgList.size(), 0);
  bool sizeMatch = true;
  for (auto img : test.negImgList)
    if (img.size() != cv::Size(200, 200)) {
      sizeMatch = false;
      break;
    }
  // Check if the images read have a size of 200 x 200
  ASSERT_TRUE(sizeMatch);
}

// Unit test for first method of class Train
TEST(TrainTest, TrainGetClassifierTest) {
  Data testData;
  Train test;
  testData.loadNegImages("../data/test/imgs", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), testData.negImgList);
  test.labels.assign(test.gradientList.size()/2, 1);
  test.labels.insert(test.labels.end(),
                     test.gradientList.size() - test.labels.size(), -1);
  test.trainSVM(false, "");
  // Check if the getClassifier gives a non-empty output
  ASSERT_NE(test.getClassifier().size(), 0);
}

// Unit test for second method of class Train
TEST(TrainTest, TrainGetHOGTest) {
  Data testData;
  Train test;
  testData.loadNegImages("../data/test/imgs", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), testData.negImgList);
  // Check if the gradientList is being filled
  ASSERT_GT(test.gradientList.size(), 0);
}

// Unit test for third method of class Train
TEST(TrainTest, TrainSVMTest) {
  Data testData;
  Train test;
  testData.loadNegImages("../data/test/imgs", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), testData.negImgList);
  test.labels.assign(test.gradientList.size()/2, 1);
  test.labels.insert(test.labels.end(),
                     test.gradientList.size() - test.labels.size(), -1);
  // Check if the classifier is empty initially
  ASSERT_TRUE(test.classifier->getSupportVectors().empty());
  test.trainSVM(false, "");
  // Check if there is the classifier is non-empty after training
  ASSERT_TRUE(!test.classifier->getSupportVectors().empty());
}

// Unit test for first method of class Detect
TEST(DetectTest, DetectToggleTest) {
  Detect test;
  test.toggleMode();
  // Check if the mode changed to User
  ASSERT_EQ("User", test.modeName());
}

// Unit test for second method of class Detect
TEST(DetectTest, DetectModeNameTest) {
  Detect test;
  // Check if the mode is initialized to Default
  ASSERT_EQ("Default", test.modeName());
}

// Unit test for third method of class Detect
TEST(DetectTest, DetectHumansTest) {
  Detect test;
  cv::Rect orgBox(124, 28, 222, 444);  // [222 x 444 from (124, 28)]
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  std::vector<cv::Rect> found = test.findHumans(img);
  cv::Rect &r1 = found.front();
  // Check if the detected box is close to the ground truth in Default Mode
  ASSERT_LT(orgBox.area() - (orgBox & r1).area(), 500);
  test.toggleMode();
  found = test.findHumans(img);
  cv::Rect &r2 = found.front();
  // Check if the detected box is close to the ground truth in User Mode
  ASSERT_LT(orgBox.area() - (orgBox & r2).area(), 500);
  // Check if the detected boxes using either methods are close to each other
  ASSERT_LT(r1.area() - (r1 & r2).area(), 500);
}

// Unit test for fourth method of class Detect
TEST(DetectTest, DetectAdjustBoxTest) {
  Detect test;
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  std::vector<cv::Rect> found = test.findHumans(img);
  cv::Rect &r = found.front();
  cv::Rect orgBox = r;
  test.adjustBoundingBox(r);
  // Check if the bounding box has reduced after adjustment
  ASSERT_LT(r.area(), orgBox.area());
}

// Unit test for fifth method of class Detect
TEST(DetectTest, DetectTestClassifierTest) {
  Detect test;
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  cv::resize(img, img, cv::Size(200, 200));
  std::vector<cv::Rect> found = test.findHumans(img);
  cv::Rect &orgBox = found.front();
  cv::Rect r = test.testClassifier("../data/test/imgs", cv::Size(200, 200),
                                                            false, "User");
  // Check if the bounding box computed by the two methods are close
  ASSERT_LT(orgBox.area() - (orgBox & r).area(), 500);
}
