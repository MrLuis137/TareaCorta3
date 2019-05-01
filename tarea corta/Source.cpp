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

#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "arbolRN.h"
#include "Logica.h"

using namespace Graph_lib;

int main(int argc, char ** argv)
{
	Logica principal;

	int width = 90, height = 80;
	int rowmax = 4, colmax = 7;

	principal.set_window(width, height, rowmax, colmax);

	principal.input = new Fl_Int_Input(width + 10, rowmax * height + 20, width, 30, "N° de Nodos");
	principal.input->labelfont(FL_BOLD + FL_ITALIC); principal.input->labelcolor(FL_WHITE);

	Fl_Button* ejecutar = new Fl_Button(width * 2 + 20, rowmax * height + 20, width, 30, "Ejecutar"); ejecutar->color(FL_DARK_BLUE); ejecutar->labelcolor(FL_WHITE);
	Fl_Button* salir = new Fl_Button(width * 3 + 30, rowmax * height + 20, width, 30, "Salir"); salir->color(FL_DARK_BLUE); salir->labelcolor(FL_WHITE);

	Circle c(Point(200, 200), 10);
	c.set_fill_color(Color::red);
	Lines x;
	x.add(Point{ 100,100 }, Point{ 200,100 });
	x.set_fill_color(Color::red);

	Simple_window sw(Point(10, 10), colmax * width, rowmax * height, "");
	sw.attach(c);
	sw.attach(x);

	ejecutar->callback(principal.F_Ejecutar, &principal);
	salir->callback(principal.F_Salir, principal.window);

	principal.run_object(argc, argv);
	return 0;
}