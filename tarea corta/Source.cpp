#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>

#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "arbolRN.h"
#include "Lineas.h"
#include "Logica.h"

using namespace Graph_lib;

int main(int argc, char ** argv)
{
	Logica principal;

	Vector<Circle> s;

	int width = 90, height = 80;
	int rowmax = 4, colmax = 7;

	principal.set_window(width, height, rowmax, colmax);

	principal.input = new Fl_Int_Input(140, rowmax * height + 20, colmax * width - 160, 20, "N° de Nodos");
	principal.input->labelfont(FL_BOLD + FL_ITALIC);

	DLineas draw(10, 10, 70, 70);
	Circle c(Point(200, 200), 50);
	double x = 20, y = 20, r = 30;
	void fl_circle(double x, double y, double r);
	
	for (int i = 1; i < 10; i++) {
		int x = 10 * i, y = 10 * i;
		int w = 70 * i, h = 70 * i;
		//int r = 30;
		void fl_push_clip(int x, int y, int w, int h);
		//s.push_back(new Circle(Point(x, y), 20));
		//attach(s.back);
		cout << "Prueba" << endl;
	}	

	Fl_Button* ejecutar = new Fl_Button(10, 410, 150, 30, "Ejecutar"); ejecutar->color(FL_DARK_BLUE); ejecutar->labelcolor(FL_WHITE);
	Fl_Button* salir = new Fl_Button(490, 410, 150, 30, "Salir"); salir->color(FL_DARK_BLUE); salir->labelcolor(FL_WHITE);
	
	ejecutar->callback(principal.F_Ejecutar, &principal);
	salir->callback(principal.F_Salir, principal.window);

	principal.run_object(argc, argv);
	return 0;
}
/*
//  Philipp Siedler
//  Bjarne Stroustrup's PP
//  Chapter 16 Exercise 4

#define _USE_MATH_DEFINES
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include "GUI.h"

// layout
constexpr int xmax = 600;
constexpr int ymax = 400;

// QUAD
struct Quad_center : Closed_polyline
{
	Quad_center(Point center, int w, int h)
	{
		add(Point(center.x - w / 2, center.y - h / 2));
		add(Point(center.x + w / 2, center.y - h / 2));
		add(Point(center.x + w / 2, center.y + h / 2));
		add(Point(center.x - w / 2, center.y + h / 2));

	}

	void draw_lines() const;
};

void Quad_center::draw_lines() const
{
	fl_color(FL_BLACK);
	Closed_polyline::draw_lines();
}

// TRIANGLE
struct Triangle : Closed_polyline
{
	Triangle(Point origin, int edge_length)
	{
		int h = sqrt(3) / 2 * edge_length;

		Point p(origin.x - edge_length / 2, origin.y + edge_length / 2);
		add(p);
		add(Point(p.x + edge_length, p.y));
		add(Point(p.x + edge_length / 2, p.y - h));
	}

	void draw_lines() const;
};

void Triangle::draw_lines() const
{
	fl_color(FL_BLACK);
	Closed_polyline::draw_lines();
}

// HEXAGON
struct Hexagon : Closed_polyline
{
	Hexagon(Point origin, int radius)
	{
		int n = 6;
		for (int i = 0; i < n; i++) {
			add(Point(origin.x + radius * cos(2 * M_PI * i / n), origin.y + radius * sin(2 * M_PI * i / n)));
		}
	}

	void draw_lines() const;
};

void Hexagon::draw_lines() const
{
	fl_color(FL_BLACK);
	Closed_polyline::draw_lines();
}

// DRAW SHAPES WINDOW
struct Shapes_window : Window {
	Shapes_window(Point xy, int w, int h, const string& title);
private:
	// data
	enum Shapes
	{
		circle, square, triangle, hexagon
	};

	Vector_ref<Shape> s;

	// widgets
	Button quit_button; // end program
	In_box draw_pos_x;
	In_box draw_pos_y;
	Out_box xy_out;
	Menu shape_menu;
	Button menu_button;

	void hide_menu() { shape_menu.hide(); menu_button.show(); }

	// actions invoked by callbacks
	void menu_pressed() { menu_button.hide(); shape_menu.show(); }
	void draw_shape(Shapes s);
	void quit();

	// callback functions
	static void cb_circle(Address, Address);
	static void cb_square(Address, Address);
	static void cb_triangle(Address, Address);
	static void cb_hexagon(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_quit(Address, Address);
};

Shapes_window::Shapes_window(Point xy, int w, int h, const string& title)
	:Window(xy, w, h, title),
	quit_button(Point(x_max() - 70, 0), 70, 20, "Quit", cb_quit),
	draw_pos_x(Point(x_max() - 310, 0), 50, 20, "pos x:"),
	draw_pos_y(Point(x_max() - 210, 0), 50, 20, "pos y:"),
	xy_out(Point(100, 0), 100, 20, "drawn at (x,y):"),
	shape_menu(Point(x_max() - 70, 30), 70, 20, Menu::vertical, "shape"),
	menu_button(Point(x_max() - 80, 30), 80, 20, "shape menu", cb_menu)
{
	attach(quit_button);
	attach(draw_pos_x);
	attach(draw_pos_y);
	attach(xy_out);

	xy_out.put("no shape");

	shape_menu.attach(new Button(Point(0, 0), 0, 0, "circle", cb_circle));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "square", cb_square));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "triangle", cb_triangle));
	shape_menu.attach(new Button(Point(0, 0), 0, 0, "hexagon", cb_hexagon));

	attach(shape_menu);
	shape_menu.hide();
	attach(menu_button);
}

void Shapes_window::draw_shape(Shapes shape)
{

	if (draw_pos_x.get_int() == -999999)
	{
		xy_out.put("enter position");
	}
	else {

		int x = draw_pos_x.get_int();
		int y = draw_pos_y.get_int();

		switch (shape)
		{
		case circle: { s.push_back(new Circle(Point(x, y), 20)); break; }
		case square: { s.push_back(new Quad_center(Point(x, y), 40, 40)); break; }
		case triangle: { s.push_back(new Triangle(Point(x, y), 40)); break; }
		case hexagon: { s.push_back(new Hexagon(Point(x, y), 20)); break; }
		}

		// update current position readout
		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());

		attach(s[s.size() - 1]);
		redraw();
		hide_menu();
	}
}

void Shapes_window::quit()
{
	hide();
}

void Shapes_window::cb_circle(Address, Address pw)
{
	reference_to<Shapes_window>(pw).draw_shape(circle);
}

void Shapes_window::cb_square(Address, Address pw)
{
	reference_to<Shapes_window>(pw).draw_shape(square);
}

void Shapes_window::cb_triangle(Address, Address pw)
{
	reference_to<Shapes_window>(pw).draw_shape(triangle);
}

void Shapes_window::cb_hexagon(Address, Address pw)
{
	reference_to<Shapes_window>(pw).draw_shape(hexagon);
}

void Shapes_window::cb_menu(Address, Address pw)
{
	reference_to<Shapes_window>(pw).menu_pressed();
}

void Shapes_window::cb_quit(Address, Address pw)
{
	reference_to<Shapes_window>(pw).quit();
}

int main()
try
{
	Shapes_window win(Point(100, 100), xmax, ymax, "lines");
	return gui_main();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}

catch (...) {
	cerr << "Unknown exception!\n";
	keep_window_open();
	return 2;
}
*/