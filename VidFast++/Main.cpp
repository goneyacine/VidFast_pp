#include <iostream>
#include <opencv2/opencv.hpp>

#include "Video.h"
/*
	- change the frame rate

*/


int main()
{
	std::cout << "Tasks :" << "\n";
	std::cout << "1. Speed up" << "\n";
	std::cout << "2. Slow down" << "\n";
	std::cout << "3. ToColor16" << "\n";
	std::cout << "4. Resize" << "\n";
	std::cout << "5. Split" << "\n";


	std::cout << "Enter task index :" << "\n";

	int input;
	std::cin >> input;

	switch (input)
	{
	   case 1:
	   {
		   std::cout << "Enter input video path :" << "\n";
		   std::string inputVideoPath;
		   std::cin >> inputVideoPath;
		   std::cout << "Enter the speed multiplyer :" << "\n";
		   int speedMultipyer;
		   std::cin >> speedMultipyer;
		   std::cout << "Enter output video path :" << "\n";
		   std::string outputVideoPath;
		   std::cin >> outputVideoPath;
		   cv::VideoCapture video(inputVideoPath);
		   VidFast::Video::SpeedUp(&video, speedMultipyer, outputVideoPath);
	   }
		break;
	   case 2:
	   {
		   std::cout << "Enter input video path :" << "\n";
		   std::string inputVideoPath;
		   std::cin >> inputVideoPath;
		   std::cout << "Enter the speed multiplyer :" << "\n";
		   int speedMultipyer;
		   std::cin >> speedMultipyer;
		   std::cout << "Enter output video path :" << "\n";
		   std::string outputVideoPath;
		   std::cin >> outputVideoPath;
		   cv::VideoCapture video(inputVideoPath);
		   VidFast::Video::SlowDown(&video, speedMultipyer, outputVideoPath);
	   }
		   break;	   
	   case 3:
	   {
		   std::cout << "Enter input video path :" << "\n";
		   std::string inputVideoPath;
		   std::cin >> inputVideoPath;
		   std::cout << "Enter output video path :" << "\n";
		   std::string outputVideoPath;
		   std::cin >> outputVideoPath;
		   cv::VideoCapture video(inputVideoPath);
		   VidFast::Video::ToColor16(&video, outputVideoPath);
	   }
		   break;
	   case 4:
	   {
		   std::cout << "Enter input video path :" << "\n";
		   std::string inputVideoPath;
		   std::cin >> inputVideoPath;
		   std::cout << "Enter the new width :" << "\n";
		   int newWidth;
		   std::cin >> newWidth;
		   std::cout << "Enter the new height:" << "\n";
		   int newHeight;
		   std::cin >> newHeight;
		   std::cout << "Enter output video path :" << "\n";
		   std::string outputVideoPath;
		   std::cin >> outputVideoPath;
		   cv::VideoCapture video(inputVideoPath);
		   VidFast::Video::Resize(&video, newWidth, newHeight, outputVideoPath);
	   }
		   break;
	   case 5:
	   {
		   std::cout << "Enter input video path :" << "\n";
		   std::string inputVideoPath;
		   std::cin >> inputVideoPath;
		   std::cout << "Enter the slipt point (in seconds)" << "\n";
		   float splitPoint;
		   std::cin >> splitPoint;
		   std::cout << "Enter output video path 1:" << "\n";
		   std::string outputVideoPath1;
		   std::cin >> outputVideoPath1;
		   std::cout << "Enter output video path 2:" << "\n";
		   std::string outputVideoPath2;
		   std::cin >> outputVideoPath2;
		   cv::VideoCapture video(inputVideoPath);
		   VidFast::Video::Split(&video,splitPoint, outputVideoPath1, outputVideoPath2);
	   }
	   break;
	}
	return 0;

}