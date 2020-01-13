#include "pch.h"

#include "CameraClib.h"

using namespace std;
using namespace cv;
namespace fs = std::filesystem;

void CameraClib::DetermineCameraParams(string imagePath)
{
	for (auto &p : fs::directory_iterator(imagePath))
	{
		cout << p.path() << endl;
	}
}

CameraClib::CameraClib()
{
}


CameraClib::~CameraClib()
{
}
