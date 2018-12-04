#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace cv;
Mat img = imread("rubik.jpg",0);
Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
void updatefunct(int t,void *)
{
int i,j,gx,gy,k,l,sum;
for( i=0;i<img.rows;i++)
   {
     for( j=0;j<img.cols;j++)
      {
      if((i+2)<img.rows&&(j+2)<img.cols) 
        {
         gx = -img.at<uchar>(i-1,j-1)-img.at<uchar>(i,j-1)-img.at<uchar>(i+1,j-1)+img.at<uchar>(i-1,j+1)  +img.at<uchar>(i,j+1)+img.at<uchar>(i+1,j+1);
         gy = -img.at<uchar>(i-1,j-1)-img.at<uchar>(i-1,j)-img.at<uchar>(i-1,j+1)+img.at<uchar>(i+1,j-1)+img.at<uchar>(i+1,j)+img.at<uchar>(i+1,j+1);
         int k = sqrt(pow(gx,2)+pow(gy,2));
        if(k>t)
          {
            img3.at<uchar>(i,j)=255;
          }
      else
          {
            img3.at<uchar>(i,j)=0;
          }

      for(k=0;k<=2;k++)
           {
             for(l=0;l<=2;l++)
              {
               sum = sum + img3.at<uchar>(i+l,j+k);
              }
           }
         img3.at<uchar>(i+1,j+1) =sum/9;
        }
      } 
      
    }
 imshow("win1",img3);
}
int main()
{
 int th=0;
 namedWindow("win1",WINDOW_NORMAL);
 createTrackbar("trackbar_name","win1",&th,255,updatefunct);
 waitKey(0);
 imwrite("edgedetect1.jpg",img3);
 return 0;
}
 
