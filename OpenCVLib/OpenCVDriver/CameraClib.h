#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include "opencv2/opencv.hpp"

class CameraClib
{
public:
	CameraClib();
	~CameraClib();
	void DetermineCameraParams(std::string imagePath);
};

