#pragma once

#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class Cwiczenia3zadanie1 {
public:
	char* name;
	cv::Mat input;
	cv::Mat output;
	int filter;
	int size;

	Cwiczenia3zadanie1(cv::Mat image) 
	: name("filter"), filter(0), size(1)
	{
		input = image.clone();
		output = cv::Mat(input.size(), input.type());
		cv::bitwise_not(input, output);
	}

	void run()
	{
		cv::waitKey(1000);
		cv::String filters[]{ "blur" };
		cv::namedWindow(name);
		cv::createTrackbar("Filter", name, &filter, 3, update, this);
		cv::createTrackbar("Size", name, &size, 31, update, this);
		while (true)
		{
			if(char(cv::waitKey(30) == 27))
				break;
		}
	}

	static void update(int pos, void* that)
	{
		auto self = static_cast<Cwiczenia3zadanie1*>(that);
		std::cout << pos << " "  << std::endl;
		self->realUpdate();
	}

	void realUpdate()
	{
		//cv::blur(input, output, cv::Size(size + 1, size + 1));
		//cv::bitwise_not(input, output);
		cv::imshow(name, output);
	}
};
