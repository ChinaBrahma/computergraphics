//Program tom implement bresenham's line drawing algorithm

#include<iostream>
#include<graphics.h>

using namespace std;

void drawline(int x0, int y0, int x1, int y1){
	int dx,dy,p,x,y;
	dx=x1-x0;
	dy=y1-y0;
	
	x=x0;
	y=y0;
	
	p=2*dy-dx;
	
	while(x<x1){
		if(p>=0){
			putpixel(x,y,7);
			y=y+1;
			p=p+2*dy-2*dx;
			}
			else{
				putpixel(x,y,7);
				p=p+2*dy;
			}
			x=x+1;
		}
}


int main(){
	int gd=DETECT,gm;
	int error,x0,x1,y0,y1;
	
	initgraph(&gd,&gm, (char*)"");
	
	cout<<"\nEnter x0,y0:"<<endl;
	cin>>x0>>y0;
	cout<<"\nEnter x1,y1:"<<endl;
	cin>>x1>>y1;
	
	drawline(x0,y0,x1,y1);
	drawline(100,100,200,200);
	
	getch();
	closegraph();
	return 0;
}
