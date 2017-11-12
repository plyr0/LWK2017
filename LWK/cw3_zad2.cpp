#include "stdafx.h"
#include "cw3_zad2.h"

cw3_zad2::cw3_zad2(const cv::Mat image) 
: name("cw3zad2-hsv"), hue1(97), hue2(176), name2("cw3zad2 - threshold"), threshold(128), 
  max_val(255), threshold_type(7), otsu(0)
{
	input = image.clone();
	output = cv::Mat(input.size(), input.type());
}

void cw3_zad2::run()
{
	cv::namedWindow(name);
	cv::createTrackbar("Start", name, &hue1, 179, update_a, this);
	cv::createTrackbar("End", name, &hue2, 179, update_b, this);
	update(0, this);
	
	cv::namedWindow(name2);
	cv::createTrackbar("Type", name2, &threshold_type, 7, update2, this);
	cv::createTrackbar("Otsu/mthd", name2, &otsu, 2, update2, this);
	cv::createTrackbar("Trhld/size", name2, &threshold, 255, update2, this);
	cv::createTrackbar("Max value", name2, &max_val, 255, update2, this);
	update2(0, this);

	while (true)
	{
		if (char(cv::waitKey(30) == 27))
			break;
		if (!cvGetWindowHandle(name) || !cvGetWindowHandle(name2))
			break;
	}
}

void cw3_zad2::update_a(int, void* that)
{
	const auto self = static_cast<cw3_zad2*>(that);
	if(self->hue1 > self->hue2)
	{
		self->hue2 = self->hue1;
		cvSetTrackbarPos("End", self->name, self->hue2);
	}
	update(0, that);
}

void cw3_zad2::update_b(int, void* that)
{
	const auto self = static_cast<cw3_zad2*>(that);
	if (self->hue2 < self->hue1)
	{
		self->hue1 = self->hue2;
		cvSetTrackbarPos("Start", self->name, self->hue1);
	}
	update(0, that);
}

void cw3_zad2::update(int, void* that)
{
	const auto self = static_cast<cw3_zad2*>(that);	
	cv::cvtColor(self->input, self->output, CV_RGB2HSV);

	cv::Mat mask;
	const auto lowerb = cv::Scalar(self->hue1, 0, 0);
	const auto upperb = cv::Scalar(self->hue2, 255, 255);
	cv::inRange(self->output, lowerb, upperb, mask);

	cv::Mat masked;
	self->output.copyTo(masked, mask);
	
	cv::cvtColor(masked, self->output, CV_HSV2RGB);
	cv::imshow(self->name, self->output);
}

void cw3_zad2::update2(int, void* that)
{
	const auto self = static_cast<cw3_zad2*>(that);
	cv::Mat gray;
	cv::cvtColor(self->input, gray, cv::COLOR_BGR2GRAY);
	
	int threshold_type = 0;
	switch (self->threshold_type)
	{
	case 0: 
		threshold_type = cv::THRESH_BINARY; 
		std::cout << "THRESH_BINARY"; 
		break;
	case 1: 
		threshold_type = cv::THRESH_BINARY_INV; 
		std::cout << "THRESH_BINARY_INV"; 
		break;
	case 2: 
		threshold_type = cv::THRESH_TRUNC; 
		std::cout << "THRESH_TRUNC"; 
		break;
	case 3: 
		threshold_type = cv::THRESH_TOZERO; 
		std::cout << "THRESH_TOZERO"; 
		break;
	case 4:
		threshold_type = cv::THRESH_TOZERO_INV;
		std::cout << "THRESH_TOZERO_INV";
		break; 
	case 5: break;
	case 6: break;
	case 7:
		cv::imshow(self->name2, gray);
		std::cout << "Original gray" << std::endl; 
		return;
	default: throw "WTF";
	}
	if (self->threshold_type < 5) {
		if (!self->otsu) {
			cv::threshold(gray, self->output, self->threshold, self->max_val, threshold_type);
		} 
		else {
			if (self->otsu == 1) {
				threshold_type |= cv::THRESH_OTSU;
				std::cout << " | THRESH_OTSU";
			}
			else if (self->otsu == 2) {
				threshold_type |= cv::THRESH_TRIANGLE;
				std::cout << " | THRESH_TRIANGLE";
			}
			const auto otsu_val = cv::threshold(gray, self->output, 0, self->max_val, threshold_type);
			std::cout << " Otsu threshold: " << otsu_val;
		}
	}  
	else  {
		const auto method = self->otsu ? cv::ADAPTIVE_THRESH_GAUSSIAN_C : cv::ADAPTIVE_THRESH_MEAN_C;
		const auto type = self->threshold_type==5 ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
		const auto blockSize = (self->threshold+1) * 2 + 1;
		const auto C = 0;
		cv::adaptiveThreshold(gray, self->output, self->max_val, method, type, blockSize, C);
		std::cout << (method ? "ADAPTIVE_THRESH_GAUSSIAN_C" : "ADAPTIVE_THRESH_MEAN_C");
		std::cout << " type " << (type?"THRESH_BINARY_INV":"THRESH_BINARY");
	}
	std::cout << std::endl;
	cv::imshow(self->name2, self->output);
}