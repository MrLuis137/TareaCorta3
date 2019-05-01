#pragma once
#include <cstdlib>
#include <ctime>
#include "Simple_window.h"
class Logica
{
	
	int* perm;
	link arbol;
	void permutacionAleatoria(int v[], int n);
	
public:
	Fl_Int_Input* input;
	Fl_Output* output;
	Fl_Window* window;
	Fl_Button* ejecutar;
	Fl_Button* ejecutarP;
	Fl_Button* limpiar;
	Fl_Button* salir;
	Fl_Button* prueba;
	vector<int> x;
	vector<int> y;

	int * Genere(int n);
	int run_object(int argc, char ** argv);
	void dibujarCirculo(Point posicion);
	void dibujar();
	void dibujarHder(link ab, Point padre);
	void dibujarHizq(link ab, Point padre);
	void set_window(int, int, int, int);
	static void F_Ejecutar(Fl_Widget * w, void * data);
	static void F_Salir(Fl_Widget * w, void * data);

	char sval[40];
	int  ival;
	Logica() {}
	~Logica() {}
};

void Logica::permutacionAleatoria(int v[], int n)
{
	int i, k, temp;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		k = rand() % n;
		temp = v[i];
		v[i] = v[k];
		v[k] = temp;
	}
}

int * Logica::Genere(int n)
{
	int * pt = new int[n];
	for (int i = 0; i < n; i++) {
		pt[i] = i;
	}
	permutacionAleatoria(pt, n);
	return pt;
}

void Logica::F_Ejecutar(Fl_Widget * w, void * data)
{
	Logica *principal = reinterpret_cast<Logica*>(data);
	principal->ival = atoi(principal->input->value());
	printf("Integer value is %d\n", principal->ival);
	//principal->output->value(principal->sval);
	principal->perm = principal->Genere(principal->ival);
	int *permutacion = principal->perm;
	for (int i = 0; i < principal->ival; i++)
	{
		RBinsert(principal->arbol, permutacion[i]);
		cout << permutacion[i] << " ";
	}
	cout << "\n";
	columnas(principal->arbol);
	cout << "\n";
	filas(principal->arbol);
	cout << "\n";
	principal->arbol->show(10);
	principal->input->value("");
}

void Logica::F_Salir(Fl_Widget * w, void * data)
{
	Fl_Window *window = (Fl_Window *)data;
	window->hide();
	exit(0);
}

void Logica::set_window(int width, int height, int rowmax, int colmax)
{
	window = new Fl_Window(colmax * width + 20, rowmax * height + 240);
	window->color(FL_DARK_GREEN);
}

int Logica::run_object(int argc, char ** argv)
{
	window->end();
	window->show(argc, argv);
	return Fl::run();
}

void Logica::dibujarCirculo(Point posicion) {
	Circle c(posicion, 10);
	c.set_fill_color(Color::red);
}

void Logica::dibujar() {
	int posX = x.at(arbol->x);
	int posY = x.at(arbol->y);
	Point padre(posX,posY);
	dibujarCirculo(padre);
	

}
void Logica::dibujarHder(link ab, Point padre) {

}

void Logica::dibujarHizq(link ab, Point padre) {

}