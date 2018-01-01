#pragma once
#include "stdafx.h"

class cw4_zad1
{
public:
	cw4_zad1();
	char* name;
	cv::Mat input;
	cv::Mat output;
	int shape;
	int mode;
	int size;

	void run();

	static void update(int pos, void* that);
};

