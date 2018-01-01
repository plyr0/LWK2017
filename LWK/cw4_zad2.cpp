#include "stdafx.h"
#include "cw4_zad2.h"


cw4_zad2::cw4_zad2(): name("cw4 hist"), factor(4096), threshold(0)
{
	input = imread("test1.jpg", cv::COLOR_RGB2GRAY);
	std::cout << input.channels() << " " << input.type() << std::endl;

	std::vector<cv::Mat> planes;
	split(input, planes);
	input = planes[0];
}

void cw4_zad2::run()
{
	namedWindow(name, cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("factor", name, &factor, 100000, update, this);
	cv::createTrackbar("threshold", name, &threshold, 255, update, this);
	update(0, this);
	while (true)
	{
		if (char(cv::waitKey(30) == 27))
			break;
		if (!cvGetWindowHandle(name))
			break;
	}
}

void cw4_zad2::update(int ignored, void* that)
{
	const auto self = static_cast<cw4_zad2*>(that);
	self->hist();
}

void cw4_zad2::hist()
{
	cv::Mat histogram;
	calcHist(&input, 1, nullptr, cv::Mat(), histogram, 1, &histSize, &histRange, uniform, accumulate);

	normalize(histogram, histogram, factor, 0, cv::NORM_L1); // jak cvNormalizeHist()
	cv::threshold(histogram, histogram, threshold, 0, CV_THRESH_TOZERO); // jak cvThreshHist()

	const int hist_w = 512, hist_h = 256;
	const int bin_w = cvRound(static_cast<double>(hist_w) / histSize);
	cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(0, 0, 0));
	
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(histogram.at<float>(i - 1))),
			cv::Point(bin_w*(i), hist_h - cvRound(histogram.at<float>(i))),
			cv::Scalar(255, 255, 255), 2, 8, 0);
	}
	imshow(name, histImage);
}

