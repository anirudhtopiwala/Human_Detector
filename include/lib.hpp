//Copyright (c) 2018 Anirudh Topiwala
/** @file lib.hpp
 * @brief lib.hpp It consisits of class defenition of the required classes.
 *
 * Details.
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <iostream>
#include <iomanip>
#include <string>
using namespace cv;
using namespace std;
/**

 * @brief Detector is a class

 * @param1 Grades[5] stores the student grades for 5 students.
 * @param2 ChangeGrade() will change the specific student grade depending upon the input number.
 * @param3 ComputeAverage() compute the average grade of all the students.

 */

class Detector
{
    enum Mode { Default, Daimler } m;
    HOGDescriptor hog, hog_d;
public:
	/**
	* Constructor
	*/

    Detector() : m(Default), hog(), hog_d(Size(48, 96), Size(16, 16), Size(8, 8), Size(8, 8), 9)
    {
        hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
        hog_d.setSVMDetector(HOGDescriptor::getDaimlerPeopleDetector());
    }
	/**
	* @brief Method 1 = detect
	*/

    void toggleMode() { m = (m == Default ? Daimler : Default); }
    string modeName() const { return (m == Default ? "Default" : "Daimler"); }
    vector<Rect> detect(InputArray img)
    {
        // Run the detector with default parameters. to get a higher hit-rate
        // (and more false alarms, respectively), decrease the hitThreshold and
        // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
        vector<Rect> found;
        if (m == Default)
            hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2, false);
        else if (m == Daimler)
            hog_d.detectMultiScale(img, found, 0.5, Size(8,8), Size(32,32), 1.05, 2, true);
        return found;
    }
    /**
    * Method 2 = adjustRect
    */
    void adjustRect(Rect & r) const
    {
        // The HOG detector returns slightly larger rectangles than the real objects,
        // so we slightly shrink the rectangles to get a nicer output.
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
    }
};
