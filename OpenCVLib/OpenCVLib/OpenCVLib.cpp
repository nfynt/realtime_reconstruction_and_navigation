// OpenCVLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <algorithm>

#define TESTDLL_API __declspec(dllexport)

extern "C" {
	TESTDLL_API void TestSort(int a[], int length)
	{
		std::sort(a, a + length);
	}
}



