#include "pch.h"


#include <iostream>
#include <string>
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "CameraClib.h"
#include "VideoTest.h"
#include "Filtering.h"

using namespace std;
using namespace cv;

string chessImgDir="C:/Users/shubh/Pictures/OpenCVImg/Data.Note8Camera_chess";

//C:/Users/shubh/Pictures/OpenCVImg/lenna.png

int main()
{

	VideoTest vid;
	if (!vid.EnableVideoCapture()) {
		cerr << "Unable to open camera stream";
		return -1;
	}

	cv::Mat frame;
	Filtering filter;

	while (true)
	{
		frame = vid.GetCurrFrame();
		//frame = cv::imread("C:/Users/shubh/Pictures/OpenCVImg/lenna.png");
		cv::imshow("Camera", frame);
		//cv::Mat gray = filter.ConvertToGrayScale(frame);
		cv::Mat img_filter = filter.gammaCorrection(frame,0.3);
		cv::imshow("Filter", img_filter);

		if (waitKey(5) >= 0)
			break;
	}

	vid.DisableVideoCapture();
	
	return 0;
}
