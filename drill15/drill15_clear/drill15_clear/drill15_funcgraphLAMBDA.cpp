//g++ drill15_funcgraph.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o funcgraph `fltk-config --ldflags --use-images`

//Function graphing drill:
/* 2. Note that you’ll need to make a project with the properties specified in the “installation of FLTK” note from the course website.*/
//3. You’ll need to move Graph.cpp and Window.cpp into your project.

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"
#include <functional>

constexpr int rangeMin = -10;
constexpr int rangeMax = 11;
Point origin{300, 300};
constexpr int resolution = 400;
constexpr double scale = 20;

int main()
{
    try
    {
    
//1. Make an empty 600-by-600 Window labeled “Function graphs.”
        Simple_window win{Point{200, 400}, 600, 600, "Function graphs"};

/*4. Add an x axis and a y axis each of length 400, labeled “1 = = 20 pixels” and with a notch every 20 pixels. The axes should cross at (300,300).*/
        Axis xa{Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
        Axis ya{Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
//5. Make both axes red.
        xa.set_color(Color::red);
        ya.set_color(Color::red);
        
        win.attach(xa);
        win.attach(ya);
//In the following, use a separate Shape for each function to be graphed:

/*1. Graph the function double one(double x) { return 1; } in the range [–10,11] with (0,0) at (300,300) using 400 points and no scaling (in the window).*/
//2. Change it to use x scale 20 and y scale 20.
//3. From now on use that range, scale, etc. for all graphs.

        auto one = [](double x) -> double
        {
            return 1;
        };
        Function fone{one, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(fone);

//4. Add double slope(double x) { return x/2; } to the window.
//5. Label the slope with a Text "x/2" at a point just above its bottom left end point.

        auto slope = [](double x)
        {
            return x / 2;
        };
        Function fslope{slope, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(fslope);
       
//6. Add double square(double x) { return x*x; } to the window.

        auto square = [](double x)
        {
            return x * x;
        };
        Function fsquare{square, rangeMin, rangeMax, origin, resolution, scale, scale};
        win.attach(fsquare);
        
//7. Add a cosine to the window (don’t write a new function).
//8. Make the cosine blue.

        auto sloping_cos = [](double x)
        {
            return cos(x) + x / 2;
        };
        Function fcos{cos, rangeMin, rangeMax, origin, resolution, scale, scale};
        fcos.set_color(Color::blue);
        win.attach(fcos);
	
//9. Write a function sloping_cos() that adds a cosine to slope() (as defined above) and add it to the window.
	
	Function fslos(sloping_cos, rangeMin, rangeMax, origin, resolution, scale, scale);
 	win.attach(flos);

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
