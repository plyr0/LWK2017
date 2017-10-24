#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

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
	const cv::String NAME = cv::String("A");
	cv::namedWindow(NAME, cv::WINDOW_NORMAL);
	cv::imshow(NAME, image);
	cv::waitKey();
	return 0;
}