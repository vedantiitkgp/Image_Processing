#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
using namespace cv;

int main()
{
 int i,j,k;
 float hist[256];
 Mat img = imread("lenna.png",0);
 Mat img1((img.rows)*(img.cols)/200,255,CV_8UC1,Scalar(0));
 for(k=0;k<256;k++)
  {
  hist[k] =0;
  }
 for(i=0;i<img.rows;i++)
   {
    for(j=0;j<img.cols;j++)
      {
   
      for(k=0;k<256;k++)       
       {
        if(k==img.at<uchar>(i,j))
        { 
         hist[k]=hist[k]+0.1;
        }
       }
      }
   }
 for(j=0;j<256;j++)
   {
    for(i=0;i<(img.rows)*(img.cols)/200;i++)
      {
      if(i<((img.rows)*(img.cols)/200-hist[j]))
         {
           img1.at<uchar>(i,j) =255;
         }
      else
        {
        img1.at<uchar>(i,j) =0;
        }
      }
    }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img1);
waitKey(0);
return 0;
}

