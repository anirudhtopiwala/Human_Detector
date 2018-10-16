/*
 * MIT License
 * 
 * Copyright (c) 2018 Anirudh Topiwala
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
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
