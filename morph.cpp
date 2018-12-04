#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
using namespace cv;

int main()
{
 int i,j,hist[256],k;
 Mat img1 = imread("whale.jpg");
 Mat img2 = imread("water.jpg");
 Mat img3(700,700,CV_8UC3,Scalar(0,0,0));

 for(i=0;i<700;i++)
  {
    for(j=0;j<700;j++)
     {
    img3.at<Vec3b>(i,j)[0] = img1.at<Vec3b>(i,j)[0]/2 +img2.at<Vec3b>(i,j)[0]/2;
    img3.at<Vec3b>(i,j)[1] = img1.at<Vec3b>(i,j)[1]/2 +img2.at<Vec3b>(i,j)[1]/2;
    img3.at<Vec3b>(i,j)[2] = img1.at<Vec3b>(i,j)[2]/2 +img2.at<Vec3b>(i,j)[2]/2;
     }
  }
namedWindow("win1",WINDOW_NORMAL);
imshow("win1",img3);
waitKey(0);
return 0;
}
