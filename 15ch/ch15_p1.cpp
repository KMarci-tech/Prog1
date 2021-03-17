#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}

double slope(double x) {return x/2; }

double square(double x) {return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}

int main()
{

	const int xmax = 600;
	const int ymax = 600;

	const int xlength = xmax - 200;
	const int ylength = ymax - 200;

	const int x_orig = xmax/2;
	const int y_orig = ymax/2;

	const Point orig = {300,300};

	const int x_scale = 20;
	const int y_scale = 20;

	const int r_min = -10;
	const int r_max = 11;

	const int n_points = 400;


	Simple_window win(Point(100,100),xmax,ymax,"Function graphs");

	Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
	Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");

	Function s(one,r_min,r_max,orig,n_points, x_scale,y_scale);
	Function s2(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
	Function s3(square,r_min,r_max,orig,n_points,x_scale,y_scale);
	Function s4(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
	Function s5(sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale);


	s4.set_color(Color::blue);
	Text ts(Point(120,370),"x/2");




	x.set_color(Color::red);
	y.set_color(Color::red);


	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(ts);
	win.wait_for_button();


	return 0;
}