#pragma once

#include "opencv2/opencv.hpp"

class Filtering
{
public:
	Filtering();
	~Filtering();

	cv::Mat ConvertToGrayScale(cv::Mat srcImg, bool isBGR = true);
};

