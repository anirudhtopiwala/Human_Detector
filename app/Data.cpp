/*
 *  @file Data.cpp
 *  Copyright [2018]
 *  @author1 anirudhtopiwala [Anirudh Topiwala] - stub
 *  @author2 Ghost1995 [Ashwin Goyal] - Implementation
 *  @date Oct 12, 2018
 *  @brief This is the implementation of the Data class
 */

#include <Data.hpp>
/*
 * @brief This is the constructor for the class
 * 
 * @param This constructor takes a string as an input which defines the objective of the class.
 */
Data::Data(std::string classObjective) {
    std::cout << "Class Data has been Initialized to read " << classObjective << std::endl;
}

/*
 * @brief This is the first method of the class. It loads the images, that is, training set - positive, negative - from the directory given as a string input.
 *
 * @param This method takes the directory name as an input from where the images are to be loaded.
 */
void Data::loadImages() {
    for (int i=0; i< anotations.size(); i++) {

        cv::Mat img = cv::imread(trainimages[i]);
        img= img(anotations[i]);
        if (img.empty()) {
            std::cout << trainimages[i] << " is invalid!" << std::endl;
            continue;
        }
        cv::imshow("frame",img);
        cv::waitKey(10);
        imgList.push_back(img);
    }
}

/*
 * @brief This is the first method of the class. It loads the images, that is, training set - positive, negative - from the directory given as a string input.
 *
 * @param This method takes the directory name as an input from where the images are to be loaded.
 */
void Data::loadImages(const cv::String dirName) {
    std::vector<cv::String> files;
    cv::glob(dirName, files);

    for (auto imgName : files) {
        cv::Mat img = cv::imread(imgName);
        if (img.empty()) {
            std::cout << imgName << " is invalid!" << std::endl;
            continue;
        }
        imgList.push_back(img);
    }
}

/*
 * @brief This is the second method of the class. It extracts sample images from the load images.
 *
 * @param This method takes the size of the window as an input to be used for sampling the images.
 */
void Data::sampleImages(const cv::Size size) {
    std::vector<cv::Mat> temp;
    cv::Rect box;
    box.width = size.width;
    box.height = size.height;

    const int size_x = box.width;
    const int size_y = box.height;

    for (auto data : imgList) {
        if (data.cols > box.width && data.rows > box.height) {
            box.x = rand() % (data.cols - size_x);
            box.y = rand() % (data.rows - size_y);
            cv::Mat roi = data(box);
            temp.push_back(roi.clone());
        }
    }
    imgList = temp;
}


 

void Data::loadAnnotations(const cv::String annotpath, const cv::String  posDir) {

std::string line,value; //Line stores lines of the file and value stores characters of the line
int i=0; //Iterate through lines
int j=0; //Iterate through characters
int n=0; //Iterate through ,()-...
char v; //Stores variable value as a char to be able to make comparisions easily

 //Stores rectangles for each image
std::vector <int> bbValues; //Bounding box values (xmin,ymin,xmax,ymax)


std::vector<cv::String> filesannot, files ;
cv::glob(annotpath, filesannot);
cv::glob(posDir, files);

std::cout<<"Reading anotations from"<< annotpath <<std::endl;

for (int k=0; k< files.size(); k++) {
    std::ifstream inputFile; //Declare input file with image path
    inputFile.open(filesannot[k]);
    // std::cout<<"here 1";
    i=0;
    while (! inputFile.eof() ){ //Until end of file
        getline (inputFile,line);//Get lines one by one
        if ((i>=17) && ((i-17)%7==0)){ //In lines numer 17,24,31,38...where bounding boxes coordinates are
            j=69;
            v=line[j]; //Start from character num 69 corresponding to first value of Xmin
            while (j<line.size()){ //Until end of line
                if (v=='(' || v==',' || v==')' || v==' ' || v=='-'){ //if true, push back acumulated value unless previous value wasn't a symbol also
                    if (n==0){
                        bbValues.push_back(stoi(value)); //stoi converts string in to integer ("567"->567) 
                        value.clear();
                    }
                    n++;
                 }
                else{
                     value+=v; //Append new number
                    n=0;//Reset in order to know that a number has been read
                    }
                j++;
                v=line[j];//Read next character
            }
            cv::Rect rect(bbValues[0],bbValues[1],bbValues[2]-bbValues[0],bbValues[3]-bbValues[1]); //Build a rectangle rect(xmin,ymin,xmax-xmin,ymax-ymin)
            anotations.push_back(rect);
            trainimages.push_back(files[k]);
            // std::cout<< "rect read"<< rect<<std::endl;

            bbValues.clear();
       }
       i++;//Next line
     }
    // std::cout<<"File name"<< imgName <<std::endl;

    inputFile.close();     
    // std::cout<< k<< std::endl;
}      
// std::cout<< "annotsize"<< anotations.size()<<std::endl;
// std::cout<< "files"<< trainimages.size()<<std::endl;

}

















/*
 * @brief This is the destructor for the class
 */
Data::~Data() {
    std::cout << "Class Data has been Destroyed" << std::endl;
}