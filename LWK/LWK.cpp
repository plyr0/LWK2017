#include "stdafx.h"

#include "Cwiczenia2random.h"
#include "Cwiczenia2zadanie5.h"
#include "Cwiczenia2zadanie6.h"
#include "Cwiczenia3zadanie1.h"

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("Lenna.png", CV_LOAD_IMAGE_UNCHANGED);

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}
	//imshow("Original", image);
	//Cwiczenia2random().run(image);
	
	//Cwiczenia2zadanie5().run(image);
	//Cwiczenia2zadanie6().run(image);

	Cwiczenia3zadanie1(image).run();

	return 0;
}