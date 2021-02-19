#include "Simple_window.h"
#include "Graph.h"

int main()
{

	int xmax = 600;
	int ymax = 400;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int xlength = xmax - 40;
	int ylength = ymax - 40;


	Point origo{xmax/2,ymax/2};
	Point p{100,100};

	Simple_window win(p,xmax,ymax,"My window");

	Axis xt(Axis::x,Point{20,y_orig},xlength,20,"x tengely");
	Axis yt(Axis::y,Point{x_orig,ymax-20},ylength,20,"y tengely");

	Function sine(sin,0,14,Point{10,150},900,40,40);

	sine.set_color(Color::dark_blue);
	sine.set_style(Line_style(Line_style::solid,5));



	Polygon poly;

	poly.add(Point(400,100));
	poly.add(Point(450, 50));
	poly.add(Point(500,100));

	poly.set_fill_color(Color::blue);
	poly.set_style(Line_style(Line_style::dash));


	xt.set_color(Color::dark_red);
	yt.set_color(Color::dark_red);
	xt.label.set_color(Color::black);
	yt.label.set_color(Color::black);

	Rectangle r(Point(60,20),50,80);

	r.set_fill_color(Color::black);


	Closed_polyline poly_rect;
	poly_rect.add(Point(100,230));
	poly_rect.add(Point(200,230));
	poly_rect.add(Point(200,280));
	poly_rect.add(Point(100,280));
	poly_rect.add(Point(50,255));

	poly_rect.set_fill_color(Color::green);


	Text t(Point(430,85), "Triangle");

	t.set_font(Graph_lib::Font::times_bold);
	t.set_font_size(10);

	Image ii(Point{325,205},"download.jpeg");

	
	win.attach(r);
	win.attach(poly);
	win.attach(sine);
	win.attach(yt);
	win.attach(xt);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(ii);

	win.wait_for_button();

}