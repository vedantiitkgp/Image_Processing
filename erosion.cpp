#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace cv;
Mat img = imread("dialation.jpg",0);
Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
int main()
{
 for(int i=0;i<img.rows;i++)
   {
     for(int j=0;j<img.cols;j++)
      {
      if((i+2)<img.rows&&(j+2)<img.cols) 
        { 
	int flag =0;
         for(int k=0;k<=2;k++)
           {
             for(int l=0;l<=2;l++)
              {
               if(img.at<uchar>(i+l,j+k)==0)
                 {
                   flag =1;
                 }    
              }
           }
	if(flag==1) img3.at<uchar>(i+1,j+1)=0;
        else img3.at<uchar>(i+1,j+1)=255;         
        }
      }
   }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img3);
waitKey(0);
 imwrite("erosion.jpg",img3);
 return 0; 
}
