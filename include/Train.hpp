/*
 *  @file Train.hpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 12, 2018
 *  @brief This is the declaration of the Train class.
 */

#ifndef INCLUDE_TRAIN_HPP_
#define INCLUDE_TRAIN_HPP_

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

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
     * @brief This is the third method of the class. It trains the SVM classifier.
     */
    void trainSVM();

    /*
     * @brief This is the destructor for the class
     */
    ~Train();
};

#endif  // INCLUDE_TRAIN_HPP_
