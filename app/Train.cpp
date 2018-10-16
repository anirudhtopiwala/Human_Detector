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
 *  @file Train.cpp
 *  Copyright [2018]
 *  @author1 Ghost1995 [Ashwin Goyal] - stub
 *  @author2 anirudhtopiwala [Anirudh Topiwala] - Implementation
 *  @date Oct 12, 2018
 *  @brief This is the implementation of class Train
 */

#include <Train.hpp>

/*
 * @brief This is the constructor for the class
 */
Train::Train() {
    // Initialize classifier
    classifier = cv::ml::SVM::create();
    // Default values to train SVM
    classifier->setCoef0(0.0);
    classifier->setDegree(3);
    classifier->setTermCriteria(cv::TermCriteria(
    cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 1000, 1e-3));
    classifier->setGamma(0);
    classifier->setKernel(cv::ml::SVM::LINEAR);
    classifier->setNu(0.5);
    classifier->setP(0.1); // for EPSILON_SVR, epsilon in loss function?
    classifier->setC(0.01); // From paper, soft classifier
    classifier->setType(cv::ml::SVM::EPS_SVR);
    std::cout << "Class Train has been Initialized" << std::endl;
}

/*
 * @brief This is the first method of the class. It outputs the support vectors of the classifier.
 *
 * @result The output is a float vector containing the support vectors of the classifier.
 */
std::vector<float> Train::getClassifier() {
    // get the support vectors
    cv::Mat svm = classifier->getSupportVectors();
    // get the decision function
    cv::Mat alpha, svidx;
    double rho = classifier->getDecisionFunction(0, alpha, svidx);

    // create a variable to return the support vectors in desired type
    std::vector<float> hogDetector(svm.cols + 1);
    memcpy(&hogDetector[0], svm.ptr(), svm.cols*sizeof(hogDetector[0]));
    hogDetector[svm.cols] = static_cast<float>(- rho);
    return hogDetector;
}

/*
 * @brief This is the second method of the class. It extracts HOG features from the given images.
 *
 * @param The first parameter is the window size to be used for HOG feature extraction.
 * @param The second parameter is a vector containing the images whose feature are to be extracted.
 */
void Train::getHOGfeatures(const cv::Size windowSize,
                           const std::vector<cv::Mat> & imgList) {
    cv::HOGDescriptor hog;
    hog.winSize = windowSize;
    hog.cellSize = cv::Size(4, 4);
    cv::Mat gray;
    std::vector<float> descriptors;

    for (auto data : imgList)
        if (data.cols >= windowSize.width && data.rows >= windowSize.height) {
            // convert image to grayscale
            cvtColor(data, gray, cv::COLOR_BGR2GRAY);
            // extract hog features
            hog.compute(gray, descriptors);
            // store hog features
            gradientList.push_back(cv::Mat(descriptors).clone());
            // Now flip the images
            cv::flip(gray, gray, 1);
            hog.compute(gray, descriptors);
            gradientList.push_back(cv::Mat(descriptors).clone());
        }
}

/*
 * @brief This is the third method of the class. It trains the SVM classifier.
 *
 * @param The first parameter is a boolean which commands the method to either save or not save the classifier.
 * @param The second parameter is the name of the classifier if it is to be saved.
 */
void Train::trainSVM(const bool saveClassifier = false,
                     const cv::String classifierName = "") {
    // make sure all HOG features are row vectors for the train function of SVM
    const int rows = static_cast<int>(gradientList.size());
    const int cols = static_cast<int>(std::max(gradientList[0].cols,
                                               gradientList[0].rows));
    cv::Mat temp(1, cols, CV_32FC1), trainData(rows, cols, CV_32FC1);
    for (auto index = 0; index < gradientList.size(); index++) {
        if (gradientList[index].cols == 1) {
            transpose(gradientList[index], temp);
            temp.copyTo(trainData.row(static_cast<int>(index)));
        } else if (gradientList[index].rows == 1) {
            gradientList[index].copyTo(trainData.row(static_cast<int>(index)));
        }
    }

    // Training Starts
    std::cout << "Training SVM Classifier" << std::endl;
    classifier->train(trainData, cv::ml::ROW_SAMPLE, labels);
    std::cout << "Training Finshed" << std::endl;
    // Save the classifier if asked
    if (saveClassifier)
        classifier->save(classifierName);
}

/*
 * @brief This is the destructor for the class
 */
Train::~Train() {
    std::cout << "Class Train has been Destroyed" << std::endl;
}
