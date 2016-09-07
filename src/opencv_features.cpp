#include "opencv2/opencv.hpp"
#include <stdio.h>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace cv::xfeatures2d;

int main(int, char**)
{
	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened()) { // check if we succeeded
		printf("nope\n");
		return -1;
	}

	//Mat pic;
	namedWindow("pic",1);
	//	for(;;)	{
		//Mat frame;
		//cap >> frame;
		Mat pic = imread( "./sciencyfeatures.png", IMREAD_GRAYSCALE );
		//cvtColor(frame, pic, CV_BGR2GRAY);
		int minHessian = 400;
		Ptr<SURF> detector = SURF::create( minHessian );
		std::vector<KeyPoint> keypoints_1;
		detector->detect( pic, keypoints_1 );
		Mat img_keypoints_1;
		drawKeypoints( pic, keypoints_1, img_keypoints_1, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
		imshow("Keypoints 1", img_keypoints_1 );
		waitKey(0);
		//	}



	return 0;
}
