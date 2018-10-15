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
    // Check if directories exist
    // if (posDir.empty() || negDir.empty() || testDir.empty() || annotationPath.empty()) {
    //     std::cout << "Input data directory empty or incorrect." <<
    //                  " Please enter a valid data path." << std::endl;
    //     return 0;
    // }

    // Define a window size
    cv::Size windowSize = cv::Size(200, 200);
    // Load positive images
    Data allData;
    // Loading Annotations
//    std::cout << "Loading Annotations for Positive Images" << std::endl;
  //  posData.loadAnnotations(annotationPath, posDir);
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
    // int minRow = 1000000000, minCol = 1000000000, avgRow = 0, avgCol = 0;
    // for (auto i = 0; i < posData.imgList.size(); i++) {
    // 	if (minRow > posData.imgList[i].rows)
    // 		minRow = posData.imgList[i].rows;
    //     if (minCol > posData.imgList[i].cols)
    // 		minCol = posData.imgList[i].cols;
    // 	avgRow += posData.imgList[i].rows;
    // 	avgCol += posData.imgList[i].cols;
    // }
    // std::cout << "cols: " << minCol << ", rows: " << minRow << std::endl;
    // std::cout << "cols: " << avgCol/posData.imgList.size() << ", rows: " << avgRow/posData.imgList.size() << std::endl;

    // return 0;

    // Now load negative images and sample them randomly
    std::cout << "Loading Negative Images" << std::endl;
    allData.loadNegImages(negDir, windowSize);
//    negData.sampleImages(cv::Size(96, 160));
    if (allData.negImgList.size() > 0) {
        std::cout << "Loading Negative Training Data Complete" << std::endl;
    } else {
        std::cout << "No images found. " <<
                    "Please check the Path Directory: " << negDir << std::endl;
        return 0;
    }

    Train trainClass;
    // For Positive Images
    std::cout << "Extracting HOG features and storing in a " <<
                 "vector for Positive Images" << std::endl;
    trainClass.getHOGfeatures(windowSize, allData.posImgList);
    size_t positiveCount = trainClass.gradientList.size();
    // Assigning Positive labels
    trainClass.labels.assign(positiveCount, 1);
    std::cout << "Done getting HOG Features for Positive Images" << std::endl;

    // For Negative Images
    std::cout << "Extracting HOG features and storing in a " <<
                 "vector for Negative Images" << std::endl;
    trainClass.getHOGfeatures(windowSize, allData.negImgList);
    size_t negativeCount = trainClass.gradientList.size() - positiveCount;
    // Assigning Negative labels
    trainClass.labels.insert(trainClass.labels.end(), negativeCount, -1);
    std::cout << "Done getting HOG Features for Negative Images" << std::endl;

    // Training Starts
    trainClass.trainSVM(true,"svm2classifier");

    // Train test;
    // test.classifier = cv::ml::SVM::load("../data/svmclassifier");

    // Testing Trained Classifier
//     Detect detector;
//     detector.hog_user.winSize = cv::Size(96, 160);
//     std::cout << "1" << std::endl;
//     detector.hog_user.setSVMDetector(trainClass.getClassifier());
//     std::cout << "2" << std::endl;

// //    std::string imageName("../data/test/pos/crop001005.png");
//     std::string imageName("../data/test/imgs/pedestrian_5.jpg");
//     cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
//     if (img.empty()) {
//         std::cout << imageName << " is invalid!" << std::endl;
//         return 0;
//     }
//     if (detector.modeName() != "User") {
// 	    detector.toggleMode();
// 	}
//     cv::Size imgSize(img.cols, img.rows);
//     cv::resize(img, img, cv::Size(96, 160), 0, 0);
//     std::cout << "3" << std::endl;
//     std::vector<cv::Rect> found = detector.findHumans(img);
//     std::cout << "4" << std::endl;
//     for (std::vector<cv::Rect>::iterator i = found.begin(); i != found.end(); ++i) {
//         cv::Rect &r = *i;
//         std::cout << r << std::endl;
//         cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
//         detector.adjustBoundingBox(r);
//         std::cout << r << std::endl;
//         cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
//     }
//     cv::resize(img, img, imgSize, 0, 0);
//     cv::imshow("People detector", img);
//     cv::waitKey(10000);


//     cv::Rect r = detector.testClassifier(testDir, true);
    std::cout << "Finshed" << std::endl;

    // std::string imageName("../data/pedestrian_5.jpg");
    // cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
    // std::vector<cv::Rect> found = test.findHumans(img);
    // for (std::vector<cv::Rect>::iterator i = found.begin();
    //                                      i != found.end(); ++i) {
    //     cv::Rect &r = *i;
    //     std::cout << r << std::endl;
    //     cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
    //     test.adjustBoundingBox(r);
    //     std::cout << r << std::endl;
    //     cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
    // }
    // cv::imshow("People detector", img);
    // cv::waitKey(1000);

    // cv::VideoCapture cap;
    // cap.open(0);
    // if (!cap.isOpened()) {
    //     std::cout << "Can not open video stream: " << std::endl;
    //     return 2;
    // }

    // std::cout << "Press <space> to toggle between " <<
    //               "Default and Daimler detector" << std::endl;
    // Detect detector;
    // cv::Mat frame;
    // for (;;) {
    //     cap >> frame;
    //     if (frame.empty()) {
    //         std::cout << "Finished reading: empty frame" << std::endl;
    //         break;
    //     }
    //     int64 t = cv::getTickCount();
    //     std::vector<cv::Rect> found = detector.findHumans(frame);
    //     t = cv::getTickCount() - t;

    //     for (std::vector<cv::Rect>::iterator i = found.begin();
    //                                          i != found.end(); ++i) {
    //         cv::Rect &r = *i;
    //         detector.adjustBoundingBox(r);
    //         cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
    //     }
    //     cv::imshow("People detector", frame);

    //     // interact with user
    //     const char key = static_cast<char>(cv::waitKey(30));
    //     if (key == 27 || key == 'q') {  // ESC
    //         std::cout << "Exit requested" << std::endl;
    //         break;
    //     } else if (key == ' ') {
    //         detector.toggleMode();
    //     }
    // }

    return 0;
}
