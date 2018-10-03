# Human_Detector
[![Build Status](https://travis-ci.org/anirudhtopiwala/Human_Detector.svg?branch=master)](https://travis-ci.org/anirudhtopiwala/Human_Detector)
[![Coverage Status](https://coveralls.io/repos/github/anirudhtopiwala/Human_Detector/badge.svg?branch=master)](https://coveralls.io/github/anirudhtopiwala/Human_Detector?branch=master)
---

## Overview

An implementation of Human Detection using HOG features. The classifier used is a trained Support Vector machine (SVM).

## Project Breakdown
<p align="center">
<img src="https://github.com/anirudhtopiwala/Human_Detector/blob/master/ProjectBreakdown.jpg">
</p>

## Standard install via command-line
```
git clone --recursive https://github.com/anirudhtopiwala/Human_Detector.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/detect
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/anirudhtopiwala/Human_Detector.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)


