#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
//using namespace std;
using namespace cv;
int main()
{
int i,j;
Mat img=imread("lenna.jpeg");
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
 for(i=0;i<img.rows;i++)
  {
   for(j=0;j<img.cols;j++)
   {
     img1.at<uchar>(i,j) =(img.at<Vec3b>(i,j)[0] + img.at<Vec3b>(i,j)[1] + img.at<Vec3b>(i,j)[2])/3;
   }
  }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img1);
for(i=0;i<img.rows;i++)
  {
   for(j=0;j<img.cols;j++)
   {
     img2.at<uchar>(i,j) =(std::max(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2])+std::min(img.at<Vec3b>(i,j)[0],img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]))/2;
   }
  }
namedWindow("win2",WINDOW_NORMAL);
imshow("win2",img2);

for(i=0;i<img.rows;i++)
  {
   for(j=0;j<img.cols;j++)
   {
     img2.at<uchar>(i,j) =(0.07*img.at<Vec3b>(i,j)[0] + 0.72*img.at<Vec3b>(i,j)[1] +0.21* img.at<Vec3b>(i,j)[2]);
   }
  }
namedWindow("win3",WINDOW_NORMAL);
imshow("win3",img3);
waitKey(0);
return 0;
}
