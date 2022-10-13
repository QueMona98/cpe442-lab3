/************************************************************
*************************************************************
* File: sobel.cpp
*
*
* ************************************************************/
#include "sobel.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/matx.hpp>
#include <iostream>

using namespace cv;

Mat to442_greyscale(Mat frame);

int main (int argc, char *argv[]) {

	if (argc != 2) {
		std::cerr << "Missing argument -- include path to file" << std::endl;
		exit(1);
	}

	VideoCapture cap(argv[1]);
	Mat frame;

	for(;;) {

		cap >> frame;

		if(frame.empty())
			break;

		frame = to442_greyscale(frame);
		resize(frame, frame, Size(frame.cols/3, frame.rows/3));
		namedWindow("Display frame", WINDOW_NORMAL);
		imshow("Display frame", frame);

		if (waitKey(1) == 27)
			break;
	}
	return 0;

}

Mat to442_greyscale(Mat frame) {
        float grey;

        for(int row=0; row < frame.rows; row++){

                for(int col=0; col<frame.cols; col++){

                        Vec3b colors = frame.at<Vec3b>(Point(col,row));
			
                        /*BT.709 recommended algorithm*/
                        grey = colors.val[0]*0.0722 + colors.val[1]*0.7152 + colors.val[2]*0.2126;
                        colors.val[0]=grey;//Blue
                        colors.val[1]=grey;//Green
                        colors.val[2]=grey;//Red

                        frame.at<Vec3b>(Point(col, row)) = colors;
                }
        }
	return frame;
}

/*Visuals on how to implement the matrices
 *p0 p1 p2        -1 0 1      1  2  1
 *p3 p4 p5     Gx=-2 0 2  Gy= 0  0  0
 *p6 p7 p8        -1 0 1     -1 -2 -1
 * */

//void to442_sobel(Mat frame, Mat sobelFrame){
//      Vec3b sobelColor;
//      int p0, p1, p2, p3, p4, p5, p6, p7, p8;
//      int Gx, Gy, G;
//      int col0 = 0;
//      int row0 = 0;

 
