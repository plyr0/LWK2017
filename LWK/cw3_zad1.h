#pragma once

#include "stdafx.h"

class cw3_zad1
{
public:
	char* name;
	cv::Mat input;
	cv::Mat output;
	int filter;
	int size;

	cw3_zad1(cv::Mat image);

	void run();

	static void update(int pos, void* that);

	void real_update();
};

inline cw3_zad1::cw3_zad1(cv::Mat image) : name("filter"), filter(3), size(27)
{
	input = image.clone();
	output = cv::Mat(input.size(), input.type());
}

inline void cw3_zad1::run()
{
	cv::namedWindow(name);
	cv::createTrackbar("Filter", name, &filter, 3, update, this);
	cv::createTrackbar("Size", name, &size, 47, update, this);
	real_update();
	while (true)
	{
		if (char(cv::waitKey(30) == 27))
			break;
		if (!cvGetWindowHandle(name))
			break;
	}
}

inline void cw3_zad1::update(int, void* that)
{
	auto self = static_cast<cw3_zad1*>(that);
	switch (self->filter)
	{
	case 0: std::cout << "blur"; break;
	case 1: std::cout << "GaussianBlur"; break;
	case 2: std::cout << "medianBlur"; break;
	case 3: std::cout << "bilateralFilter"; break;
	default:
		throw "Unknown filter";
	}
	std::cout << " " << self->size << std::endl;
	self->real_update();
}

inline void cw3_zad1::real_update()
{
	if (!size) size++;
	switch (filter)
	{
	case 0:
		cv::blur(input, output, cv::Size(size, size));
		break;
	case 1:
		cv::GaussianBlur(input, output, cv::Size(2 * size + 1, 2 * size + 1), 0, 0);
		break;
	case 2:
		cv::medianBlur(input, output, 2 * size + 1);
		break;
	case 3:
		cv::bilateralFilter(input, output, size, size * 2, size / 2);
		break;
	default:
		throw "Unknown filter";
	}
	cv::imshow(name, output);
}
