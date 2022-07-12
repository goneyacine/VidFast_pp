#include <opencv2/opencv.hpp>

#include "Video.h"


using namespace VidFast;

 
Video::Video(cv::VideoCapture p_video) : m_videoCapture(p_video)
{
	
}

void Video::SpeedUp(cv::VideoCapture* p_video, int p_multiplyer,STRING outputPath)
{
	cv::Mat frame;


	int width = p_video->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = p_video->get(cv::CAP_PROP_FRAME_HEIGHT);

	
	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),fps,cv::Size(width,height));

	//iterating through the video frames to generate the faster version of the video by skiping some frames 
	for (int i = 0; i < framesCount; i++)
	{


		(*p_video) >> frame;

		if(i%(p_multiplyer -1))
		writer.write(frame);
	}


	writer.release();


}

void Video::SlowDown(cv::VideoCapture* p_video, int p_multiplyer,STRING outputPath)
{
	cv::Mat frame;


	int width = p_video->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = p_video->get(cv::CAP_PROP_FRAME_HEIGHT);


	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));

	//iterating through the video frames to generate the slower version of the video by repreating every frame
	for (int i = 0; i < framesCount; i++)
	{

		(*p_video) >> frame;
		//hear we repeat the frame (the number of times we repeat the frames is the speed multiplyer or p_multiplyer)
		for(int j = 0; j < p_multiplyer;j++)
			writer.write(frame);

	}


	writer.release();

}


void Video::SpeedUp(int multiplyer,STRING outputPath)
{
	Video::SpeedUp(&m_videoCapture,multiplyer,outputPath);
}

void Video::SlowDown(int multiplyer,STRING outputPath)
{
	Video::SlowDown(&m_videoCapture, multiplyer,outputPath);
}


void Video::SetVideoCapture(cv::VideoCapture p_video)
{
	m_videoCapture = p_video;
}

cv::VideoCapture Video::GetVideoCapture()
{
	return m_videoCapture;
}



