//Copyright (c) 2018 Anirudh Topiwala
/**
 *
 */
#include "lib.hpp"
/**

   * @brief		 Main Function to call the class, execute the functions
   *  and print the results.

   * @return 	 return 0

   */
int main()
{

    VideoCapture cap;
    cap.open(0);
    if (!cap.isOpened())
    {
        cout << "Can not open video stream: " << endl;
        return 2;
    }

    cout << "Press 'q' or <ESC> to quit." << endl;
    cout << "Press <space> to toggle between Default and Daimler detector" << endl;
    Detector detector;
    Mat frame;
    for (;;)
    {
        cap >> frame;
        if (frame.empty())
        {
            cout << "Finished reading: empty frame" << endl;
            break;
        }
        int64 t = getTickCount();
        vector<Rect> found = detector.detect(frame);
        t = getTickCount() - t;

        // show the window
//        {
//            ostringstream buf;
//            buf << "Mode: " << detector.modeName() << " ||| "
//                << "FPS: " << fixed << setprecision(1) << (getTickFrequency() / (double)t);
//            putText(frame, buf.str(), Point(10, 30), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255), 2, LINE_AA);
//        }
        for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i)
        {
            Rect &r = *i;
            detector.adjustRect(r);
            rectangle(frame, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
        }
        imshow("People detector", frame);

        // interact with user
        const char key = (char)waitKey(30);
        if (key == 27 || key == 'q') // ESC
        {
            cout << "Exit requested" << endl;
            break;
        }
        else if (key == ' ')
        {
            detector.toggleMode();
        }
    }
    return 0;
}
