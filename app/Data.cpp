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
 */
void Data::loadImages() {
    for (auto i = 0; i < anotations.size(); i++) {
        cv::Mat img = cv::imread(trainImages[i]);
        img = img(anotations[i]);
        if (img.empty()) {
            std::cout << trainImages[i] << " is invalid!" << std::endl;
            continue;
        }
        // cv::imshow("frame",img);
        // cv::waitKey(10);
        imgList.push_back(img);
    }
}

/*
 * @brief This is the overloaded first method of the class. It loads the images, that is, training set - negative - from the directory given as a string input.
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
 * @brief This is the second method of the class. It extracts sample images from the loaded images.
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
    unsigned int seed = time(NULL);
    srand(seed);

    for (auto data : imgList) {
        if (data.cols > box.width && data.rows > box.height) {
            box.x = rand_r(&seed) % (data.cols - size_x);
            box.y = rand_r(&seed) % (data.rows - size_y);
            cv::Mat roi = data(box);
            temp.push_back(roi.clone());
        }
    }
    imgList = temp;
}

/*
 * @brief This is the third method of the class. It loads the annotations to be used when loading positive training set.
 *
 * @param The first parameter defines the path to the directory where all annotations are defined.
 * @param The second parameter defines the path to the directory where all positive images are stored.
 */
void Data::loadAnnotations(const cv::String annotPath,
                           const cv::String  posDir) {
    std::string line, value;  // Line stores lines of the file
                              // and value stores characters of the line
    int j = 0;  // Iterate through characters
    int n = 0;  // Iterate through ,()-...
    char v;  // Stores variable value as a char for making comparisons easy

    // Stores rectangles for each image
    std::vector<int> bbValues;  // Bounding box values (xmin,ymin,xmax,ymax)

    std::vector<cv::String> filesAnnot, files;
    cv::glob(annotPath, filesAnnot);
    cv::glob(posDir, files);

    std::cout << "Reading anotations from " << annotPath << std::endl;

    for (auto k = 0; k < files.size(); k++) {
        std::ifstream inputFile;  // Declare input file with image path
        inputFile.open(filesAnnot[k]);
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
                    // if true, push back acumulated value
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
                anotations.push_back(rect);
                trainImages.push_back(files[k]);
                bbValues.clear();
           }
           i++;  // Next line
        }
        // std::cout << "File name: " << imgName << std::endl;
        inputFile.close();
    }
    // std::cout << "annotSize" << anotations.size() << std::endl;
    // std::cout << "files" << trainImages.size() << std::endl;
}

/*
 * @brief This is the destructor for the class
 */
Data::~Data() {
    std::cout << "Class Data has been Destroyed" << std::endl;
}
