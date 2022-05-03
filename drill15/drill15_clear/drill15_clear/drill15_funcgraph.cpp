//g++ drill15_funcgraph.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o funcgraph `fltk-config --ldflags --use-images`

//Function graphing drill:
/* 2. Note that you’ll need to make a project with the properties specified in the “installation of FLTK” note from the course website.*/
//3. You’ll need to move Graph.cpp and Window.cpp into your project.
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

#include <string>
#include <iostream>

//------------------------------------------------------

using namespace Graph_lib;

//------------------------------------------------------

int main ()
{
try
{
//1. Make an empty 600-by-600 Window labeled “Function graphs.”

Point t1{100,100};
Simple_window win{t1, 600, 600, "Function graphs"};

/*4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels” and with a notch every 20 pixels. The axes should cross at (300,300).*/

Axis xa{Axis::x, Point {300,500},400,20,"1 = = 20 pixels"};

Axis ya{Axis::y, Point{100,300},400,20, "1 = = 20 pixels"};


//5. Make both axes red.
xa.set_color(Color::red);
ya.set_color(Color::red);
win.attach(xa);
win.attach(ya);
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//In the following, use a separate Shape for each function to be graphed:

/*1. Graph the function double one(double x) { return 1; } in the range [–10,11] with (0,0) at (300,300) using 400 points and no scaling (in the window).*/
//2. Change it to use x scale 20 and y scale 20.
//3. From now on use that range, scale, etc. for all graphs.

double one   (double x){return 1;}

constexpr int minrange = -10; constexpr int maxrange = 11;
constexpr int xscale = 20; constexpr int yscale = 20;
constexpr int points = 400;

Function onefunct{one, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(onefunct);

//4. Add double slope(double x) { return x/2; } to the window.
//5. Label the slope with a Text "x/2" at a point just above its bottom left end point.
double slope (double x){return x/2;}

Function slopefunct{slope, minrange, maxrange, Point{300,300}, points, xscale, yscale};
Text label{Point{100,385}, "x/2"};
win.attach(slopefunct);
win.attach(label);

//6. Add double square(double x) { return x*x; } to the window.
double square(double x){return x*x;}
Function squarefunct{square, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(squarefunct);

//7. Add a cosine to the window (don’t write a new function).
//8. Make the cosine blue.
Function cosinus{cos, r_min, r_max, Origo, pts, xscale, yscale}; cosinus.set_color(Color::blue);
win.attach(cosinus);

//9. Write a function sloping_cos() that adds a cosine to slope() (as defined above) and add it to the window.
double sloping_cos(double x){return cos(x)+slope(x);}
Function sloping_cosinus{sloping_cos, minrange, maxrange, Point{300,300}, points, xscale, yscale};
win.attach(sloping_cosinus);

win.wait_for_button();

}
catch (exception &e)
    {
        cout << "error: " << e.what() << endl;
        return 1;
    }
    catch (...)
    {
        cout << "unknown error" << endl;
        return 2;
        }
        
}

