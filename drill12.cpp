/*The drill is the graphical equivalent to the “Hello, World!” program. Its purpose is to get you acquainted with the simplest graphical output tools. */

#include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>

//------------------------------------------------------

using namespace Graph_lib;

//------------------------------------------------------

int main ()
{
	try 
	{
/*1. Get an empty Simple_window with the size 600 by 400 and a label My window compiled, linked, and run. Note that you have to link the FLTK library as described in Appendix D; #include Graph.h and Simple_window.h in your code; and include Graph.cpp and Window.cpp in your project. */
	Point t1 {100, 100};
	Simple_window win {t1, 600, 400, "My Window"};
	win.wait_for_button();
	
//------------------------------------------------------
	
/* 2. Now add the examples from §12.7 one by one, testing between each added subsection example.*/
	//12.7.3 Axis
	Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"};
	win.attach(xa);
	
	
	Axis ya{Axis::y, Point{20,300}, 280, 10, "y axis"};
	win.attach(ya)
	
	win.set_label("Axis");
	win.wait_for_button();
	
	//12.7.4 Function
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::yellow);
	win.attach(sine);
	win.set_label("Function");
	win.wait_for_button();

	//12.7.5 Polygon
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::dark_green);
	poly.set_fill_color(Color::dark_yellow)
	poly.set_style(Line_style::dot);
	win.attach(poly);
	win.set_label("Polygon");
	win.wait_for_button();

	//12.7.6 Rectangle
	Rectangle r {Point{200,200},100,50};
	r.set_color(Color::dark_green);
	r.set_fill_color(Color::green);
	win.attach(r);
	win.set_label("Shrektangle");
	win.wait_for_button();

	//12.7.8 Text
	Text t {Point{150,150}"Shrek is love, Shrek is life"};
	win.attach(t);
	t.set_font(Font::helvetica_bold_italic);
	t.set_font_size(40);
	win.set_label("We all love Shrek");
	win.wait_for_button();

	//12.7.9 Images
	Image ii {Point{100,50},"shrek.jpg"};
	win.attach(ii);
	win.set_label("Shrekd");
	win.wait_for_button();

	//12.7.10 More
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_green);
	Mark m {Point{100,200},'shrek'};
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.set_label("More");
	win.wait_for_button();

//------------------------------------------------------

/* 3. Go through and make one minor change (e.g., in color, in location, or in number of points) to each of the subsection examples. */

//------------------------------------------------------

	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
    }
catch (...) {
	cerr << "error\n";
	return 1;
	}







