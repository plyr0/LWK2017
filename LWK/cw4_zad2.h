#pragma once
class cw4_zad2
{
public:
	cw4_zad2();
	char* name;
	cv::Mat input;
	cv::Mat output;
	int factor;
	int threshold;

	const int histSize = 256;
	const float range[2] = { 0, 256 };
	const float* histRange = { range };
	const bool uniform = true;
	const bool accumulate = false;
	
	void run();

	static void update(int pos, void* that);

	void hist();
};

