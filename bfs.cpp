#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
using namespace cv;

struct Point
{
 int i;
 int j;
}

int main()
{
 queue<Point> myqueue;
 Mat img = imread("dfs_path.jpg",0);
 Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
 for(i=0;i<img.rows;i++)
  {
   for(j=0;j<img.cols;j++)
    {
     if(img.at<uchar>(i,j)==0&&img1.at<uchar>(i,j)!=120)
      {
       myqueue.push(i,j);
       for(k=-1;k<2;k++)
        {
         for(l=-1;l<2;l++)
          {
           if(img.at<uchar>(i+k,j+l)==0&&((i+k)>0)&&((j+l)>0)&&((i+k)<img.rows)&&((j+l)<img.cols))
            {
              myqueue.push(i+k,j+l);
              img1.at<uchar>(i+k,j+l)=120;
            }
          }
        }
       myqueue.pop();
      }
    else if(img1.at<uchar>(i,j)!=120)
      {
       img1.at<uchar>(i,j)=0;
      }    
    }
  } 
 myqueue.front(Pt2);//returns value

}
