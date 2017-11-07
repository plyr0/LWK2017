#pragma once

#include "stdafx.h"

class Cwiczenia3zadanie1 {
public:
	char* name;
	cv::Mat input;
	cv::Mat output;
	int filter;
	int size;

	Cwiczenia3zadanie1(cv::Mat image);

	void run();

	static void update(int pos, void* that);

	void realUpdate();
};
