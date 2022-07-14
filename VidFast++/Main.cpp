#include <iostream>
#include <opencv2/opencv.hpp>

#include "Video.h"
/*
	- change the frame rate

*/


int main()
{

	std::cout << "Enter the input video path :" << "\n";
	std::string inputVideoPath;
	std::cin >> inputVideoPath;

	std::cout << "Enter the output video path 1 :" << "\n";
	std::string outputVideoPath1;
	std::cin >> outputVideoPath1;



	std::cout << "Enter the output video path 2:" << "\n";
	std::string outputVideoPath2;
	std::cin >> outputVideoPath2;


	cv::VideoCapture vid(inputVideoPath);
   
	VidFast::Video::Split(&vid,76, outputVideoPath1,outputVideoPath2);

	return 0;

}