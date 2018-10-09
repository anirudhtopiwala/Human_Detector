# Human_Detector
[![Build Status](https://travis-ci.org/anirudhtopiwala/Human_Detector.svg?branch=master)](https://travis-ci.org/anirudhtopiwala/Human_Detector)
[![Coverage Status](https://coveralls.io/repos/github/anirudhtopiwala/Human_Detector/badge.svg?branch=master)](https://coveralls.io/github/anirudhtopiwala/Human_Detector?branch=master)
---

## Overview
Human detection is an old and important problem in the field of object detection.Current technologies
easily detect static obstacles. But, detecting dynamic obstacles has always been tough.In dynamic obstacles, human obstacles are the most important as any collision might lead to injury or loss of life which is highly undesirable for any product. This has generated a need for an accurate detector for making the algorithms more robust and efficient. 

To this extent we propose an algorithm that can detect humans in frame by making rectangular bounding
boxes around individual humans. The center position of the rectangle will be used as the pixel location in
that frame. The pixel coordinates can then be used with a robots intrinsic and extrinsic transformations (not
considered in this project) to track the human with respect to the robot world frame.  We would be using
Histogram of Oriented Gradient (HOG) as the feature extractor. Support Vector Machine (SVM) will be used
as a classifier which will be using the extracted HOG features as a classifying factor. The data set used for
training images will be from Caltech [Pedestrian Dataset](http://www.vision.caltech.edu/Image_Datasets/CaltechPedestrians/)  or the [INRIA Person Dataset](http://pascal.inrialpes.fr/data/human/)

## License
MIT License

Copyright (c) 2017 Anirudh Topiwala

```
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Standard install via command-line
```
git clone https://github.com/anirudhtopiwala/Human_Detector.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/detect
```

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

# Dependencies

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
# TDD Process
Test Driven Development is used to develop the module. The process is detailed in the following [link](https://docs.google.com/spreadsheets/d/1EZE9dxY_vlz4glKEceYtc5kQ3OyYQjs5Zh9BSKF8AoA/edit?usp=sharing)
