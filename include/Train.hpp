/*
 * MIT License
 * 
 * Copyright (c) 2018 Anirudh Topiwala
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
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
#include "Data.hpp"

/*
 * @brief Train is a class
 */
class Train : public Data {
 private:
    cv::Ptr<cv::ml::SVM> classifier;
    std::vector<cv::Mat> gradientList;

 public:
    std::vector<int> labels;

    /*
     * @brief This is the constructor for the class
     */
    Train();

    /*
     * @brief This is the first method of the class. It outputs the support
     *        vectors of the classifier.
     *
     * @result The output is a float vector containing the support vectors of
     *         the classifier.
     */
    std::vector<float> getClassifier();

    /*
     * @brief This is the second method of the class. It extracts HOG features
     *        from the given images.
     *
     * @param The first parameter is the window size to be used for HOG feature
     *        extraction.
     * @param The second parameter is a vector containing the images whose
     *        feature are to be extracted.
     */
    void getHOGfeatures(const cv::Size, const cv::String);

    /*
     * @brief This is the third method of the class. It trains the SVM
     *        classifier.
     *
     * @param The first parameter is a boolean which commands the method to
     *        either save or not save the classifier.
     * @param The second parameter is the name of the classifier if it is to be
     *        saved.
     */
    void trainSVM(const bool, const cv::String);

    /*
     * @brief This is the fourth method of the class. It gives the size of the
     *        gradient list.
     *
     * @return This function outputs the size of the gradient list.
     */
    int getListSize();

    /*
     * @brief This is the fifth method of the class. It sets the classifier for
     *        the class.
     *
     * @param This function takes the classifier as input.
     */
    void setClassifier(const cv::Ptr<cv::ml::SVM>);

    /*
     * @brief This is the sixth method of the class. It returns the classifier
     *        for the class.
     *
     * @return This function returns the classifier.
     */
    cv::Ptr<cv::ml::SVM> getDefaultClassifier();

    /*
     * @brief This is the destructor for the class
     */
    ~Train();
};

#endif  // INCLUDE_TRAIN_HPP_
