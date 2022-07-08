#include <iostream>
#include <opencv2/opencv.hpp>


int main()
{
	std::cout << "Hello world" << "\n";


	cv::Mat hello((400, 400, CV_8UC3, cv::Scalar(100, 150, 255)));


	cv::imshow("Hello World", hello);
	cv::waitKey(0);

	return 0;

}