/*
 *  @file main.cpp
 *  Copyright [2018] Ghost1995 [Ashwin Goyal]
 *  @date Oct 04, 2018
 *  @brief This is the main file which runs the detection algorithm
 */

#include <Detect.hpp>

/*
 * @brief Main Function to call the class, execute the functions, and print the results.
 *
 * @return It returns a 0 just to avoid a warning.
 */
int main() {
    cv::VideoCapture cap;
    cap.open(0);
    if (!cap.isOpened()) {
        std::cout << "Can not open video stream: " << std::endl;
        return 2;
    }

    std::cout << "Press 'q' or <ESC> to quit." << std::endl;
    std::cout << "Press <space> to toggle between " <<
                  "Default and Daimler detector" << std::endl;
    Detect detector;
    cv::Mat frame;
    for (;;) {
        cap >> frame;
        if (frame.empty()) {
            std::cout << "Finished reading: empty frame" << std::endl;
            break;
        }
        int64 t = cv::getTickCount();
        std::vector<cv::Rect> found = detector.findHumans(frame);
        t = cv::getTickCount() - t;

        for (std::vector<cv::Rect>::iterator i = found.begin();
                                             i != found.end(); ++i) {
            cv::Rect &r = *i;
            detector.adjustBoundingBox(r);
            cv::rectangle(frame, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        }
        cv::imshow("People detector", frame);

        // interact with user
        const char key = static_cast<char>(cv::waitKey(30));
        if (key == 27 || key == 'q') {  // ESC
            std::cout << "Exit requested" << std::endl;
            break;
        } else if (key == ' ') {
            detector.toggleMode();
        }
    }
    return 0;
}
