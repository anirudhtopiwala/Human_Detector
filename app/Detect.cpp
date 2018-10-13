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
    // hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    // hog_d.setSVMDetector(cv::HOGDescriptor::getDaimlerPeopleDetector());
    std::cout<<"whats up"<<std::endl;
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
 * @param This method takes an image as input.
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
 * @param This method takes the bounding box detected as input.
 */
void Detect::adjustBoundingBox(cv::Rect & r) {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}
/*
 * @brief This is the fifth method of the class. It is used to test the trained detector.
 *
 * @param This method takes the bounding box detected as input.
 */

void Detect::testTrainedDetector(cv::String objDetFilename, cv::String testDir, cv::String videofilename = "") {
    std::cout << "Testing trained detector..." << std::endl;
    cv::HOGDescriptor hog;
    hog.load(objDetFilename);

    std::vector<cv::String> files;
    cv::glob(testDir, files);

    // int delay = 0;
    // cv::VideoCapture cap;

    // if (videofilename != "") {
    //     if (videofilename.size() == 1 && isdigit(videofilename[0]))
    //         cap.open(videofilename[0] - '0');
    //     else
    //         cap.open(videofilename);
    // }

    // objDetFilename = "testing " + objDetFilename;
    // cv::namedWindow(objDetFilename, cv::WINDOW_NORMAL);

    // for( size_t i=0;; i++ ) {
    //     cv::Mat img;

    //     if (cap.isOpened()) {
    //         cap >> img;
    //         delay = 1;
    //     } else if (i < files.size()) {
    std::vector<cv::Rect> detections;
    std::vector<double> foundWeights;
    int j=1 ;
    for (auto imgName : files) {
        cv::Mat img = cv::imread(imgName);
        if (img.empty()) {  // invalid image, skip it.
           std::cout << imgName << " is invalid!" << std::endl;
           continue;
        }
        std::cout<< j<< std::endl;
        std::vector<cv::Rect> found = findHumans(img);
        for (std::vector<cv::Rect>::iterator i = found.begin(); i != found.end(); ++i) {
            cv::Rect &r = *i;
            std::cout << r << std::endl;
            cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
            adjustBoundingBox(r);
            std::cout << r << std::endl;
            cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        }
        cv::imshow("Frame" , img);
        cv::waitKey(3000);
        j+=1;    
    }

}

/*
 * @brief This is the destructor for the class
 */
Detect::~Detect() {
    std::cout << "Class is destroyed" << std::endl;
}