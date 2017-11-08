#pragma once
//#ifndef __Cwiczenia2zadanie5.h__
//#define __Cwiczenia2zadanie5.h__ 1

#include "stdafx.h"

class cw2_zad5 {
public:
	std::vector<cv::Mat> run(const cv::Mat image) const
	{
		std::vector<cv::Mat> colors(3);
		cv::split(image, colors);
		cv::imshow("Blue", colors[0]);
		cv::imshow("Red", colors[1]);
		cv::imshow("Green", colors[2]);
		cv::waitKey();
		return colors;
	}
};

//#endif // __Cwiczenia2zadanie5.h__