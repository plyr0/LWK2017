#pragma once

#include "stdafx.h"

class Cwiczenia2zadanie6 {
private:
	cv::Mat sharpenKernel = (cv::Mat_<char>(3, 3) <<
		0, -1, 0,
		-1, 5, -1,
		0, -1, 0);

	cv::Mat edgeKernel = (cv::Mat_<char>(3, 3) <<
		1, -2, 1,
		2, -4, 2,
		1, -2, 1);

	cv::Mat meanKernel = (cv::Mat_<char>(3, 3) <<
		1, 1, 1,
		1, 1, 1,
		1, 1, 1);

	int kernel_size = 9;
	cv::Mat softenKernel = 
		cv::Mat::ones(kernel_size, kernel_size, CV_32F) / static_cast<float>(kernel_size * kernel_size);

	cv::Mat sharpenKernel2 = (cv::Mat_<double>(3, 3) <<
		1, 1, 1,
		1, 9, 1,
		1, 1, 1) / static_cast<float>(3 * 3);
	
public:
	void run(const cv::Mat image) const
	{
		cv::Mat output = cv::Mat(image.size(), image.type());
		cv::filter2D(image, output, image.depth(), softenKernel);
		cv::imshow("Filter", output);
		cv::waitKey();
	}
};
