#pragma once

#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "Cwiczenia2zadanie5.h"

class Cwiczenia2random {
public:
	void run(cv::Mat image) {
		// Gray
		cv::Mat gray_image;
		cv::cvtColor(image, gray_image, CV_BGR2GRAY);
		cv::imshow("Gray", gray_image);
		cv::imwrite("./output.png", gray_image);

		// Random
		cv::Mat R = cv::Mat(cv::Size(image.cols, image.rows), image.type());
		randu(R, cv::Scalar::all(0), cv::Scalar::all(255));
		cv::imshow("Rand", R);

		// Clash colors
		std::vector<cv::Mat> colors = Cwiczenia2zadanie5().run(image);

		std::vector<cv::Mat> clash;
		clash.push_back(colors[2]);
		clash.push_back(colors[0]);
		clash.push_back(colors[1]);
		cv::Mat mat_clash;
		cv::merge(clash, mat_clash);
		cv::imshow("Clash", mat_clash);
	}
};