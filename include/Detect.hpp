/*
 *  @file Detect.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of the Detect class.
 */

#ifndef INCLUDE_DETECT_HPP_
#define INCLUDE_DETECT_HPP_

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

/*
 * @brief Detector is a class
 */
class Detect {
    enum Mode { Default, User } m;

 public:
    cv::HOGDescriptor hog, hog_user;

    /*
     * @brief This is the constructor for the class
     */
    Detect();

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
    std::vector<cv::Rect> findHumans(const cv::InputArray);

    /*
     * @brief This is the fourth method of the class. It adjusts the bounding box created around a detected human.
     *
     * @param This method takes the bounding box detected as input.
     */
    void adjustBoundingBox(cv::Rect &);

    /*
     * @brief This is the fifth method of the class. It is used to test the trained classifier.
     *
     * @param The first parameter defines the testDir where the testing set is stored.
     * @param The second parameter is the window size or the image size at which testing is done.
     * @param The third parameter commands the method to either show or not show the images.
     * @param The fourth parameter defines the mode to be used for testing the classifier.
     */
    cv::Rect testClassifier(const cv::String, const cv::Size,
                            const bool, const std::string &);

    /*
     * @brief This is the destructor for the class
     */
    ~Detect();
};

#endif  // INCLUDE_DETECT_HPP_
