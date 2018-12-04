#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
using namespace cv;
int main()
{
 int i,j,k,l,sum;
 Mat img = imread("lennanoise.png");
 Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
  for(i=0;i<img.rows;i++)
   {
     for(j=0;j<img.cols;j++)
      {
       sum =0;
      if((i>=0)&&((i+2)<img.rows)&&((j+2)<img.cols)&&(j>=0)) 
       {
          for(k=0;k<=2;k=k+2)
           {
             for(l=0;l<=2;l=l+2)
              {
               sum = sum + img.at<uchar>(i+k,j+l);
              }
           }

         img.at<uchar>(i+1,j+1) =(int)(sum/16.0+(1/8.0)*(img.at<uchar>(i,j+1)+img.at<uchar>(i+1,j)+img.at<uchar>(i+1,j+2)+img.at<uchar>(i+2,j+1))+(1/4.0)*img.at<uchar>(i+1,j+1));
       } 
      }
   }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img);
waitKey(0);
return 0;
}
