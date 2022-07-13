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


		/// <summary>
		/// Speeds up the src video
		/// </summary>
		/// <param name="p_video">  Source video ptr</param>
		/// <param name="p_multiplyer"> Speed multiplyer (should be greater than 1)</param>
		/// <param name="p_outputPath">  The path where the output video will be saved</param>
		static void SpeedUp(cv::VideoCapture* p_video,int p_multiplyer,STRING p_outputPath);

		/// <summary>
		///  Slows down the src video
		/// </summary>
		/// <param name="p_video">  Source video ptr</param>
		/// <param name="p_multiplyer">  Speed multiplyer (should be greater than 1)</param>
		/// <param name="p_outputPath">  The path wehere the output video will be saved</param>
		static void SlowDown(cv::VideoCapture* p_video, int p_multiplyer,STRING p_outputPath);

		/// <summary>
		/// Casts the RGB colors from 32 bit color to 16 bit 
		/// </summary>
		/// <param name="p_video"> Source video ptr</param>
		/// <param name="p_outputPath"> The path where the output video will be saved</param>
		static void ToColor16(cv::VideoCapture* p_video, STRING p_outputPath);

		/// <summary>
		/// Resizes the src video
		/// </summary>
		/// <param name="p_video"> Source video ptr</param>
		/// <param name="p_newWidth"> The new frame width value</param>
		/// <param name="p_newHeight"> The new frame height value</param>
		/// <param name="p_outputPath"> The path where the output video will be saved</param>
		static void Resize(cv::VideoCapture* p_video, int p_newWidth, int p_newHeight, STRING p_outputPath);


		void SetVideoCapture(cv::VideoCapture p_video);
		cv::VideoCapture GetVideoCapture();

	private :
		cv::VideoCapture m_videoCapture;
	};
}