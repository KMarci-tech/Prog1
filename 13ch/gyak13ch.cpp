#include "Graph.h"
#include "Simple_window.h"

int main()
{
	
	int x_max = 800;
	int y_max = 1000;
	int x_grid = 100;
	int y_grid = 100;
	int i_x = 0;
	int i_y = 0;
	


	Simple_window win(Point{100,100},x_max,y_max,"13ch drill");

	Lines grid;
	for(int x=x_grid; x<=800; x+= x_grid)
		grid.add(Point(x,0),Point(x,800));
	for(int y = y_grid; y<=800; y+=y_grid)
		grid.add(Point(0,y),Point(x_max,y));

	Rectangle rect00(Point(0,0),100,100);
	Rectangle rect01(Point(100,100),100,100);
	Rectangle rect02(Point(200,200),100,100);
	Rectangle rect03(Point(300,300),100,100);
	Rectangle rect04(Point(400,400),100,100);
	Rectangle rect05(Point(500,500),100,100);
	Rectangle rect06(Point(600,600),100,100);
	Rectangle rect07(Point(700,700),100,100);


	rect00.set_fill_color(Color::red);
	rect01.set_fill_color(Color::red);
	rect02.set_fill_color(Color::red);
	rect03.set_fill_color(Color::red);
	rect04.set_fill_color(Color::red);
	rect05.set_fill_color(Color::red);
	rect06.set_fill_color(Color::red);
	rect07.set_fill_color(Color::red);

	Image i00(Point(400,0),"dog2.jpg");
	Image i01(Point(0,400),"dog2.jpg");
	Image i02(Point(500,200),"dog2.jpg");
	
	

	
	

	

	win.attach(grid);
	win.attach(rect00);
	win.attach(rect01);
	win.attach(rect02);
	win.attach(rect03);
	win.attach(rect04);
	win.attach(rect05);
	win.attach(rect06);
	win.attach(rect07);
	win.attach(i00);
	win.attach(i01);
	win.attach(i02);
	

	bool n = true;

	while(n)
	{
		
		
		while(i_x <= 800)
		{
			Image i04(Point(i_x,i_y),"pic100.jpg");
			win.attach(i04);
			win.wait_for_button();
			i_x += 100;
		}
		
		i_x = 0;
		i_y += 100;		
		if(i_y > 800)
			i_y = 0;

	}	
	


	return 0;
}
