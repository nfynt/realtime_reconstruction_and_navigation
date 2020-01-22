#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class CameraClib
{
private:
	int numBoards;
	int numCornersHor;
	int numCornersVer;
	int numSquares;

	cv::Size board_sz;
	cv::Size frame_sz;

	vector<vector<Point3f>> object_points;
	vector<vector<Point2f>> image_points;

	vector<Point2f> corners;
	int successes = 0;

	cv::Mat intrinsic;
	cv::Mat distCoeffs;
	vector<Mat> rvecs;
	vector<Mat> tvecs;

	int framesProcessed;
	bool finishedCalberation;

public:
	CameraClib();
	~CameraClib();
	//Reset current params for new caliberation
	bool InitCaliberation(int horizontalCorners, int verticalCorners, int frameWidth, int frameHeight);
	
	//Caliberate current calculation with camera image. indOut set's the total number of frames processed
	bool Caliberate(cv::Mat img, int* indOut=NULL);
	
	//Close caliberation and save to params to local file
	bool FinishCaliberation(bool saveParamsToFile, std::string path=NULL);
	
	//Get intrinsic matrix (3,3,CV_32FC1)
	cv::Mat GetIntrinsicMatrix();
	cv::Mat GetDistortionCoefficients();
	std::vector<cv::Mat> GetRotationVectors();
	std::vector<cv::Mat> GetTranslationVectors();
	
	//Load camera param from local file and initialise camera param
	cv::Mat LoadCameraParamFromFile(std::string path);
};

