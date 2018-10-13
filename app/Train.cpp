/*
 *  @file Train.cpp
 *  Copyright [2018]
 *  @author1 Ghost1995 [Ashwin Goyal] - stub
 *  @author2 anirudhtopiwala [Anirudh Topiwala] - Implementation
 *  @date Oct 12, 2018
 *  @brief This is the implementation of class Train
 */

#include <Train.hpp>

/*
 * @brief This is the constructor for the class
 */
Train::Train() {
}

/*
 * @brief This is the first method of the class. It outputs the support vectors of the classifier.
 *
 * @result The output is a float vector containing the support vectors of the classifier.
 */
std::vector<float> Train::getClassifier() {
}

/*
 * @brief This is the second method of the class. It extracts HOG features from the given images.
 *
 * @param The first parameter is the window size to be used for HOG feature extraction.
 * @param The second parameter is a vector containing the images whose feature are to be extracted.
 */
void Train::getHOGfeatures(const cv::Size windowSize, const std::vector<cv::Mat> & imgList) {
}

/*
 * @brief This is the third method of the class. It ensures the extracted HOG features are row vectors.
 */
void Train::trainSVM() {
}

/*
 * @brief This is the destructor for the class
 */
Train::~Train() {
}