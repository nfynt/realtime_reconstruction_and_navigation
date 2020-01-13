#include "pch.h"

#include "Filtering.h"


Filtering::Filtering()
{
}


Filtering::~Filtering()
{
}

cv::Mat Filtering::ConvertToGrayScale(cv::Mat srcImg, bool isBGR)
{
	cv::Mat grayImg;
	if(isBGR)
		cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
	else
		cv::cvtColor(srcImg, grayImg, cv::COLOR_RGB2GRAY);
	return grayImg;
}
