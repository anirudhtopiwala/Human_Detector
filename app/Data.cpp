/*
 *  @file Data.cpp
 *  Copyright [2018]
 *  @author1 Ghost1995 [Ashwin Goyal] - stub
 *  @author2 anirudhtopiwala [Anirudh Topiwala] - Implementation
 *  @date Oct 12, 2018
 *  @brief This is the implementation of the Data class
 */

#include <Data.hpp>

/*
 * @brief This is the constructor for the class
 */
Data::Data(std::string classObjective) {
   
}

/*
 * @brief This is the first method of the class. It loads the images (test set, training set (positive, negative)) as per the string defined.
 *
 * @param The first parameter is the directory name from where the images are to be loaded.
 * @param The second parameter is a boolean which states whether to show the images being loaded or not. By default, it is set to false.
 */
void Data::loadImages(const cv::String & dirName, bool showImages = false) {
    
}

/*
 * @brief This is the third method of the class. It returns if a human is found in the image.
 *
 * @param The first parameter defines all the images read.
 * @param The second parameter reduces the images into samples of the size roi
 * @param The third parameter is the size of the ROI.
 */
void Data::sampleImages(const cv::Size & size) {
    
}

/*
 * @brief This is the destructor for the class
 */
Data::~Data() {
}