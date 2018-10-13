/*
 *  @file Data.hpp
 *  Copyright [2018] anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 12, 2018
 *  @brief This is the declaration of the Data class.
 */

#ifndef _INCLUDE_DATA_H_
#define _INCLUDE_DATA_H_

#include <opencv2/opencv.hpp>
#include <iostream>

/*
 * @brief Data is a class
 */
class Data {
    public:
    std::vector<cv::Mat> imgList;

    /*
     * @brief This is the constructor for the class
     * 
     * @param This constructor takes a string as an input which defines the objective of the class.
     */
    Data(std::string);

    /*
     * @brief This is the first method of the class. It loads the images, that is, training set - positive, negative - from the directory given as a string input.
     *
     * @param This method takes the directory name as an input from where the images are to be loaded.
     */
    void loadImages(const cv::String);
    
    /*
     * @brief This is the second method of the class. It extracts sample images from the load images.
     *
     * @param This method takes the size of the window as an input to be used for sampling the images.
     */
    void sampleImages(const cv::Size);

    /*
     * @brief This is the destructor for the class
     */
    ~Data();
};

#endif  // _INCLUDE_DATA_H_
