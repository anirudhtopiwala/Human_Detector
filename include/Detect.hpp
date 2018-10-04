/*
 *  @file Detect.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the declaration of the Detect class.
 */

#ifndef _INCLUDE_DETECT_H_
#define _INCLUDE_DETECT_H_

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <iostream>
#include <iomanip>
#include <string>

/*
 * @brief Detector is a class
 *
 * @param1 Grades[5] stores the student grades for 5 students.
 * @param2 ChangeGrade() will change the specific student grade depending upon the input number.
 * @param3 ComputeAverage() compute the average grade of all the students.
 */

class Detect {
    enum Mode {Default, Daimler} m;
    cv::HOGDescriptor hog, hog_d;

    public:
    /*
     * @brief This is the constructor for the class
     */
    Detect();

    /*
     * @brief This is the first method of the class. It toggles between the Default mode and Daimler mode.
     */
    void toggleMode();

    /*
     * @brief This is the second method of the class. It returns the name of the current mode.
     *
     * @return This method returns the mode name as a string.
     */
    std::string modeName() const;

    /*
     * @brief This is the third method of the class. It returns if a human is found in the image.
     *
     * @ param This method takes an image as input.
     *
     * @return This method returns a vector containing the object Rect which defines the bounding box around the detected humans.
     */
    std::vector<cv::Rect> findHumans(cv::InputArray);

    /*
     * @brief This is the fourth method of the class. It adjust the bounding box created around a detected human.
     *
     * @ param This method takes the bounding box detected as input.
    */
    void adjustBoundingBox(cv::Rect);

    /*
     * @brief This is the destructor for the class
     */
    ~Detect();
};

#endif  // _INCLUDE_DETECT_H_
