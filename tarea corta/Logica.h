#pragma once
#include <cstdlib>
#include <FL/Fl_Widget.H>
#include <ctime>
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
	Simple_window* sw;
	vector<int> x;
	vector<int> y;

	int * Genere(int n);
	int run_object(int argc, char ** argv);
	void dibujarCirculo(Point posicion, string color);
	void dibujarLinea(Point posicion, Point color);
	void dibujar();
	void dibujarAux(link ab, Point padre);
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
	if (principal->ival <= 200 && principal->ival >= 1) {
		printf("Integer value is %d\n", principal->ival);
		principal->perm = principal->Genere(principal->ival);
		int *permutacion = principal->perm;
		for (int i = 0; i < principal->ival; i++)
		{
			RBinsert(principal->arbol, permutacion[i]);
			cout << permutacion[i] << " ";
		}
		columnas(principal->arbol);
		filas(principal->arbol);
		principal->dibujar();
		principal->ejecutar->hide();
		principal->input->hide();
	}
	else {
		cout << "No es un numero valido" << endl;
		principal->input->value("");
	}
}

void Logica::F_Salir(Fl_Widget * w, void * data)
{
	Fl_Window *window = (Fl_Window *)data;
	window->hide();
	exit(0);
}

void Logica::set_window(int width, int height, int rowmax, int colmax)
{
	window = new Fl_Window(colmax * width + 20, rowmax * height + 80);
	window->color(fl_rgb_color(210, 10, 10));

	input = new Fl_Int_Input(width + 10, rowmax * height + 30, width, 30, "N° de Nodos");
	input->labelfont(FL_BOLD + FL_ITALIC); input->labelcolor(FL_WHITE);

	ejecutar = new Fl_Button(width * 2 + 20, rowmax * height + 30, width, 30, "Ejecutar"); ejecutar->color(fl_rgb_color(64, 94, 138)); ejecutar->labelcolor(FL_WHITE);
	salir = new Fl_Button(colmax * width - 80, rowmax * height + 30, width, 30, "Salir"); salir->color(fl_rgb_color(64, 94, 138)); salir->labelcolor(FL_WHITE);

	Fl_Scroll* scroll2 = new Fl_Scroll(20, 10, colmax * width, 10);
	scroll2->type(Fl_Scroll::HORIZONTAL);

	sw = new Simple_window(Point(20, 20), colmax * width + 1600, rowmax * height, "");
	sw->color(Color::white);
}

int Logica::run_object(int argc, char ** argv)
{
	window->end();
	window->show(argc, argv);
	return Fl::run();
}

void Logica::dibujarCirculo(Point posicion, string color) {
	Circle *c = new Circle(posicion, 5);
	if (color == "rojo") {
		c->set_fill_color(Color::red);
	}
	else {
		c->set_fill_color(Color::black);
	}
	sw->attach(*c);
	sw->redraw();
}

void Logica::dibujarLinea(Point posicion1, Point posicion2) {
	Line *l = new Line(posicion1, posicion2);
	l->set_color(Color::black);
	sw->attach(*l);
	sw->redraw();
}

void Logica::dibujar() {
	int posX = x.at(arbol->x);
	int posY = x.at(arbol->y);
	Point padre(posX,posY);
	dibujarCirculo(padre, arbol->scolor());
	if (arbol->der != NULL) {
		dibujarAux(arbol->der, padre);
	}
	if (arbol->izq != NULL) {
		dibujarAux(arbol->izq, padre);
	}
}

void Logica::dibujarAux(link ab, Point padre) {
	int posX = x.at(ab->x);
	int posY = x.at(ab->y);
	Point nodo(posX, posY);
	dibujarLinea(padre, nodo);
	dibujarCirculo(nodo, ab->scolor());
	if (ab->der != NULL) {
		dibujarAux(ab->der, nodo);
	}
	if (ab->izq != NULL) {
		dibujarAux(ab->izq, nodo);
	}
}