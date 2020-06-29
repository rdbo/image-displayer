#include <iostream>
#include <cv.hpp>
#include <highgui.h>
#include <fstream>

int main(int argc, char** argv)
{
    std::cout << "<< image displayer by rdbo >> " << std::endl;
    if(argc != 2)
    {
        std::cout << "[!] Invalid number of arguments" << std::endl;
        return -1;
    }

    std::ifstream file(argv[1]);
    if(file.good())
    {
        std::cout << "[*] Displaying image..." << std::endl;
        cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
        if(image.empty())
        {
            std::cout << "[!] Unable to load image" << std::endl;
            return -1;
        }

        else
        {
            cv::namedWindow("Image Displayer", CV_WINDOW_AUTOSIZE);
            cv::imshow("Image Displayer", image);
            cv::waitKey(0);
        }   
        std::cout << "[*] Done" << std::endl;
    }

    else
    {
        std::cout << "[!] The file is invalid" << std::endl;
    }
    
    return 0;
}