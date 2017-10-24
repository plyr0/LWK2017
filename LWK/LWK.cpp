#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

//#include "Cwiczenia2random.h"
#include "Cwiczenia2zadanie5.h"
#include "Cwiczenia2zadanie6.h"

using namespace std;

int main(int argc, char** argv)
{
	cv::Mat image;
	image = cv::imread("Lenna.png", CV_LOAD_IMAGE_UNCHANGED);

	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		cin.get();
		return -1;
	}
	cv::imshow("Original", image);
	//Cwiczenia2random().run(image);

	//Cwiczenia2zadanie5().run(image);
	Cwiczenia2zadanie6().run(image);

	cv::waitKey();
	return 0;
}