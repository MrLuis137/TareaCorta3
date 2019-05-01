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
#include "Logica.h"

int main(int argc, char ** argv)
{
	Logica principal;

	int width = 90, height = 80;
	int rowmax = 4, colmax = 7;

	principal.set_window(width, height, rowmax, colmax);

	principal.input = new Fl_Int_Input(140, rowmax * height + 20, colmax * width - 160, 20, "N° de Nodos");
	principal.input->labelfont(FL_BOLD + FL_ITALIC);

	Fl_Button* ejecutar = new Fl_Button(10, 410, 150, 30, "Ejecutar"); ejecutar->color(FL_DARK_BLUE); ejecutar->labelcolor(FL_WHITE);
	Fl_Button* salir = new Fl_Button(490, 410, 150, 30, "Salir"); salir->color(FL_DARK_BLUE); salir->labelcolor(FL_WHITE);

	ejecutar->callback(principal.F_Ejecutar, &principal);
	salir->callback(principal.F_Salir, principal.window);

	principal.run_object(argc, argv);
	return 0;
}