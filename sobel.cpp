************************************************************
*************************************************************
* File: sobel.cpp
*
*
* ************************************************************
*
#include "sobel.hpp"

void to442_greyscle(Mat frame){
        float grey;
        for(int row=0; row < frame.rows; row++){
                for(int col=0; col<frame.cols; col++){
                        Vec3b colors = frame.at<Vec3b>(Point(col,row));
                        /*BT.709 recommended algorithm*/
                        grey = color.val[0]*0.0722 + color.val[1]*0.7152 + color.val[2]*0.2126;
                        color.val[0]=grey;//Blue
                        color.val[1]=grey;//Green
                        color.val[2]=grey;//Red

                        frame.at<Vec3b>(Point(col, row)) = color;
                }
        }
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


