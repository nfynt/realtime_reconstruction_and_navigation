#include "pch.h"

#include "Filtering.h"


cv::Mat Filtering::gammaCorrection(cv::Mat srcImg, float gamma) 
{
	CV_Assert(gamma >= 0);

	cv::Mat lookUp(1, 256, CV_8U);
	uchar *p = lookUp.ptr();

	for(int i=0;i<256;i++)
		p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);

	cv::Mat res = srcImg.clone();
	cv::LUT(srcImg, lookUp, res);
	//! [changing-contrast-brightness-gamma-correction]

	cv::hconcat(srcImg, res, res);

	return res;
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


Filtering::Filtering()
{
}


Filtering::~Filtering()
{
}


/*
//accessing individual pixels
for( int y = 0; y < image.rows; y++ ) {
		for( int x = 0; x < image.cols; x++ ) {
			for( int c = 0; c < image.channels(); c++ ) {
				new_image.at<Vec3b>(y,x)[c] =
				  saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
			}
		}
	}
*/