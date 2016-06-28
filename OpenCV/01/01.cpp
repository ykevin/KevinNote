#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	//cv::Mat image(240, 320, CV_8U, cv::Scalar(0));
	cv::Mat image;
	image = cv::imread("../mm.jpg");
	cv::Mat newImage;
	//newImage.create(image.size(), image.type());
	//image.copyTo(newImage);
	newImage = image.clone();
	cv::namedWindow("ppmm");
	cv::imshow("ppmm", newImage);
	cv::waitKey(5000);
	return 0;
}
