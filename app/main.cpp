/*
 *  @file main.cpp
 *  Copyright [2018]
 *  @author1 Ghost1995 [Ashwin Goyal]
 *  @author2 anirudhtopiwala [Anirudh Topiwala]
 *  @date Oct 04, 2018
 *  @brief This is the main file which runs the detection algorithm
 */

#include <Detect.hpp>
#include <Data.hpp>

/*
 * @brief This is the main function to call the classes, execute the functions, and print the results.
 *
 * @return It returns a 0 just to avoid a warning.
 */
int main() {
//    Train trainclass;
    Data posData("Positive Training Set"), negData("Negative Training Set");
    Detect test;

    // Setting Data store file path
    cv::String posDir = "../data/INRIAPerson/Train/pos/";
    cv::String negDir = "../data/INRIAPerson/Train/neg/";
    cv::String testDir = "../data/INRIAPerson/Test";

    // Booleans
    bool testingTrainedClassifier = false;
    bool output = false;
    // Setting Input image size
    int inputRows = 96;
    int inputCols = 160;

    if (posDir.empty() || negDir.empty() || testDir.empty()) {
        std::cout << "Input data directory empty or incorrect. Please enter a valid data path." << std::endl;
        return 0;
    }

    std::vector<cv::Mat> posList, fullNegList, negList, gradientList;
    std::vector<int> labels;

    std::cout << "Loading Positive Images" << std::endl;
    posData.loadImages(posDir, output);

    // Check if Data is actually Present.
    if (posData.imgList.size() > 0) {
        std::cout << "Loading Training Data Complete: " << posData.imgList.size() << std::endl;
    } else {
        std::cout << "No images found. Please check the Path Directory: " << posDir << std::endl;
        return 0;
    }

    // Checking to see if all images are of the same size
    cv::Size posImgSize = posData.imgList[0].size();
    if (inputRows && inputCols) {
        posImgSize = cv::Size(inputRows, inputCols);
    } else {
        for (auto data : posData.imgList) {
            if (data.size() != posImgSize) {
                std::cout << "All the input images do not match the input image size of rows: " << inputRows << " and columns: " << inputCols << std::endl;
                return 0;
            }
        }
    }

    //Now loading Negative Samples and Sampling them randomly
    negData.loadImages(negDir, false);
    negData.sampleImages(posImgSize);
    std::cout << "Negative Image Sampling Completed: " << negData.imgList.size() << std::endl;

    // End of Loading the Data

    // Training Starts

    

    // std::string imageName("../data/pedestrian_5.jpg");
    // cv::Mat img = cv::imread(imageName, CV_LOAD_IMAGE_COLOR);
    // std::vector<cv::Rect> found = test.findHumans(img);
    // for (std::vector<cv::Rect>::iterator i = found.begin(); i != found.end(); ++i) {
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
