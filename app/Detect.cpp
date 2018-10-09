/*
 * @file Detect.cpp
 * @Copyright [2018]
 * @author1 Ghost1995 [Ashwin Goyal] - stub
 * @author2 anirudhtopiwala [Anirudh Topiwala] - Implementation
 * @date Oct 04, 2018
 * @brief This is the implementation of the Detect class.
 */

#include <Detect.hpp>

/*
 * @brief This is the constructor for the class
 */
Detect::Detect(): m(Default), hog(),
hog_d(cv::Size(48, 96), cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9) {
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    hog_d.setSVMDetector(cv::HOGDescriptor::getDaimlerPeopleDetector());
}

/*
 * @brief This is the first method of the class. It toggles between the Default mode and Daimler mode.
 */
void Detect::toggleMode() {
    m = (m == Default ? Daimler : Default);
}

/*
 * @brief This is the second method of the class. It returns the name of the current mode.
 *
 * @return This method returns the mode name as a string.
 */
std::string Detect::modeName() const {
    return (m == Default ? "Default" : "Daimler");
}

/*
 * @brief This is the third method of the class. It returns if a human is found in the image.
 *
 * @ param This method takes an image as input.
 *
 * @return This method returns a vector containing the object Rect which defines the bounding box around the detected humans.
 */
std::vector<cv::Rect> Detect::findHumans(cv::InputArray img) {
    std::vector<cv::Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, cv::Size(8,8),
                             cv::Size(32,32), 1.05, 2, false);
    else if (m == Daimler)
        hog_d.detectMultiScale(img, found, 0.5, cv::Size(8,8),
                               cv::Size(32,32), 1.05, 2, true);
    return found;
}

/*
 * @brief This is the fourth method of the class. It adjust the bounding box created around a detected human.
 *
 * @ param This method takes the bounding box detected as input.
 */
void Detect::adjustBoundingBox(cv::Rect & r) {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}

/*
 * @brief This is the destructor for the class
 */
Detect::~Detect() {
    std::cout << "Class is destroyed" << std::endl;
}
