#include "pch.h"
#include "VideoTest.h"


bool VideoTest::EnableVideoCapture(int deviceID, int apiID)
{
	this->devID = deviceID;
	this->apiID = apiID;
	return cap.open(devID, apiID);
}

cv::Mat VideoTest::GetCurrFrame()
{
	cv::Mat img;
	if (cap.isOpened())
	{
		cap.read(img);
		return img;
	}

	return img;
}

void VideoTest::DisableVideoCapture()
{
	return cap.release();
}

VideoTest::VideoTest()
{

}

VideoTest::~VideoTest()
{

}
