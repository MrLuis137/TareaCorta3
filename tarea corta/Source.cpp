#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
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

	int width = 90, height = 80;
	int rowmax = 4, colmax = 7;

	principal.set_window(width, height, rowmax, colmax);

	principal.input = new Fl_Int_Input(width + 10, rowmax * height + 30, width, 30, "N° de Nodos");
	principal.input->labelfont(FL_BOLD + FL_ITALIC); principal.input->labelcolor(FL_WHITE);

	Fl_Button* ejecutar = new Fl_Button(width * 2 + 20, rowmax * height + 30, width, 30, "Ejecutar"); ejecutar->color(FL_DARK_BLUE); ejecutar->labelcolor(FL_WHITE);
	Fl_Button* mostrar = new Fl_Button(width * 3 + 30, rowmax * height + 30, width, 30, "Mostrar"); mostrar->color(FL_DARK_BLUE); mostrar->labelcolor(FL_WHITE);
	Fl_Button* salir = new Fl_Button(width * 4 + 40, rowmax * height + 30, width, 30, "Salir"); salir->color(FL_DARK_BLUE); salir->labelcolor(FL_WHITE);

	Fl_Scroll* scroll2 = new Fl_Scroll(20, 10, 340, 10);
	scroll2->type(Fl_Scroll::HORIZONTAL);

	Circle c1(Point(5, 5), 5);
	c1.set_fill_color(Color::red);
	Circle c2(Point(5, 15), 5);
	c2.set_fill_color(Color::red);
	Circle c3(Point(5, 25), 5);
	c3.set_fill_color(Color::red);
	Circle c4(Point(5, 35), 5);
	c4.set_fill_color(Color::red);
	Lines x1;
	x1.add(Point{ 5,5 }, Point{ 15,5 }); 
	Lines x2;
	x2.add(Point{ 5,5 }, Point{ 15,10 });
	Circle d1(Point(15, 5), 5);
	d1.set_fill_color(Color::red);
	Simple_window sw(Point(20, 20), colmax * width + 200, rowmax * height , "");
	sw.color(Color::black);
	sw.attach(c1);
	sw.attach(c2);
	sw.attach(c3);
	sw.attach(c4);
	
	sw.attach(d1);
	sw.attach(x1);
	sw.attach(x2);

	ejecutar->callback(principal.F_Ejecutar, &principal);
	//ejecutar->callback(principal.dibujar, &principal);
	salir->callback(principal.F_Salir, principal.window);

	principal.run_object(argc, argv);
	return 0;
}
