/*
 *  @file Detect.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of the Detect class.
 */

#ifndef _INCLUDE_DETECT_H_
#define _INCLUDE_DETECT_H_

#include <opencv2/opencv.hpp>
#include <iostream>

/*
 * @brief Detector is a class
 */
class Detect {
    enum Mode { Default, User } m;
    cv::HOGDescriptor hog, hog_user;

    public:
    /*
     * @brief This is the constructor for the class
     *
     * @param This constructor takes the user defined HOGDescriptor as input. It also sets the mode as Default.
     */
    Detect(cv::HOGDescriptor);

    /*
     * @brief This is the first method of the class. It toggles between the Default mode and User mode.
     */
    void toggleMode();

    /*
     * @brief This is the second method of the class. It returns the name of the current mode.
     *
     * @return This method returns the mode name as a string.
     */
    std::string modeName() const;

    /*
     * @brief This is the third method of the class. It returns the bounding boxes around the humans found in the image.
     *
     * @param This method takes an image as input.
     *
     * @return This method returns a vector containing the object Rect which defines the bounding box around the detected humans.
     */
    std::vector<cv::Rect> findHumans(cv::InputArray);

    /*
     * @brief This is the fourth method of the class. It adjusts the bounding box created around a detected human.
     *
     * @param This method takes the bounding box detected as input.
     */
    void adjustBoundingBox(cv::Rect &);
    
    /*
     * @brief This is the fifth method of the class. It is used to test the trained classifier.
     *
     * @param The first parameter defines the mode to be used. In general, it will use "User" mode.
     * @param The second parameter defines the testDir where the testing set is stored.
     * @param The third parameter gives the video filename if video is to be made.
     * @param The fourth parameter commands the method to either show or not show the images.
     */
    cv::Rect testClassifier(std::string, cv::String, cv::String, bool);
    
    /*
     * @brief This is the destructor for the class
     */
    ~Detect();
};

#endif  // _INCLUDE_DETECT_H_