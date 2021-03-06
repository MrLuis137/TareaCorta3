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
#include "Logica.h"

using namespace Graph_lib;

int main(int argc, char ** argv)
{
	Logica principal;

	int width = 90, height = 80;
	int rowmax = 4, colmax = 7;

	principal.set_window(width, height, rowmax, colmax);
	int columnas = 10;
	for (int i = 0; i < 1991; i++) {
		principal.x.push_back(columnas);
		columnas += 10;
	}
	int filas = 15;
	for (int i = 0; i < 10; i++) {
		principal.y.push_back(filas);
		filas += 15;
	}
	principal.ejecutar->callback(principal.F_Ejecutar, &principal);
	principal.salir->callback(principal.F_Salir, principal.window);

	principal.run_object(argc, argv);
	return 0;
}
