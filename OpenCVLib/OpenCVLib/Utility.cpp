#include "stdafx.h"

//#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;


struct Color32
{
	uchar red;
	uchar green;
	uchar blue;
	uchar alpha;
};

Mat _currFrame;

#define OPENCV_API __declspec(dllexport)

extern "C" {

	OPENCV_API void ConvertTexToGray(Color32** texData, int width, int height)
	{
		Mat texture(height, width, CV_8UC4, *texData);

		//Flip if necessary
		//flip(texture, texture, -1);
		Mat gray;
		cvtColor(texture, gray, COLOR_RGBA2GRAY);

		cvtColor(gray, texture, COLOR_GRAY2RGBA);

	}

	OPENCV_API void CannyEdgeFilter(Color32** texData, int width, int height)
	{
		Mat texture(height, width, CV_8UC4, *texData);

		//Flip if necessary
		//flip(texture, texture, -1);
		
		Mat edges;
		Canny(texture, edges, 50, 200);
		dilate(edges, edges, (5, 5));
		cvtColor(edges, edges, COLOR_GRAY2RGBA);
		normalize(edges, edges, 0, 1, NORM_MINMAX);
		multiply(texture, edges, texture);

		// flip again (just vertically) to get the right orientation
		//flip(image, image, 0);
	}

	OPENCV_API int DoubleInt(int a)
	{
		return 2 * a;
	}
}
