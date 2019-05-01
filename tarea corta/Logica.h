#pragma once
//#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
#include <cstdlib>
#include "arbolRN.h"
#include <ctime>
#include<FL/Fl.h>
#include<FL/Fl_Box.h>
#include<FL/Fl_Window.h>
#include<FL/Fl_Input.h>
#include<FL/Fl_Button.H>
#include <FL/Fl_Draw.H>

using namespace std;
class Logica {

	int* perm;
	link arbol;

	void permutacionAleatoria(int v[], int n)
	{
		int i, k, temp;

		for (i = 0; i < n; i++)
		{
			k = rand() % n;
			temp = v[i];
			v[i] = v[k];
			v[k] = temp;
		}
	}
public:
	int * genere(int n) {
		int * pt = new int[n];
		for (int i = 0; i < n; i++) {
			pt[i] = i;
		}
		permutacionAleatoria(pt, n);
		return pt;
	}

	Logica() {}
	void ok_callback(Fl_Widget *widget, void *w)
	{
		perm = genere(40);
		for (int i = 0; i < 40; i++)
		{
			cout << perm[i] << " ";

		}
	}
	~Logica() {}

};

