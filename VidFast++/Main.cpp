#include <iostream>
#include <opencv2/opencv.hpp>

#include "Video.h"
/*
  project notes :

  - basic functions needed :

    - cut 
	- remove
	- merge
	- speed up & slow down
	- resize
	- change the frame rate

*/


int main()
{

	std::cout << "Enter the input video path :" << "\n";
	std::string inputVideoPath;
	std::cin >> inputVideoPath;

	std::cout << "Enter the output video path :" << "\n";
	std::string outputVideoPath;
	std::cin >> outputVideoPath;



	cv::VideoCapture vid(inputVideoPath);
   
	VidFast::Video::ToColor16(&vid, outputVideoPath);

	return 0;

}