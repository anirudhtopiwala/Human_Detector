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
 *
 * @param This constructor takes the user defined HOGDescriptor as input. It also sets the mode as Default.
 */
Detect::Detect(cv::HOGDescriptor hog_temp): m(Default), hog(), hog_user() {
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    hog_user = hog_temp;
    std::cout << "Class Detect has been Initialized" << std::endl;
}

/*
 * @brief This is the first method of the class. It toggles between the Default mode and User mode.
 */
void Detect::toggleMode() {
    m = (m == Default ? User : Default);
}

/*
 * @brief This is the second method of the class. It returns the name of the current mode.
 *
 * @return This method returns the mode name as a string.
 */
std::string Detect::modeName() const {
    return (m == Default ? "Default" : "User");
}

/*
 * @brief This is the third method of the class. It returns the bounding boxes around the humans found in the image.
 *
 * @param This method takes an image as input.
 *
 * @return This method returns a vector containing the object Rect which defines the bounding box around the detected humans.
 */
std::vector<cv::Rect> Detect::findHumans(cv::InputArray img) {
    std::vector<cv::Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, cv::Size(8,8), cv::Size(32,32), 1.05, 2, false);
    else if (m == User)
        hog_user.detectMultiScale(img, found, 0.5, cv::Size(8,8), cv::Size(32,32), 1.05, 2, false);
    return found;
}

/*
 * @brief This is the fourth method of the class. It adjusts the bounding box created around a detected human.
 *
 * @param This method takes the bounding box detected as input.
 */
void Detect::adjustBoundingBox(cv::Rect & r) {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}

/*
 * @brief This is the fifth method of the class. It is used to test the trained classifier.
 *
 * @param The first parameter defines the mode to be used. In general, it will use "User" mode.
 * @param The second parameter defines the testDir where the testing set is stored.
 * @param The third parameter gives the video filename if video is to be made.
 * @param The fourth parameter commands the method to either show or not show the images.
 */
cv::Rect Detect::testClassifier(std::string detectMode, cv::String testDir, cv::String videoFilename = "", bool displayImage = false) {
    std::cout << "Testing Trained Classifier" << std::endl;
    
    std::vector<cv::String> files;
    cv::glob(testDir, files);

    cv::VideoCapture cap;
    if (videoFilename != "") {
        if (videoFilename.size() == 1 && isdigit(videoFilename[0]))
            cap.open(videoFilename[0] - '0');
        else
            cap.open(videoFilename);
    }

    if (detectMode != modeName()) {
        toggleMode();
    }

    cv::Rect R;
    for(auto i=0;; i++) {
        cv::Mat img;
        if (cap.isOpened()) {
            cap >> img;
        } else if (i < files.size()) {
            img = cv::imread(files[i]);
        }
        if (img.empty())
            return R;

        std::vector<cv::Rect> detections = findHumans(img);
        for (std::vector<cv::Rect>::iterator j = detections.begin(); j != detections.end(); ++j) {
            cv::Rect &r = *j;
            if (files[i] == "../data/test/pedestrian_5.jpg")
                R = r;
//            cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
            adjustBoundingBox(r);
            cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        }
        if (displayImage) {
            cv::imshow("Frame" , img);
            cv::waitKey(300);
        }
    }
    return R;
}

/*
 * @brief This is the destructor for the class
 */
Detect::~Detect() {
    std::cout << "Class Detect has been Destroyed" << std::endl;
}