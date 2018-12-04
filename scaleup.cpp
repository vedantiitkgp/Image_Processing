#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
using namespace cv;
int main()
{
int i,j,k,l;
Mat img = imread("lenna.png",0);
Mat img1(3*img.rows,3*img.cols,CV_8UC1,Scalar(0));
 for(i=0;i<img.rows;i++)
   {
     for(j=0;j<img.cols;j++)
      {
        for(k=3*i;k<3*(i+1);k++)
         {
          for(l=3*j;l<3*(j+1);l++)
           {
             img1.at<uchar>(k,l) = img.at<uchar>(i,j);
           }
         }      
      }
   }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img1);
waitKey(0);
return 0;
}
