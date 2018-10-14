/*
 * @file Detect.cpp
 * @Copyright [2018]
 * @author1 Ghost1995 [Ashwin Goyal] - stub
 * @author2 anirudhtopiwala [Anirudh Topiwala] - Implementation
 * @date Oct 04, 2018
 * @brief This is the implementation of the Detect class.
 */

#include <Detect.hpp>

/*
 * @brief This is the constructor for the class
 */
Detect::Detect() {
    m = Default;
    hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    std::cout << "Class Detect has been Initialized" << std::endl;
}

/*
 * @brief This is the first method of the class. It returns the bounding boxes around the humans found in the image.
 *
 * @param This method takes an image as input.
 *
 * @return This method returns a vector containing the object Rect which defines the bounding box around the detected humans.
 */
std::vector<cv::Rect> Detect::findHumans(cv::InputArray img) {
    std::vector<cv::Rect> found;
    if (m == Default)
        hog.detectMultiScale(img, found, 0, cv::Size(8, 8),
                             cv::Size(32, 32), 1.05, 2, false);
    else if (m == User)
        hog_user.detectMultiScale(img, found, 0, cv::Size(8, 8),
                                  cv::Size(32, 32), 1.05, 2, false);
    return found;
}

/*
 * @brief This is the second method of the class. It adjusts the bounding box created around a detected human.
 *
 * @param This method takes the bounding box detected as input.
 */
void Detect::adjustBoundingBox(cv::Rect & r) {
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
}

/*
 * @brief This is the third method of the class. It is used to test the trained classifier.
 *
 * @param The first parameter defines the testDir where the testing set is stored.
 * @param The second parameter commands the method to either show or not show the images.
 */
cv::Rect Detect::testClassifier(cv::String testDir, bool dispImage = false) {
    std::cout << "Testing Trained Classifier" << std::endl;

    std::vector<cv::String> files;
    cv::glob(testDir, files);

    if (m != User) {
        m = User;
    }

    cv::Rect R;
    for (auto data : files) {
        cv::Mat img = cv::imread(data);
        if (img.empty()) {
            std::cout << data << " is invalid!" << std::endl;
            continue;
        }
        std::vector<cv::Rect> detections = findHumans(img);
        for (std::vector<cv::Rect>::iterator i = detections.begin();
                                             i != detections.end(); ++i) {
            cv::Rect &r = *i;
            if (data == "../data/test/pedestrian_5.jpg")
                R = r;
            adjustBoundingBox(r);
            cv::rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        }
        if (dispImage) {
            cv::imshow("Frame" , img);
            cv::waitKey(300);
        }
    }
    return R;
}

/*
 * @brief This is the destructor for the class
 */
Detect::~Detect() {
    std::cout << "Class Detect has been Destroyed" << std::endl;
}
