#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
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
	cv::imshow("Original", image);
	
	// Gray
	//cv::Mat gray_image;
	//cv::cvtColor(image, gray_image, CV_BGR2GRAY);
	//cv::imshow("Gray", gray_image);
	//cv::imwrite("./output.png", gray_image);
	
	// Random
	//cv::Mat R = cv::Mat(cv::Size(image.cols, image.rows), image.type());
	//randu(R, cv::Scalar::all(0), cv::Scalar::all(255));
	//cv::imshow("Rand", R);

	// Zadanie 5
	vector<cv::Mat> colors(3);
	cv::split(image, colors);	
	cv::imshow("Blue", colors[0]);
	cv::imshow("Red", colors[1]);
	cv::imshow("Green", colors[2]);
	
	// Clash colors
	/*vector<cv::Mat> clash;
	clash.push_back(colors[2]);
	clash.push_back(colors[0]);
	clash.push_back(colors[1]);
	cv::Mat mat_clash;
	cv::merge(clash, mat_clash);
	cv::imshow("Clash", mat_clash);*/


	cv::waitKey();
	return 0;
}