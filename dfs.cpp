#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <stack>
using namespace cv;//object detection in binary image using BFS Search
using namespace std;

Mat graytobin(Mat a)
{
	int i,j;
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)>127) a.at<uchar>(i,j)=255;
			else a.at<uchar>(i,j)=0;
		}
		return a;
}

int IsValid(int x,int y,int a,int b)
 {
	if (x>=0 and y>=0 and x<a-1 and y<b-1)return 1;
	else return 0;
 }
struct pixel
 {
	int x;
	int y;
 };

int main(){
	Mat a=imread("dfs_path.jpg",0);
	a=graytobin(a);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	b=a.clone();
imshow("win",b);
waitKey(0);
	int v[a.rows][a.cols],i,j,k,l,count=0;//v[][]=visited array to store 1 if pixel is visited else 0
	struct pixel p,u,m;
	stack<struct pixel>q;

	for (i=0;i<a.rows;i++)
		for (j=0;j<a.cols;j++)//initialise v
			v[i][j]=0;


	for (i=1;i<a.rows-1;i++)
	{//traverse all pixels of image
		for(j=1;j<a.cols-1;j++)
		{
			if (v[i][j]==0 && a.at<uchar>(i,j)==0)
			{//check if pixel is not visited and white
				v[i][j]=1;
				//c.at<uchar>(i,j) =255;(not required)
				p.x=i;
				p.y=j;
				q.push(p);
				count++;
				cout<<count<<'\n';
			}
			else if(v[i][j]==0)
			{
				c.at<uchar>(i,j) =255;
				v[i][j]=1;
			}
			int count1 =0;
			while (!q.empty())
			{
					count1++;
					u=q.top();
					q.pop();
					//cout<<u.x<<endl;
					c.at<uchar>(u.x,u.y)=60;
					for (k=u.x-1;k<u.x+2;k++)
					{//check the kernel 3*3 of point u
						for (l=u.y-1;l<u.y+2;l++)
						{
							if (IsValid(k,l,a.rows,a.cols))
							{
								if (b.at<uchar>(k,l)==0 && v[k][l]==0)
								{
									c.at<uchar>(k,l) =120;
									m.x=k;
									m.y=l;
									q.push(m);
									v[k][l]=1;

								}
							}
						}
					}
				//cout<<q.front().x<<" "<<q.front().y<<endl;
				if(count1>100)
				{
					imshow("image",c);
					waitKey(1);
					count1 =0;
				}	
 
			}
		}
						
		
	}
	imshow("image",c);
	waitKey(0);
	//cout<<a.rows<<endl;
	cout<<count<<endl; 
        return 0;
}