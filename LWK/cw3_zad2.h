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
	int mode;
	char* name2;
	int threshold;
	int max_val;
	int threshold_type;
	int otsu;

	cw3_zad2(const cv::Mat image);

	void run();

	static void update(int, void* that);
	static void update2(int, void* that);
};
