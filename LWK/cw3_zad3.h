#pragma once

#include "stdafx.h"

class cw3_zad3
{
public:
	char* name;
	cv::Mat input;
	cv::Mat output;
	int rot;
	int fx;
	int fy;
	int gray;

	cw3_zad3(cv::Mat image);

	void run();

	static void update(int pos, void* that);
};

inline cw3_zad3::cw3_zad3(cv::Mat image) : name("cw3zad3-transform"),rot(0),fx(10),fy(10),gray(0)
{
	input = image.clone();
	output = cv::Mat(input.size(), input.type());
}

inline void cw3_zad3::run()
{
	cv::namedWindow(name);// , cv::WINDOW_NORMAL);
	cv::createTrackbar("Gray", name, &gray, 1, update, this);
	cv::createTrackbar("x", name, &fx, 100, update, this);
	cv::createTrackbar("y", name, &fy, 100, update, this);
	cv::createTrackbar("Rot", name, &rot, 359, update, this);
	update(0, this);
	while (true)
	{
		if (char(cv::waitKey(30) == 27))
			break;
		if (!cvGetWindowHandle(name))
			break;
	}
}

inline void cw3_zad3::update(int, void* that)
{
	auto self = static_cast<cw3_zad3*>(that);

	if (self->gray) {
		cv::cvtColor(self->input, self->output, cv::COLOR_BGR2GRAY);
	} else
	{
		self->output = self->input.clone();
	}

	const auto x = (self->fx + 1) / 10.0;
	const auto y = (self->fy + 1) / 10.0;
	cv::resize(self->output, self->output, cv::Size(0, 0), x, y, cv::INTER_LINEAR);

	const cv::Point2f center(self->output.cols / 2, self->output.rows / 2);
	const cv::Mat rotation =  cv::getRotationMatrix2D(center, self->rot, 1.0);
	const auto size = cv::Size(self->output.cols, self->output.rows);
	cv::warpAffine(self->output, self->output , rotation, size);

	cv::imshow(self->name, self->output);
}
