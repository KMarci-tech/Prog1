#include "Lines_window.h"


int main()
{
	using namespace Graph_lib;

	Lines_window win{Point(100,100),800,600,"lines"};
	return gui_main();

}
