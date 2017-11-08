#pragma once

#include "stdafx.h"

class cw3_zad2
{
public:
	char* name;
	cv::Mat input;
	cv::Mat output;
	int hue1;
	int hue2;

	cw3_zad2(const cv::Mat image)
	: name("cw3zad2"), hue1(100), hue2(120)
	{
		cv::cvtColor(image, input, CV_BGR2HSV);
		output(cv::Mat(input.size(), input.type()));
	}

	void run()
	{
		cv::namedWindow(name);
		cv::createTrackbar("Hue start", name, &hue1, 360, update, this);
		cv::createTrackbar("Hue end", name, &hue2, 360, update, this);
		while (true)
		{
			if (char(cv::waitKey(30) == 27))
				break;
			if (!cvGetWindowHandle(name))
				break;
		}
	}

	static void update(int, void* that)
	{
		auto self = static_cast<cw3_zad2*>(that);
		std::vector<cv::Mat> colors(3);
		cv::split(self->input, colors);
		cv::imshow("Blue", colors[0]);
		cv::imshow("Red", colors[1]);
		cv::imshow("Green", colors[2]);
		std::cout << " " << self->hue1 << " " << self->hue2 << std::endl;
	}
};
