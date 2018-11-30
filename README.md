# Human Detector

[![Build Status](https://travis-ci.org/anirudhtopiwala/Human_Detector.svg?branch=master)](https://travis-ci.org/anirudhtopiwala/Human_Detector)
[![Coverage Status](https://coveralls.io/repos/github/anirudhtopiwala/Human_Detector/badge.svg?branch=master)](https://coveralls.io/github/anirudhtopiwala/Human_Detector?branch=master)
 [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---

The loss in coverage of 7 percent is because of uncovered statements by the unit test. Example of these are code blocks which are put in place to check the correct input of directory path or to check the correct dimensions of different variables. And as unit tests are given the right image inputs, these code blocks don't get covered.
## Overview

**This Branch is an implementation of Google Mock test. Please go to the Master Branch for original implementation. To read more on the Google mock test. Go to the Google Mock section in the ReadMe below.**

Human detection is an old and important problem in the field of object detection. Current technologies
easily detect static obstacles. But, detecting dynamic obstacles has always been tough. In dynamic obstacles, human obstacles are the most important as any collision might lead to injury or loss of life which is highly undesirable for any product. This has generated a need for an accurate detector for making the algorithms more robust and efficient. 

To this extent we propose an algorithm that can detect humans in a frame by making rectangular bounding
boxes around individual humans. The center position of the rectangle will be used as the pixel location in
that frame. The pixel coordinates can then be used with a robots intrinsic and extrinsic transformations to track the human with respect to the robot's world frame.  We have used Histogram of Oriented Gradient (HOG) as the feature extractor. Support Vector Machine (SVM) is used to train using these feature vectors generated on the training data.The data set used for this project is taken from [INRIA Person Dataset](http://pascal.inrialpes.fr/data/human/). The algorithm is based on the paper by [Dalal, N., Triggs, B.](https://ieeexplore.ieee.org/document/1467360). A brief introduction of the algorithm can be found [here](https://www.learnopencv.com/histogram-of-oriented-gradients/). 

We have used openCV as a third party library, which is covered under the 3-clause BSD License.

## Algorithm and Outputs

The goal of this project is to detect humans using a SVM classifier trained on HOG descriptors. As the name suggests there are three major components or classes in the project. The **Data class**, which is responsible for loading the training Data, the **Train class** which computes the HOG descriptors and trains the classifier and the **Detect class** which makes a bounding box around the detected human.
Refer to the [class](https://github.com/anirudhtopiwala/Human_Detector/blob/master/UML/revised/UML_Class.pdf) and the  [activity]( https://github.com/anirudhtopiwala/Human_Detector/blob/master/UML/revised/UML_Activity.pdf) diagrams to understand the flow of the algorithm.

The algorithm starts with reading the positive (pos) images from the INRIA database to form the training data. Now, as the HOG descriptors requires a cropped input of the human to form a good descriptor, the training images were cropped using the bounding boxes obtained from the annotations file. To have a balanced descriptor, the negatives (neg) were formed by random cropping on the images obtained from the neg folder of the INRIA dataset. All the images were finally resized to have the same size, as this is very essential to the proper working of the classifier. 

The HOG features were calculated with a cell size of (4,4). This size was taken as the length of the descriptor is very high for a cell size of (2,2) and for a cell size of (8,8), the number of descriptors were not enough to represent all the information in the image. This can be clearly observed in the comparison shown below. 

<p align="center">
<img src="https://github.com/anirudhtopiwala/Human_Detector/blob/master/additional_files/Hog_cell_size_comaprison.png">
</p>

The HOG features for a cell size of (4,4) for some of the test images is shown below.

<p align="center">
<img src="https://github.com/anirudhtopiwala/Human_Detector/blob/master/additional_files/hog.gif">
</p>

Once the descriptor for pos and neg images is concatenated, it is passed to the SVM classifier. After the classifier is trained, the detectMultiScale function of openCV is used to make the detection. The bounding box obtained is then adjusted to give the final prediction of the human. Some of the detections on the test images can be seen below. 

<p align="center">
<img src="https://github.com/anirudhtopiwala/Human_Detector/blob/master/additional_files/detections.gif">
</p>

As we can see, the classifier is able to make an approximate detection of the human. This detection is the most basic kind of detection and many other optimization algorithms can be used to improve upon the detection accuracy. One way of removing multiple detections or multiple bounding boxes over a single human can be achieved by using [Non-maximum Suppression.](https://www.pyimagesearch.com/2015/02/16/faster-non-maximum-suppression-python/). Some other optimization techniques are discussed [here](https://stackoverflow.com/questions/26607418/improving-accuracy-opencv-hog-people-detector). 

## License

MIT License

Copyright (c) 2018 Anirudh Topiwala

```
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```

## SIP Logs

The process is detailed in the following [link](https://docs.google.com/spreadsheets/d/1EZE9dxY_vlz4glKEceYtc5kQ3OyYQjs5Zh9BSKF8AoA/edit?usp=sharing)

## Dependencies

Install OpenCV 3.3.0 using the following commands

Install Dependencies
```
sudo apt-get install build-essential checkinstall cmake pkg-config yasm gfortran git
sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev
## If you are using Ubuntu 14.04
sudo apt-get install libtiff4-dev
## If you are using Ubuntu 16.04
sudo apt-get install libtiff5-dev
sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
sudo apt-get install libxine2-dev libv4l-dev
sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
sudo apt-get install libqt4-dev libgtk2.0-dev libtbb-dev
sudo apt-get install libatlas-base-dev
sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev
sudo apt-get install libvorbis-dev libxvidcore-dev
sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev
sudo apt-get install x264 v4l-utils
```
Download and Compile OpenCV
```
git clone https://github.com/opencv/opencv.git
cd opencv 
git checkout 3.3.0 
cd ..
git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout 3.3.0
cd ..
cd opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local \
      -D INSTALL_C_EXAMPLES=ON \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_QT=ON \
      -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
      -D BUILD_EXAMPLES=ON ..
## find out number of CPU cores in your machine
nproc
## substitute 4 by output of nproc
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" >> /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```

## Build Instructions
```
git clone https://github.com/anirudhtopiwala/Human_Detector.git
cd Human_Detector
mkdir build
cd build
cmake ..
make
```

## Build Instructions for Code Coverage
```
sudo apt-get install lcov
git clone https://github.com/anirudhtopiwala/Human_Detector.git
cd Human_Detector
mkdir build
cd build
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Data Set up

The user has three options here: 
1) Download our classifier from [here](https://drive.google.com/drive/folders/1_ohdD842Nh5XqXgyvDHJ5lnyOXj5CTd1?usp=sharing) and save it in [./data/classifier/](https://github.com/anirudhtopiwala/Human_Detector/tree/master/data/classifier/). The classifer is of 1 GB.
2) Use a default Pre Trained classifier of OpenCV to run the program.
3) Train your own classifier to run the program.

For options 1 and 2 the user can either use his own data and give the file path for the test images when prompted while running the program or download the INRIA Dataset by running the code below. The dataset has both training and testing images and is of 1.2 GB. There are a couple of sample images present in [./data/test/imgs](https://github.com/anirudhtopiwala/Human_Detector/tree/master/data/test/imgs) which can be used to test the classifier. In this case no additional image data needs to be downloaded.
```
cd .. 
cd data
wget ftp://ftp.inrialpes.fr/pub/lear/douze/data/INRIAPerson.tar
cd ..
```
Downplaying the INRIA dataset is necessary for option 3, as the training images are required for training the classifier. A different dataset can also be used here if needed but the feature extraction paramters and the classifier parameters needs to be fine tuned accordingly.

Once the dataset it downloaded, extract it in the same folder.


## Running the Program

Go to the build directory and run the following command from the build directory:

```
cd <build folder of the module>
./app/detectHumans 
```

## Running the Unit Tests

Go to the build directory and run the following command from the build directory:
```
cd <build folder of the module>
./test/detectHuman-test 
```
## Google Mock Test

Google Mock is a way to test interdependent methods or classes by creating their mock counterparts. This is very useful as if there is any refactoring and the classes are changed, then the tests need not be rewritten. Note: mock objects are different from fake objects. Mock objects are specifically built to test interdependent classes.

For the current project, I have created two mock methods in the Detect class, which are toggleMode() and modeName(). I have used these methods as these are the only methods which are called into different classes. All the other methods are independent and they just act as functions. Therefore I decided to use just these two methods for Google Mock implementation. 

Using Google mock macro "EXPECT_CALL", in the testDetect.cpp (DetectModeNameTest), I checked if the modeName() method is being called once and that the value "default" is being returned. 

The toggleMode() method is checked in DetectToggleTest. Here we use the same mock macro "EXPECT_CALL" to run **twice**. This way we check if the mode name is changing from "User" to "Default" and back.


Note that, for the Google mock testing, the methods discussed above in the class detect was interdependent and therefore no additional changes are made in the class structure. 

## How to Generate Doxygen Documnetation

To install doxygen run the following command:
```
sudo apt-get install doxygen
```
Now from the cloned directory run:
```
doxygen Doxygen
```
Doxygen files will be generated to ./docs folder.

To view them in a browser:
```
cd docs
cd html
google-chrome index.html
```

## Plugins

- CppChEclipse
To install and run cppcheck in Terminal
```
cd <path to repository>
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/"  -e "^./docs/"  -e "^./results/" )
```
- Google C++ Sytle
To include and use Google C++ Style formatter in Terminal
```
cd <path to repository>
cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```
