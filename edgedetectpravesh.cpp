#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <bits/stdc++.h>


using namespace std;
using namespace cv;

Mat img = imread("rubik.jpg",0);

Mat a(img.rows,img.cols,CV_8UC1,Scalar(255));
int median(int a, int b, int c, int d, int e,int f, int g, int h,int i)
{
  int arr[9];
  arr[0] = a;
  arr[1] = b;
  arr[2] =c;
  arr[3] =d;
  arr[4] =e;
  arr[5] =f;
  arr[6] = g;
  arr[7] =h;
  arr[8] =i;
  sort(arr, arr+9);
  return (arr[4]);
}
int check(int i, int j)
{
  if(i>0&&i<img.rows-1&&j>0&&j<img.cols-1)return 1;
  else return 0;
}
void update(int t,void *)
{

  float gx=0,gy=0;
  for(int i=1;i<img.rows-1;i++)
  {
    for(int j=1;j<img.cols-1;j++)
    {
        gx = (img.at<uchar>(i-1,j-1)*(-1)+img.at<uchar>(i-1,j+1)+img.at<uchar>(i+1,j-1)*(-1)+img.at<uchar>(i,j-1)*(-2)+img.at<uchar>(i+1,j+1)+img.at<uchar>(i,j+1)*2)/8;
        gy = (img.at<uchar>(i-1,j-1)*(-1)+img.at<uchar>(i-1,j+1)*(-1) +img.at<uchar>(i-1,j)*(-2)+img.at<uchar>(i+1,j-1)+img.at<uchar>(i+1,j)*2+img.at<uchar>(i+1,j+1))/8;
        if(sqrt(gx*gx+gy*gy)>t)
        {
          a.at<uchar>(i,j) = 0;
        }
        else
        {
          a.at<uchar>(i,j) = 255;

        }
    }
  }
  imshow("win",a);
}

int main()
{
  // for(int i=1;i<img.rows-1;i++)
  // {
  //   for(int j=1;j<img.cols-1;j++)
  //   {
  //       a.at<uchar>(i,j) = median(img.at<uchar>(i-1,j-1),img.at<uchar>(i,j),img.at<uchar>(i-1,j),img.at<uchar>(i-1,j+1),img.at<uchar>(i,j-1),img.at<uchar>(i,j+1),img.at<uchar>(i+1,j-1),img.at<uchar>(i+1,j),img.at<uchar>(i+1,j+1));
  //   }
  // }
  for(int i=1;i<img.rows-1;i++)
  {
    for(int j=1;j<img.cols-1;j++)
    {
        a.at<uchar>(i,j) = (a.at<uchar>(i-1,j-1)/16+a.at<uchar>(i,j)/4+a.at<uchar>(i-1,j)/8+a.at<uchar>(i-1,j+1)/16+a.at<uchar>(i,j-1)/8+a.at<uchar>(i,j+1)/8+a.at<uchar>(i+1,j-1)/16+a.at<uchar>(i+1,j)/8+a.at<uchar>(i+1,j+1)/16);
    }
  }
  int t;
  t=0;
  namedWindow("win",WINDOW_NORMAL);
  resizeWindow("win", 1000,1000);
  // imshow("win",a);
  // waitKey(0);

  createTrackbar("Bar","win",&t,255,update);
  waitKey(0);
    imwrite( "edgedetected.jpg",a);
}
