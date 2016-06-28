#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/*
void colorReduce(cv::Mat& image, int div)
{
	for(int i = 0; i < image.rows; i++) {
		for(int j = 0; j < image.cols; j++){
			image.at<cv::Vec3b>(i, j)[0] = image.at<cv::Vec3b>(i, j)[0]/div*div + div/2;
			image.at<cv::Vec3b>(i, j)[1] = image.at<cv::Vec3b>(i, j)[1]/div*div + div/2;
			image.at<cv::Vec3b>(i, j)[2] = image.at<cv::Vec3b>(i, j)[2]/div*div + div/2;
		}
	}
}
*/

/*
void colorReduce(const cv::Mat& image, cv::Mat& outImage, int div)
{
	outImage.create(image.size(), image.type());
	int nr = image.rows;
	int nl = image.cols * image.channels();
	for(int i = 0; i < nr; i++){
		const uchar* intData = image.ptr<uchar>(i);
		uchar* outData = outImage.ptr<uchar>(i);
		for(int j = 0; j < nl; j++) {
			outData[j] = intData[j]/div*div + div/2;
		}
	}
}
*/

void colorReduce(const cv::Mat& image, cv::Mat& outImage, int div)
{
	int nr = image.rows;
	int nc = image.cols;
	outImage.create(image.size(), image.type());
	if(image.isContinuous() && outImage.isContinuous())
		nc = nc*nr*image.channels();

	const uchar* inData = image.ptr<uchar>(0);
	uchar* outData = outImage.ptr<uchar>(0);
	for(int j = 0; j < nc; j++){
		*outData++ = *inData++/div*div + div/2;
	}
	/*
	if(image.isContinuous() && outImage.isContinuous()){
		nr = 1;
		nc = nc*image.rows*image.channels();
	}
	for(int i = 0; i < nr; i++){
		const uchar* inData = image.ptr<uchar>(i);
		uchar* outData = outImage.ptr<uchar>(i);
		for(int j = 0; j < nc; j++){
			*outData++ = *inData++/div*div + div/2;
		}
	}
	*/
}


int main()
{
	cv::Mat image, outImage;
	image = cv::imread("../mm.jpg");
	//colorReduce(image, 32);
	colorReduce(image, outImage, 32);
	cv::namedWindow("ppmm");
	cv::imshow("ppmm", outImage);
	cv::waitKey(5000);

	return 0;
}
