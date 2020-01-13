#pragma once

#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

class VideoTest
{
	cv::VideoCapture cap;
	int devID;
	int apiID;

public:
	VideoTest();
	~VideoTest();
	bool EnableVideoCapture(int deviceID=0, int apiID=cv::CAP_ANY);
	cv::Mat GetCurrFrame();
	void DisableVideoCapture();
};

