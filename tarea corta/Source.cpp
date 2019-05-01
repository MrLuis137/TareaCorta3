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
	c.set_fill_color(Color::red);
	Simple_window sw(Point(10,10), 400, 300, "");
	sw.attach(c);
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