#include "pch.h"

#include "CameraClib.h"

bool CameraClib::InitCaliberation(int horizontalCorners, int verticalCorners, int frameWidth, int frameHeight)
{
	numBoards = 0;
	numCornersHor = horizontalCorners;
	numCornersVer = verticalCorners;
	numSquares = numCornersHor * numCornersVer;

	board_sz = Size(numCornersHor, numCornersVer);
	frame_sz = Size(frameWidth, frameHeight);

	object_points.clear();
	image_points.clear();
	corners.clear();

	intrinsic = Mat(3, 3, CV_32FC1);

	intrinsic.ptr<float>(0)[0] = 1;
	intrinsic.ptr<float>(1)[1] = 1;

	finishedCalberation = false;

	return true;
}

bool CameraClib::Caliberate(Mat image, int* indOut)
{
	vector<Point3f> obj;
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	for (int j = 0; j < numSquares; j++)
		obj.push_back(Point3f(j / numCornersHor, j%numCornersHor, 0.0f));

	bool found = findChessboardCorners(image, board_sz, corners, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FILTER_QUADS);

	if (found)
	{
		cornerSubPix(grayImage, corners, Size(11, 11), Size(-1, -1), TermCriteria(TermCriteria::EPS | TermCriteria::MAX_ITER, 30, 0.1));
		//drawChessboardCorners(grayImage, board_sz, corners, found);
		image_points.push_back(corners);
		object_points.push_back(obj);

		//printf("Snap stored!");

	}
	framesProcessed++;

	return found;
}

bool CameraClib::FinishCaliberation(bool saveParamsToFile, string path)
{
	calibrateCamera(object_points, image_points, frame_sz, intrinsic, distCoeffs, rvecs, tvecs);
	finishedCalberation = true;
}

Mat CameraClib::GetIntrinsicMatrix()
{
	if (finishedCalberation) return intrinsic;
	else NULL;
}

Mat CameraClib::GetDistortionCoefficients()
{
	if (finishedCalberation) return distCoeffs;
	else NULL;
}

vector<Mat> CameraClib::GetRotationVectors()
{
	if (finishedCalberation) return rvecs;
	else NULL;
}
vector<Mat> CameraClib::GetTranslationVectors()
{
	if (finishedCalberation) return tvecs;
	else NULL;
}

Mat CameraClib::LoadCameraParamFromFile(string path)
{

}

CameraClib::CameraClib()
{
	//this->InitCaliberation(6, 9);
}


CameraClib::~CameraClib()
{
}
