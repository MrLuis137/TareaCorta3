#pragma once
#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include <cstdlib>
#include "arbolRN.h"
#include "Logica.h"
#include <ctime>
#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>
#include<FL/Fl_Input.h>
#include<FL/Fl_Button.H>
#include <FL/Fl_Draw.H>


int main()
{
	srand((unsigned)time(NULL));
	//Simple_window win{ tl,600,400,"Canvas" };
	Logica principal;
	Fl_Window window(500, 500, "Window title");
	Line horizontal{ Point{20,10},Point{200,100} };
	Simple_window win1{ Point(44,00),600,400,"two lines" };
	win1.attach(horizontal);
	Circle c1{ Point{100,200},50 };
	c1.set_fill_color(Color::blue);
	win1.attach(c1);
	Fl_Input entrada(50, 400, 40, 20);
	Fl_Button ok(110, 400, 45, 30, "Ok");
	int * perm = principal.genere(40);
	for (int i = 0; i < 40; i++)
	{
		cout << perm[i] << " ";

	}
	//ok.callback(principal.ok_callback, main);

	window.show();
	return Fl::run();
}

