/*
 *  @file Data.hpp
 *  Copyright [2018] anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 12, 2018
 *  @brief This is the declaration of the Data class.
 */

#ifndef INCLUDE_DATA_HPP_
#define INCLUDE_DATA_HPP_

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

/*
 * @brief Data is a class
 */
class Data {
 public:
    std::vector<cv::Mat> posImgList, negImgList;

    /*
     * @brief This is the constructor for the class
     */
    Data();

    /*
     * @brief This is the first method of the class. It loads the images, that is, training set - positive.
     *
     * @param The first parameter defines the path to the directory where all annotations are defined.
     * @param The second parameter defines the path to the directory where all positive images are stored.
     * @param The third parameter defines the size of the window to be used for resizing the images.
     * @param The fourth parameter commands the method to either show or not show the loaded images.
     */
    void loadPosImages(const cv::String, const cv::String,
                       const cv::Size, const bool);

    /*
     * @brief This is the second method of the class. It loads the images, that is, training set - negative.
     *
     * @param The first parameter defines the directory from where the images are to be loaded.
     * @param The second parameter defines the size of the window to be used for sampling the images.
     */
    void loadNegImages(const cv::String, const cv::Size);

    /*
     * @brief This is the destructor for the class
     */
    ~Data();
};

#endif  // INCLUDE_DATA_HPP_
