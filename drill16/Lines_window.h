#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window 
{
Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;
	Button next_button; 
	Button quit_button; 
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Menu style_menu;
	Button color_button;
    Button style_button;

    void changec(Color c) { lines.set_color(c); }
    void changes(Line_style s) { lines.set_style(s); }

	void hide_cmenu() { color_menu.hide(); color_button.show(); }
	void hide_smenu() { style_menu.hide(); style_button.show(); }
	void cmenu_pressed() { color_button.hide(); color_menu.show(); }
	void smenu_pressed() { style_button.hide(); style_menu.show(); }

	void red_pressed() { changec(Color::red); hide_cmenu(); }
	void blue_pressed() { changec(Color::blue); hide_cmenu(); }
	void black_pressed() { changec(Color::black); hide_cmenu(); }

	void dot_pressed() { changes(Line_style::dot); hide_smenu(); }
    void dash_pressed() { changes(Line_style::dash); hide_smenu(); }
    void solid_pressed() { changes(Line_style::solid); hide_smenu(); }

	

	void next();
	void quit();
};