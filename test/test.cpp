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

TEST(DataTest, DataLoadImagesTest) {
  Data test;
  test.loadImages("../data/test/imgs");
  ASSERT_GT(test.imgList.size(), 0);
}

TEST(DataTest, DataSampleImagesTest) {
  Data test;
  test.loadImages("../data/test/imgs");
  std::vector<cv::Mat> orgDataList = test.imgList;
  test.sampleImages(cv::Size(100, 100));
  std::vector<cv::Mat> newDataList = test.imgList;
  bool match = false, checkSize = true;
  for (auto i = 0; i < orgDataList.size(); i++) {
    if (orgDataList[i].size() == newDataList[i].size()) {
      match = true;
      break;
    }
    if (newDataList[i].size() != cv::Size(100, 100)) {
      checkSize = false;
      break;
    }
  }
  ASSERT_TRUE((!match) & (checkSize));
}

TEST(DataTest, DataLoadAnnotationsTest) {
  Data test;
  test.loadAnnotations("../data/test/annotations", "../data/test/pos");
  ASSERT_TRUE((test.anotations.size() == 11) & (test.trainImages.size() == 11));
}

TEST(DataTest, DataLoadPositiveImagesTest) {
  Data test;
  test.loadAnnotations("../data/test/annotations", "../data/test/pos");
  test.loadImages();
  ASSERT_EQ(test.imgList.size(), 11);
}

TEST(TrainTest, TrainGetHOGTest) {
  Data testData;
  Train test;
  testData.loadImages("../data/test/imgs");
  test.getHOGfeatures(cv::Size(96, 160), testData.imgList);
  ASSERT_GT(test.gradientList.size(), 0);
}

TEST(TrainTest, TrainSVMTest) {
  Data testData;
  Train test;
  testData.loadImages("../data/test/imgs");
  test.getHOGfeatures(cv::Size(96, 160), testData.imgList);
  test.labels.assign(test.gradientList.size()/2, 1);
  test.labels.insert(test.labels.end(),
                     test.gradientList.size() - test.labels.size(), -1);
  bool cond = test.classifier->getSupportVectors().empty();
  test.trainSVM();
  cond = cond & !test.classifier->getSupportVectors().empty();
  ASSERT_TRUE(cond);
}

TEST(TrainTest, TrainGetClassifierTest) {
  Data testData;
  Train test;
  testData.loadImages("../data/test/imgs");
  test.getHOGfeatures(cv::Size(96, 160), testData.imgList);
  test.labels.assign(test.gradientList.size()/2, 1);
  test.labels.insert(test.labels.end(),
                     test.gradientList.size() - test.labels.size(), -1);
  test.trainSVM();
  ASSERT_NE(test.getClassifier().size(), 0);
}

TEST(DetectTest, DetectHumansTest) {
  Detect test;
  cv::Rect orgBox(115, 6, 238, 475);  // [238 x 475 from (115, 6)]
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  std::vector<cv::Rect> found = test.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  ASSERT_LT(orgBox.area() - (orgBox & r).area(), 500);
}

TEST(DetectTest, DetectAdjustBoxTest) {
  Detect test;
  cv::Rect newBox(139, 39, 190, 380);  // [190 x 380 from (139, 39)]
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  std::vector<cv::Rect> found = test.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  test.adjustBoundingBox(r);
  ASSERT_LT(newBox.area() - (newBox & r).area(), 500);
}

TEST(DetectTest, DetectTestClassifierTest) {
  Detect test1, test2;
  std::string imageName("../data/test/imgs/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName);
  std::vector<cv::Rect> found = test1.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &orgBox = *i;
  test2.hog_user.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
  cv::Rect r = test2.testClassifier("../data/test/imgs", false);
  ASSERT_LT(orgBox.area() - (orgBox & r).area(), 500);
}
