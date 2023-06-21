// C++ program for implementing
// Mid-Point Circle Drawing Algorithm
//Working file
#include<iostream>
#include<graphics.h>

using namespace std;

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(int x0, int y0, int r)
{
	int x = r, y = 0;
	
	// Printing the initial point on the axes
	// after translation
	putpixel( x + x0, y + y0, 7);
	
	// When radius is zero only a single
	// point will be printed
	if (r > 0)
	{
		putpixel(x + x0,-y + y0,7);
		putpixel( y + x0, x + y0,7);
		putpixel(-y + x0,x + y0,7);
	}
	
	// Initialising the value of P
	int P = 1 - r;
	while (x > y)
	{
		y++;
		
		// Mid-point is inside or on the perimeter
		if (P <= 0)
			P = P + 2*y + 1;
		// Mid-point is outside the perimeter
		else
		{
			x--;
			P = P + 2*y - 2*x + 1;
		}
		
		// All the perimeter points have already been printed
		if (x < y)
			break;
		
		// Printing the generated point and its reflection
		// in the other octants after translation
		putpixel(x + x0, y + y0, 7);
		putpixel(-x + x0, y + y0, 7);
		putpixel(x + x0, -y + y0, 7);
		putpixel(-x + x0,-y + y0, 7);
		
		// If the generated point is on the line x = y then
		// the perimeter points have already been printed
		if (x != y)
		{
			putpixel( y + x0,x + y0,7);
			putpixel(-y + x0,x + y0,7);
			putpixel(y + x0,-x + y0,7);
			putpixel(-y + x0,-x + y0,7);
		}
	}
}

// Driver code
int main()
{
	// To draw a circle of radius 3 centered at (0, 0)
	int gd=DETECT, gm;
	initgraph(&gd,&gm,(char*)"");
	
	int x,y,r;
	cout<<"\nEnter The Coordinate : "; //300 300
	cin>>x>>y;
	cout<<"\nEnter radius : "; //100
	cin>>r;
	midPointCircleDraw(x,y,r);
	getch();
	closegraph();
	
	return 0;
} 

