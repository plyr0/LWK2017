#include "stdafx.h"
#include "cw4_zad1.h"


cw4_zad1::cw4_zad1() : name("cw4 morph"), shape(cv::MORPH_RECT), mode(0), size(0)
{
	input = imread("test1.jpg", cv::COLOR_RGB2GRAY);
	std::cout << input.channels() << " " <<  input.type() << std::endl;
}

void cw4_zad1::run()
{
	cv::namedWindow(name);
	cv::createTrackbar("Mode", name, &mode, 6, update, this);
	cv::createTrackbar("k shape", name, &shape, 2, update, this);
	cv::createTrackbar("k size", name, &size, 10, update, this);
	update(0, this);
	while (true)
	{
		if (char(cv::waitKey(30) == 27))
			break;
		if (!cvGetWindowHandle(name))
			break;
	}
}

void cw4_zad1::update(int ignored, void* that)
{
	const auto self = static_cast<cw4_zad1*>(that);

	int shape;
	switch (self->shape) {
	case 0:	
		shape = cv::MORPH_RECT;
		std::cout << "MORPH_RECT ";
		break;
	case 1:
		shape = cv::MORPH_CROSS;
		std::cout << "MORPH_CROSS ";
		break;
	case 2:
		shape = cv::MORPH_ELLIPSE;
		std::cout << "MORPH_ELLIPSE ";
		break;
	default: 
		throw "WTF";
	}
	const cv::Size ksize(2 * (self->size + 1) + 1, 2 * (self->size + 1) + 1);
	const cv::Point anchor(ksize.width/2, ksize.height/2);
	const auto kernel = getStructuringElement(shape, ksize, anchor);

	if (self->mode == 0)
	{
		erode(self->input, self->output, kernel);
		std::cout << "erode" << std::endl;
	} 
	else if (self->mode == 1) 
	{
		dilate(self->input, self->output, kernel);
		std::cout << "dilate" << std::endl;
	} 
	else {
		morphologyEx(self->input, self->output, self->mode - 2, kernel);
		switch (self->mode)
		{
		case 2:
			std::cout << "opening" << std::endl; break;
		case 3:
			std::cout << "closing" << std::endl; break;
		case 4:
			std::cout << "gradient" << std::endl; break;
		case 5:
			std::cout << "top hat" << std::endl; break;
		case 6:
			std::cout << "black hat" << std::endl; break;
		default:
			throw "WTF 2";
		}
	}
	imshow(self->name, self->output);
}
