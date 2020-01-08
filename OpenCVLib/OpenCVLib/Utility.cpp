#include "stdafx.h"
//
//#include "opencv2/opencv.hpp"
//
//
//using namespace cv;
//using namespace std;
//
//Mat _currFrame;
//
//#define OPENCV_API __declspec(dllexport)
//
//extern "C" {
//
//	OPENCV_API uchar* GetRawImage()
//	{
//		return _currFrame.data;
//	}
//
//	OPENCV_API void UpdateFrame(unsigned char* texData, int width, int height)
//	{
//		Mat texture(height, width, CV_8UC4, texData);
//		cvtColor(texture, texture, COLOR_RGB2GRAY);
//
//		cvtColor(texture, texture, COLOR_GRAY2RGB);
//
//	}
//
//	OPENCV_API void ShowImage(string filePath)
//	{
//		//Mat img = imread(filePath);
//		//cvtColor(img, img, COLOR_BGR2GRAY);
//		//imwrite("lenna_gray.jpg", img);
//		//imshow("Test image", img);
//	}
//
//	OPENCV_API int DoubleInt(int a)
//	{
//		return 2 * a;
//	}
//
//	OPENCV_API void UpdateImage(unsigned char* data, int width, int height)
//	{
//		//Resize Mat to match the array passed to it from C#
//		Mat resizedMat(height, width, _currFrame.type());
//		resize(_currFrame, resizedMat, resizedMat.size(), INTER_CUBIC);
//
//		//Do operation here
//
//		//Convert from RGB to ARGB 
//		cv::Mat argb_img;
//		cv::cvtColor(resizedMat, argb_img, COLOR_BGR2RGBA);
//		memcpy(data, argb_img.data, argb_img.total() * argb_img.elemSize());
//	}
//}
