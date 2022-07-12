#pragma once

#include <iostream>

#include <opencv2/opencv.hpp>

#define STRING std::string


namespace VidFast
{
	class Video
	{
	public : 
		Video(cv::VideoCapture p_video);
		static void SpeedUp(cv::VideoCapture* p_video,int p_multiplyer,STRING outputPath);
		static void SlowDown(cv::VideoCapture* p_video, int p_multiplyer,STRING outputPath);

		void SpeedUp(int p_multiplyer,STRING outputPath);
		void SlowDown(int p_multiplyer,STRING outputPaht); 


		void SetVideoCapture(cv::VideoCapture p_video);
		cv::VideoCapture GetVideoCapture();

	private :
		cv::VideoCapture m_videoCapture;
	};
}