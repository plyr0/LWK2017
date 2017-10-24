#pragma once
//#ifndef __Cwiczenia2zadanie5.h__
//#define __Cwiczenia2zadanie5.h__ 1

#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class Cwiczenia2zadanie5 {
public:
	std::vector<cv::Mat> run(cv::Mat image) {
		std::vector<cv::Mat> colors(3);
		cv::split(image, colors);
		cv::imshow("Blue", colors[0]);
		cv::imshow("Red", colors[1]);
		cv::imshow("Green", colors[2]);
		return colors;
	}
};

//#endif // __Cwiczenia2zadanie5.h__