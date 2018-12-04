#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
//using namespace std;
using namespace cv;
int main()
{
int i,j;
Mat img = imread("lenna.jpeg");
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
for(i=0;i<img.rows;i++)
  {
   for(j=0;j<img.cols;j++)
   {
     img1.at<uchar>(i,j) =(0.07*img.at<Vec3b>(i,j)[0] + 0.72*img.at<Vec3b>(i,j)[1] +0.21* img.at<Vec3b>(i,j)[2]);
       if(img1.at<uchar>(i,j)>125)
          {
            img1.at<uchar>(i,j)=255;
          }
      else
          {
            img1.at<uchar>(i,j)=0;
          }
   }
  }

namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img1);

waitKey(0);
return 0;
}
