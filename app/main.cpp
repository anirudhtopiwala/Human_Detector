/*
 *  @file main.cpp
 *  Copyright [2018]
 *  @author1 Ghost1995 [Ashwin Goyal]
 *  @author2 anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 04, 2018
 *  @brief This is the main file which runs the detection algorithm
 */

#include <Data.hpp>
#include <Train.hpp>
#include <Detect.hpp>

/*
 * @brief This is the main function to call the classes, execute the functions, and print the results.
 *
 * @return It returns a 0 just to avoid a warning.
 */
int main() {
    // Setting Data store file path
    const cv::String posDir = "../data/INRIAPerson/Train/pos/";
    const cv::String negDir = "../data/INRIAPerson/Train/neg/";
    const cv::String testDir = "../data/INRIAPerson/Test/pos/";
    const cv::String annotationPath = "../data/INRIAPerson/Train/annotations/";

    // Define a window/image size
    cv::Size windowSize = cv::Size(200, 200);

    // Load positive images
    Data allData;
    std::cout << "Loading Positive Images" << std::endl;
    allData.loadPosImages(annotationPath, posDir, windowSize, true);
    // Check if images were successfully loaded
    if (allData.posImgList.size() > 0) {
        std::cout << "Loading Positive Training Data Complete" << std::endl;
    } else {
        std::cout << "No images found. " <<
                    "Please check the Path Directory: " << posDir << std::endl;
        return 0;
    }

    // Now load negative images
    std::cout << "Loading Negative Images" << std::endl;
    allData.loadNegImages(negDir, windowSize);
    if (allData.negImgList.size() > 0) {
        std::cout << "Loading Negative Training Data Complete" << std::endl;
    } else {
        std::cout << "No images found. " <<
                    "Please check the Path Directory: " << negDir << std::endl;
        return 0;
    }

    // Start with the training
    Train trainClass;
    // For Positive Images
    std::cout << "Extracting HOG features and storing in a " <<
                 "vector for Positive Images" << std::endl;
    trainClass.getHOGfeatures(windowSize, allData.posImgList);
    // Assign Positive labels
    size_t positiveCount = trainClass.gradientList.size();
    trainClass.labels.assign(positiveCount, 1);
    std::cout << "Done getting HOG Features for Positive Images" << std::endl;

    // For Negative Images
    std::cout << "Extracting HOG features and storing in a " <<
                 "vector for Negative Images" << std::endl;
    trainClass.getHOGfeatures(windowSize, allData.negImgList);
    // Assign Negative labels
    size_t negativeCount = trainClass.gradientList.size() - positiveCount;
    trainClass.labels.insert(trainClass.labels.end(), negativeCount, -1);
    std::cout << "Done getting HOG Features for Negative Images" << std::endl;

    // Start training the SVM classifier
    trainClass.trainSVM(true, "svm2classifier");

    // Train trainClass;
    // trainClass.classifier = cv::ml::SVM::load("../data/svmclassifier");

    // Test Classifier
//     Detect detector;
//     detector.hog_user.winSize = windowSize;
//     detector.hog_user.setSVMDetector(trainClass.getClassifier());
//     cv::Rect r = detector.testClassifier(testDir, true);
    std::cout << "Finshed" << std::endl;

    return 0;
}
