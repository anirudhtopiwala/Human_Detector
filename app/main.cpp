#include <opencv2/opencv.hpp>
//#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main ()
{
  String imageName("../data/1.png");
  Mat img = imread(imageName,CV_LOAD_IMAGE_COLOR);
  if(! img.data )                              // Check for invalid input
  {
      cout <<  "Could not open or find the image" << std::endl ;
      cv::waitKey(5000);
      return -1;
  }
//  putText(img, "Hello World!", Point( 200, 400 ), FONT_HERSHEY_SIMPLEX | FONT_ITALIC, 1.0, Scalar( 255, 255, 0 ));
  imshow("My Window",img);
  waitKey();
  return 0;
}
