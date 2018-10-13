/*
 *  @file Data.cpp
 *  Copyright [2018]
 *  @author1 anirudhtopiwala [Anirudh Topiwala] - stub
 *  @author2 Ghost1995 [Ashwin Goyal] - Implementation
 *  @date Oct 12, 2018
 *  @brief This is the implementation of the Data class
 */

#include <Data.hpp>

/*
 * @brief This is the constructor for the class
 * 
 * @param This constructor takes a string as an input which defines the objective of the class.
 */
Data::Data(std::string classObjective) {
    std::cout << "Class Data has been Initialized to read " << classObjective << std::endl;
}

/*
 * @brief This is the first method of the class. It loads the images, that is, training set - positive, negative - from the directory given as a string input.
 *
 * @param This method takes the directory name as an input from where the images are to be loaded.
 */
void Data::loadImages(const cv::String dirName) {
    std::vector<cv::String> files;
    cv::glob(dirName, files);

    for (auto imgName : files) {
        cv::Mat img = cv::imread(imgName);
        if (img.empty()) {
            std::cout << imgName << " is invalid!" << std::endl;
            continue;
        }
        imgList.push_back(img);
    }
}

/*
 * @brief This is the second method of the class. It extracts sample images from the load images.
 *
 * @param This method takes the size of the window as an input to be used for sampling the images.
 */
void Data::sampleImages(const cv::Size size) {
    std::vector<cv::Mat> temp;
    cv::Rect box;
    box.width = size.width;
    box.height = size.height;

    const int size_x = box.width;
    const int size_y = box.height;

    for (auto data : imgList) {
        if (data.cols > box.width && data.rows > box.height) {
            box.x = rand() % (data.cols - size_x);
            box.y = rand() % (data.rows - size_y);
            cv::Mat roi = data(box);
            temp.push_back(roi.clone());
        }
    }
    imgList = temp;
}

/*
 * @brief This is the destructor for the class
 */
Data::~Data() {
    std::cout << "Class Data has been Destroyed" << std::endl;
}