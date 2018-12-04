#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;
int main()
{
int i,j;
Mat img(100,100,CV_8UC3,Scalar(0,0,0));
for(i=0;i<100;i++)
{
 for(j=0;j<100;j++)
 {
  if ((i+j)<99)
   {
    img.at<Vec3b>(i,j) ={0,0,255};
   }
  else
   {
    img.at<Vec3b>(i,j) ={0,255,0};
   }
 }
} 
namedWindow("win",WINDOW_NORMAL);
imshow("win",img);
 waitKey(0);
return 0;
}


