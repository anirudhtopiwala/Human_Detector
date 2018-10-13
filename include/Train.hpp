/*
 *  @file Train.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 12, 2018
 *  @brief This is the declaration of the Train class.
 */

#ifndef _INCLUDE_TRAIN_H_
#define _INCLUDE_TRAIN_H_

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
 * @brief Train is a class
 */
class Train {
    public:
    cv::Ptr<cv::ml::SVM> classifier;
    std::vector<cv::Mat> gradientList;
    std::vector<int> labels;
    
    /*
     * @brief This is the constructor for the class
     */
    Train();

    /*
     * @brief This is the first method of the class. It outputs the support vectors of the classifier.
     *
     * @result The output is a float vector containing the support vectors of the classifier.
     */
    std::vector<float> getClassifier();

    /*
     * @brief This is the second method of the class. It extracts HOG features from the given images.
     *
     * @param The first parameter is the window size to be used for HOG feature extraction.
     * @param The second parameter is a vector containing the images whose feature are to be extracted.
     */
    void getHOGfeatures(const cv::Size, const std::vector<cv::Mat> &);


    /*
     * @brief This is the third method of the class. It ensures the extracted HOG features are row vectors.
     */
    void trainSVM();
    /*
     * @brief This is the destructor for the class
     */
    ~Train();
};

#endif  // _INCLUDE_TRAIN_H_