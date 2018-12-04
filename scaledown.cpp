#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
using namespace cv;
int main()
{
int i,j,k,l;
Mat img = imread("lenna.png",0);
Mat img1(img.rows/2,img.cols/2,CV_8UC1,Scalar(0));
 for(i=0;i<img.rows;i=i+2)
   {
     for(j=0;j<img.cols;j=j+2)
      {
       img1.at<uchar>(i/2,j/2) =  (img.at<uchar>(i,j) + img.at<uchar>(i,j+1) + img.at<uchar>(i+1,j)+img.at<uchar>(i+1,j+1))/4 ;         
      }
   }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img1);
waitKey(0);
return 0;
}
