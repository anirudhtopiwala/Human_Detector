/*
 *  @file test.cpp
 *  Copyright [2018]
 *  @author Ghost1995 [Ashwin Goyal]
 *  @author anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of all units tests to be conducted.
 */

#include <gtest/gtest.h>
#include <Detect.hpp>
#include <Data.hpp>
#include <Train.hpp>

Data testData1("Data for DataTest 1"), testData2("Data for DataTest 2");

TEST(DataTest, DataLoadImagesTest) {
  testData1.loadImages("../data/test");
  ASSERT_TRUE(testData1.imgList.size() > 0);
}

TEST(DataTest, DataSampleImagesTest) {
  testData2.loadImages("../data/test");
  std::vector<cv::Mat> orgDataList = testData2.imgList;
  testData2.sampleImages(cv::Size(100, 100));
  std::vector<cv::Mat> newDataList = testData2.imgList;
  int i = 0;
  bool match = false;
  for (auto data : orgDataList) {
    if (data.size() == newDataList[i].size())
      match = true;
    i++;
  }
  ASSERT_TRUE(!match);
}

Data testData3("Data for TrainTest 1"), testData4("Data for TrainTest 2"), testData5("Data for TrainTest 3");
Train trainTest1, trainTest2, trainTest3;

TEST(TrainTest, TrainGetHOGTest) {
  testData3.loadImages("../data/test");
  trainTest1.getHOGfeatures(cv::Size(96, 160), testData3.imgList);
  ASSERT_TRUE(trainTest1.gradientList.size() > 0);
}

TEST(TrainTest, TrainSVMTest) {
  testData4.loadImages("../data/test");
  trainTest2.getHOGfeatures(cv::Size(96, 160), testData4.imgList);
  size_t posCount = trainTest2.gradientList.size();
  trainTest2.labels.assign(posCount/2, 1);
  trainTest2.labels.insert(trainTest2.labels.end(), posCount - trainTest2.labels.size(), -1);
  ASSERT_TRUE(trainTest2.classifier->getSupportVectors().empty());
  trainTest2.trainSVM();
  ASSERT_TRUE(!trainTest2.classifier->getSupportVectors().empty());
}

TEST(TrainTest, TrainGetClassifierTest) {
  testData5.loadImages("../data/test");
  trainTest3.getHOGfeatures(cv::Size(96, 160), testData5.imgList);
  size_t posCount = trainTest3.gradientList.size();
  trainTest3.labels.assign(posCount/2, 1);
  trainTest3.labels.insert(trainTest3.labels.end(), posCount - trainTest3.labels.size(), -1);
  trainTest3.trainSVM();
  ASSERT_TRUE(trainTest3.getClassifier().size() != 0);
}

cv::HOGDescriptor hog;
hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
Detect test1(hog), test2(hog), test3(hog), test4(hog);
TEST(DetectTest, DetectModeNameTest) {
  ASSERT_EQ("Default", test1.modeName());
}

TEST(DetectTest, DetectToggleTest) {
  ASSERT_EQ("Default", test2.modeName());
  test2.toggleMode();
  ASSERT_EQ("User", test2.modeName());
}

TEST(DetectTest, DetectHumansTest) {
  cv::Rect orgBox(115,6,238,475);  //[238 x 475 from (115, 6)]
  std::string imageName("../data/test/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test3.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  ASSERT_TRUE((orgBox.area() - (orgBox & r).area()) < 500);
}

TEST(DetectTest, DetectAdjustBoxTest) {
  cv::Rect newBox(139,39,190,380);  //[190 x 380 from (139, 39)]
  std::string imageName("../data/test/pedestrian_5.jpg");
  cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
  std::vector<cv::Rect> found = test4.findHumans(img);
  std::vector<cv::Rect>::iterator i = found.begin();
  cv::Rect &r = *i;
  test2.adjustBoundingBox(r);
  ASSERT_TRUE((newBox.area() - (newBox & r).area()) < 500);
}
