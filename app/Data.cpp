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
Data::Data() {
    std::cout << "Class Data has been Initialized" << std::endl;
}

/*
 * @brief This is the first method of the class. It loads the images, that is, training set - positive.
 *
 * @param The first parameter defines the path to the directory where all annotations are defined.
 * @param The second parameter defines the path to the directory where all positive images are stored.
 * @param The third parameter defines the size of the window to be used for resizing the images.
 * @param The fourth parameter commands the method to either show or not show the loaded images.
 */
void Data::loadPosImages(const cv::String anotPath, const cv::String  posDir,
                         const cv::Size size, const bool dispImg = false) {
    std::string line;  // line stores lines of the file
    std::string value;  // value stores characters of the line
    int j = 0;  // Iterate through characters
    int n = 0;  // Iterate through ,()-...
    char v;  // Stores variable value as a char for making comparisons easy

    // Stores rectangles for each image
    std::vector<int> bbValues;  // Bounding box values (xmin,ymin,xmax,ymax)

    // Stores individual file names in respective directories
    std::vector<cv::String> filesAnnot, files;
    // Extract file names from respective directories
    cv::glob(anotPath, filesAnnot);
    cv::glob(posDir, files);

    std::cout << "Reading annotations from " << anotPath << std::endl;
    for (auto k = files.begin(), l = filesAnnot.begin();
              k != files.end(), l != filesAnnot.end(); k++, l++) {
        std::ifstream inputFile;  // Declare input file with image path
        inputFile.open(*l);
        int i = 0;  // Iterate through lines
        while (!inputFile.eof()) {  // Until end of file
            getline(inputFile, line);  // Get lines one by one
            // Line number 17,24,31,38...have bounding boxes coordinates
            if ((i >= 17) && ((i - 17) % 7 == 0)) {
                j = 69;
                // Start from character num 69 which is first value of Xmin
                v = line[j];
                while (j < line.size()) {  // Until end of line
                    if ((v == '(') || (v == ',') || (v == ')') ||
                        (v == ' ') || (v == '-')) {
                    // if true, push back acumulated value, if it exists
                        if (n == 0) {
                            bbValues.push_back(stoi(value));
                            // stoi converts string to integer
                            value.clear();
                        }
                        n++;
                    } else {
                        value += v;  // Append new number
                        // Reset in order to know that a number has been read
                        n = 0;
                    }
                    j++;
                    v = line[j];  // Read next character
                }
                // Build a rectangle rect(xmin,ymin,xmax-xmin,ymax-ymin)
                cv::Rect rect(bbValues[0], bbValues[1],
                              bbValues[2] - bbValues[0],
                              bbValues[3] - bbValues[1]);
                // Read the image
                cv::Mat img = cv::imread(*k);
                // Check if the image is empty
                if (img.empty()) {
                    std::cout << *k << " is invalid!" << std::endl;
                    continue;
                }
                // Extract the human as per the annotations
                img = img(rect);
                // Resize the image to make all images of the same size
                cv::resize(img, img, size);
                // Display loaded images, if asked
                if (dispImg) {
                    cv::imshow(*k, img);
                    cv::waitKey(10);
                }
                // Store the images in a list
                posImgList.push_back(img);
                // Clear bbValues before extracting next rectangle
                bbValues.clear();
           }
           i++;  // Next line
        }
        inputFile.close();
        l++;
    }
}

/*
 * @brief This is the second method of the class. It loads the images, that is, training set - negative.
 *
 * @param The first parameter defines the directory from where the images are to be loaded.
 * @param The second parameter defines the size of the window to be used for sampling the images.
 */
void Data::loadNegImages(const cv::String dirName, const cv::Size size) {
    // Stores individual file names in the directory
    std::vector<cv::String> files;
    // Extract file names from the directory
    cv::glob(dirName, files);

    // Read Negative Images
    for (auto imgName : files) {
        // Read the image
        cv::Mat img = cv::imread(imgName);
        // Check if image was read
        if (img.empty()) {
            std::cout << imgName << " is invalid!" << std::endl;
            continue;
        }
        // Resize the image
        cv::resize(img, img, size);
        // Store the image in a list
        negImgList.push_back(img);
    }
}

/*
 * @brief This is the destructor for the class
 */
Data::~Data() {
    std::cout << "Class Data has been Destroyed" << std::endl;
}
