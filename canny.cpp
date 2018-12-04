#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace cv;
int main()
{
Mat img = imread("rubik.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
Canny(img,img1,50,100,3,0);// Canny(img,img1,lower_threshold,Lower_threshold*ratio,Kernel,flag=0)//sqrt(pow(gx,2)+pow(gy,2))//flag=1//mod(gx)+mod(gy)
namedWindow("win1",WINDOW_AUTOSIZE);
imshow("win1",img1);
waitKey(0);
imwrite("canny.jpg",img1);
}
