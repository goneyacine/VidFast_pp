#include <opencv2/opencv.hpp>

#include "Video.h"

using namespace VidFast;

 
Video::Video(cv::VideoCapture p_video) : m_videoCapture(p_video)
{
	
}

void Video::SpeedUp(cv::VideoCapture* p_video, int p_multiplyer,STRING p_outputPath)
{
	cv::Mat frame;


	int width = p_video->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = p_video->get(cv::CAP_PROP_FRAME_HEIGHT);

	
	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(p_outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),fps,cv::Size(width,height));

	//iterating through the video frames to generate the faster version of the video by skiping some frames 
	for (int i = 0; i < framesCount; i++)
	{
		(*p_video) >> frame;
	
			if (i % (p_multiplyer - 1))
				writer.write(frame);
	}


	writer.release();


}

void Video::SlowDown(cv::VideoCapture* p_video, int p_multiplyer,STRING p_outputPath)
{
	cv::Mat frame;


	int width = p_video->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = p_video->get(cv::CAP_PROP_FRAME_HEIGHT);


	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(p_outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));

	//iterating through the video frames to generate the slower version of the video by repreating every frame
	for (int i = 0; i < framesCount; i++)
	{

			(*p_video) >> frame;

				//hear we repeat the frame (the number of times we repeat the frames is the speed multiplyer or p_multiplyer)
				for (int j = 0; j < p_multiplyer; j++)
				{

					writer.write(frame);

				}

	}


	writer.release();

}

void Video::ToColor16(cv::VideoCapture* p_video, STRING p_outputPath)
{
	cv::Mat frame;
	cv::Vec3b* rowPtr;


	int width = p_video->get(cv::CAP_PROP_FRAME_WIDTH);
	int height = p_video->get(cv::CAP_PROP_FRAME_HEIGHT);


	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(p_outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(width, height));


	for (int i = 0; i < framesCount; i++)
	{
		(*p_video) >> frame;

			//casting the pixel color values from 32 bit BGR (Blue, Green, Red) to 16 bit BGR value 
			for (int y = 0; y < frame.rows; y++)
			{
					rowPtr = frame.ptr<cv::Vec3b>(y);

				for (int x = 0; x < frame.cols; x++)
				{
			
					(rowPtr[x])[0] = static_cast<uchar>(static_cast<float>((rowPtr[x])[0]) / 255 * 16);
					(rowPtr[x])[0] = static_cast<uchar>(static_cast<float>((rowPtr[x])[0]) / 16 *255);
					
					(rowPtr[x])[1] = static_cast<uchar>(static_cast<float>((rowPtr[x])[1]) / 255 * 16);
					(rowPtr[x])[1] = static_cast<uchar>(static_cast<float>((rowPtr[x])[1]) / 16 * 255);

					(rowPtr[x])[2] = static_cast<uchar>(static_cast<float>((rowPtr[x])[2]) / 255 * 16);
					(rowPtr[x])[2] = static_cast<uchar>(static_cast<float>((rowPtr[x])[2]) / 16 * 255);



				}
			}

		
			//writing the frame into the disk
			writer.write(frame);
	}

	writer.release();
}


void Video::Resize(cv::VideoCapture* p_video, int p_newWidth, int p_newHeight, STRING p_outputPath)
{
	cv::Mat frame;

	int fps = p_video->get(cv::CAP_PROP_FPS);

	int framesCount = p_video->get(cv::CAP_PROP_FRAME_COUNT);

	//initializing the video writer
	cv::VideoWriter writer(p_outputPath, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(p_newWidth, p_newHeight));

	cv::Size newSize(p_newWidth, p_newHeight);


	for (int i = 0; i < framesCount; i++)
	{
		(*p_video) >> frame;
		cv::resize(frame, frame, newSize, cv::INTER_LINEAR);
     
		writer.write(frame);

	}

	writer.release();

}


void Video::SetVideoCapture(cv::VideoCapture p_video)
{
	m_videoCapture = p_video;
}

cv::VideoCapture Video::GetVideoCapture()
{
	return m_videoCapture;
}



