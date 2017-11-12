#include "stdafx.h"

#include "cw3_zad1.h"
#include "cw2_random.h"
#include "cw2_zad6.h"
#include "cw3_zad2.h"

int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("Lenna.png", CV_LOAD_IMAGE_UNCHANGED);

	if (image.empty())
	{
		std::cout << "Could not open or find the image" << std::endl;
		std::cin.get();
		return -1;
	}
	std::cout << "xy - nr zadania, np: 25 = cw2zad5\n0, 20, 25, 26, 31, 32\n";
	int k=32;
	//std::cin >> k;
	switch (k) {
	case 0:
		imshow("Original", image);
		std::cout << "eee";	
		cv::waitKey();
		break;
	case 20:
		cw2_random().run(image);
		break;
	case 25:
		cw2_zad5().run(image);
		break;
	case 26:
		cw2_zad6().run(image);
		break;
	case 31:
		cw3_zad1(image).run();
		break;
	case 32:
		cw3_zad2(image).run();
		break;
	default:
		break;
	}
	return 0;
}
