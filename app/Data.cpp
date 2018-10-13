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
 */
Data::Data(std::string classObjective) {
    std::cout << "Class Data has been created to read " << classObjective << std::endl;
}

/*
 * @brief This is the first method of the class. It loads the images (test set, training set (positive, negative)) as per the string defined.
 *
 * @param The first parameter is the directory name from where the images are to be loaded.
 * @param The second parameter is a boolean which states whether to show the images being loaded or not. By default, it is set to false.
 */
void Data::loadImages(const cv::String dirName) {
    std::vector<cv::String> files;
    cv::glob(dirName, files);

    for (auto imgName : files) {
        cv::Mat img = cv::imread(imgName);
        if (img.empty()) {  // invalid image, skip it.
            std::cout << imgName << " is invalid!" << std::endl;
            continue;
        }
        imgList.push_back(img);
    }
}

/*
 * @brief This is the third method of the class. It returns if a human is found in the image.
 *
 * @param The first parameter defines all the images read.
 * @param The second parameter reduces the images into samples of the size roi
 * @param The third parameter is the size of the ROI.
 */
void Data::sampleImages(const cv::Size & size) {
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
    std::cout << "Class Data is destroyed" << std::endl;
}