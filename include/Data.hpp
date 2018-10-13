/*
 *  @file Data.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 12, 2018
 *  @brief This is the declaration of the Data class.
 */

#ifndef _INCLUDE_DATA_H_
#define _INCLUDE_DATA_H_

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

/*
 * @brief Data is a class
 */
class Data {
    public:
    std::vector<cv::Mat> imgList;

    /*
     * @brief This is the constructor for the class
     */
    Data(std::string);

    /*
     * @brief This is the second method of the class. It loads the images (test set, training set) as per the string defined.
     *
     * @param The first parameter is the directory name from where the images are to be loaded.
     * @param The second parameter is a boolean which states whether to show the images being loaded or not. By default, it is set to false.
     */
    void loadImages(const cv::String &, bool);
    
    /*
     * @brief This is the third method of the class. It returns if a human is found in the image.
     *
     * @param 
     * @param 
     * @param 
     */
    void sampleImages(const cv::Size &);

    /*
     * @brief This is the destructor for the class
     */
    ~Data();
};

#endif  // _INCLUDE_DATA_H_
