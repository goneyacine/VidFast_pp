#pragma once

#include <iostream>

#include <opencv2/opencv.hpp>



namespace VidFast
{
	class Video
	{
	public :
		/// <summary>
		/// Speeds up the src video
		/// </summary>
		/// <param name="p_video">  Source video ptr</param>
		/// <param name="p_multiplyer"> Speed multiplyer (should be greater than 1)</param>
		/// <param name="p_outputPath">  The path where the output video will be saved</param>
		static void SpeedUp(cv::VideoCapture* p_video,int p_multiplyer,std::string p_outputPath);

		/// <summary>
		///  Slows down the src video
		/// </summary>
		/// <param name="p_video">  Source video ptr</param>
		/// <param name="p_multiplyer">  Speed multiplyer (should be greater than 1)</param>
		/// <param name="p_outputPath">  The path wehere the output video will be saved</param>
		static void SlowDown(cv::VideoCapture* p_video, int p_multiplyer, std::string  p_outputPath);

		/// <summary>
		/// Casts the RGB colors from 32 bit color to 16 bit 
		/// </summary>
		/// <param name="p_video"> Source video ptr</param>
		/// <param name="p_outputPath"> The path where the output video will be saved</param>
		static void ToColor16(cv::VideoCapture* p_video, std::string  p_outputPath);

		/// <summary>
		/// Resizes the src video
		/// </summary>
		/// <param name="p_video"> Source video ptr</param>
		/// <param name="p_newWidth"> The new frame width value</param>
		/// <param name="p_newHeight"> The new frame height value</param>
		/// <param name="p_outputPath"> The path where the output video will be saved</param>
		static void Resize(cv::VideoCapture* p_video, int p_newWidth, int p_newHeight, std::string  p_outputPath);

		/// <summary>
		/// Splits the source video into two parts
		/// </summary>
		/// <param name="p_video"> Source video ptr</param>
		/// <param name="p_sliptPoint"> The time point where the video is splitted in seconds</param>
		/// <param name="p_outuputPath1"> The path where the first part of the output video is saved</param>
		/// <param name="p_outuputPath2"> The path where the second part of the output video is saved</param>
		static void Split(cv::VideoCapture* p_video, float p_sliptPoint, std::string p_outuputPath1, std::string p_outputPath2);
     
	};
}