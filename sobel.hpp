/*********************************************************************************
* File: sobel.hpp
*
* **********************************************************************/

#ifdef SOBEL_H
#define SOBEL_H

#include <opencv2/opencv.hpp>

void to442_greyscale(cv::Mat frame);
void to442_sobel(cv::Mat frame, cv::Mat sobelFrame);

#endif
