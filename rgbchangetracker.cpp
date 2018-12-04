#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <algorithm>
//using namespace std;
using namespace cv;
Mat img = imread("lenna.png");
Mat img1(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int ru,rl,gu,gl,bu,bl;

void update(int t, void *)
{
 for(int i=0;i<img.rows;i++)
  {
   for(int j=0;j<img.cols;j++)
   {
   if((img.at<Vec3b>(i,j)[0]>bl)&&(img.at<Vec3b>(i,j)[0]<bu)) img1.at<Vec3b>(i,j)[0]=255; 
   else img1.at<Vec3b>(i,j)[0]=0;
   if((img.at<Vec3b>(i,j)[1]>gl)&&(img.at<Vec3b>(i,j)[1]<gu)) img1.at<Vec3b>(i,j)[1]=255;
   else img1.at<Vec3b>(i,j)[1]=0;
   if((img.at<Vec3b>(i,j)[2]>rl)&&(img.at<Vec3b>(i,j)[2]<ru)) img1.at<Vec3b>(i,j)[2]=255;
   else img1.at<Vec3b>(i,j)[2]=0;
   }
  }
imshow("win1",img1);
}


int main()
{
int i,j;
namedWindow("win1",WINDOW_NORMAL);
createTrackbar("bluelower","win1",&bl,255,update);
createTrackbar("blueupper","win1",&bu,255,update);
createTrackbar("greenlower","win1",&gl,255,update);
createTrackbar("greenupper","win1",&gu,255,update);
createTrackbar("redlower","win1",&rl,255,update);
createTrackbar("redupper","win1",&ru,255,update);
waitKey(0);
return 0;
}

