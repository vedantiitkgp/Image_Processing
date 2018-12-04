#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
//using namespace std;
using namespace cv;
Mat img = imread("lenna.jpeg");
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));

void update1(int t,void *)
{
for(int i=0;i<img.rows;i++)
  {
   for(int j=0;j<img.cols;j++)
   {
       if(img.at<Vec3b>(i,j)[0]<t)
          {
            img1.at<Vec3b>(i,j)[0]=255;
          }
      else
          {
            img1.at<Vec3b>(i,j)[0]=0;
          }
   }
  }

imshow("win1",img1);
}

void update2(int t,void *)
{
for(int i=0;i<img.rows;i++)
  {
   for(int j=0;j<img.cols;j++)
   {
       if(img.at<Vec3b>(i,j)[1]<t)
          {
            img1.at<Vec3b>(i,j)[1]=255;
          }
      else
          {
            img1.at<Vec3b>(i,j)[1]=0;
          }
   }
  }

imshow("win1",img1);
}

void update3(int t,void *)
{
for(int i=0;i<img.rows;i++)
  {
   for(int j=0;j<img.cols;j++)
   {
       if(img.at<Vec3b>(i,j)[2]<t)
          {
            img1.at<Vec3b>(i,j)[2]=255;
          }
      else
          {
            img1.at<Vec3b>(i,j)[2]=0;
          }
   }
  }

imshow("win1",img1);
}

int main()
{
int i,j;
int th1=0,th2=0,th3=0;
namedWindow("win1",WINDOW_NORMAL);
createTrackbar("bluetrack","win1",&th1,255,update1);
createTrackbar("greentrack","win1",&th2,255,update2);
createTrackbar("redtrack","win1",&th3,255,update3);
waitKey(0);
return 0;
}


