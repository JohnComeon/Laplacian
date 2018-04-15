#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	Mat src, dst;
	src = imread("C:\\IMAGE\\2.jpg");
	if (!src.data)
	{
		printf("could not load...");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "Laplacian image";
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	Mat blur_src, gray_src;
	GaussianBlur(src, blur_src, Size(3, 3), 11, 11);           //高斯模糊
	cvtColor(blur_src, gray_src, CV_BGR2GRAY);        //转换为灰度图
	imshow("gray image", gray_src);
	
	Mat edge_image;
	Laplacian(gray_src,edge_image,CV_16S,3);
	convertScaleAbs(edge_image, edge_image);
	threshold(edge_image, edge_image, 0, 255, THRESH_OTSU | THRESH_BINARY);    //去除噪声
	imshow(output_title,edge_image);
	imwrite("C:\\IMAGE\\Laplacian.jpg", edge_image);

	

	waitKey(0);
	return 0;
}