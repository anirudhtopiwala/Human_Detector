/*
 * MIT License
 * 
 * Copyright (c) 2018 Anirudh Topiwala
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
/*
 *  @file testTrain.cpp
 *  Copyright [2018]
 *  @author Ghost1995 [Ashwin Goyal]
 *  @author anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of all units tests to be conducted.
 */

#include <gtest/gtest.h>
#include <Train.hpp>

// Unit test for first method of class Train
TEST(TrainTest, getClassifierTest) {
  Train test;
  test.loadPosImages("../data/test/annotations", "../data/test/pos",
                                          cv::Size(200, 200), false);
  test.loadNegImages("../data/test/neg", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), "positive");
  size_t posCount = test.getListSize();
  test.labels.assign(posCount, 1);
  test.getHOGfeatures(cv::Size(200, 200), "negative");
  size_t negCount = test.getListSize() - posCount;
  test.labels.insert(test.labels.end(), negCount, -1);
  test.trainSVM(false, "");
  // Check if the getClassifier gives a non-empty output
  ASSERT_NE(0, test.getClassifier().size());
}

// Unit test for second method of class Train
TEST(TrainTest, getHOGfeaturesTest) {
  Train test;
  test.loadNegImages("../data/test/neg", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), "negative");
  // Check if the gradientList is being filled
  ASSERT_GT(test.getListSize(), 0);
}

// Unit test for third method of class Train
TEST(TrainTest, trainSVMTest) {
  Train test;
  test.loadPosImages("../data/test/annotations", "../data/test/pos",
                                          cv::Size(200, 200), false);
  test.loadNegImages("../data/test/neg", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), "positive");
  size_t posCount = test.getListSize();
  test.labels.assign(posCount, 1);
  test.getHOGfeatures(cv::Size(200, 200), "negative");
  size_t negCount = test.getListSize() - posCount;
  test.labels.insert(test.labels.end(), negCount, -1);
  // Check if the classifier is empty initially
  ASSERT_TRUE(test.getDefaultClassifier()->getSupportVectors().empty());
  test.trainSVM(false, "");
  // Check if there is the classifier is non-empty after training
  ASSERT_TRUE(!test.getDefaultClassifier()->getSupportVectors().empty());
  test.trainSVM(true, "../data/test/classifier/svmClassifier");
  Train test2;
  test2.setClassifier(cv::ml::SVM::load
                                    ("../data/test/classifier/svmClassifier"));
  ASSERT_TRUE(!test2.getDefaultClassifier()->getSupportVectors().empty());
}

// Unit test for fourth method of class Train
TEST(TrainTest, getListSizeTest) {
  Train test;
  test.loadNegImages("../data/test/neg", cv::Size(200, 200));
  test.getHOGfeatures(cv::Size(200, 200), "negative");
  // Check if HOG features were extracted
  ASSERT_EQ(test.getImgListSize("negative")*2, test.getListSize());
}

// Unit test for fifth method of class Train
TEST(TrainTest, setClassifierTest) {
  Train test;
  cv::Ptr<cv::ml::SVM> classifier = test.getDefaultClassifier();
  test.setClassifier(classifier);
  // Check if the classifiers are same
  ASSERT_TRUE(classifier == test.getDefaultClassifier());
}

// Unit test for sixth method of class Train
TEST(TrainTest, getDefaultClassifierTest) {
  Train test;
  // Check if the classifier retrieved is empty
  ASSERT_TRUE(test.getDefaultClassifier()->getSupportVectors().empty());
}
