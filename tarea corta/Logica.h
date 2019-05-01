#pragma once
#include <cstdlib>
#include <ctime>
class Logica
{
	int* perm;
	link arbol;
	vector<Circle> cNodos;
	void permutacionAleatoria(int v[], int n);

public:
	Fl_Int_Input* input;
	Fl_Output* output;
	Fl_Window* window;
	Fl_Button* ejecutar;
	Fl_Button* ejecutarP;
	Fl_Button* limpiar;
	Fl_Button* salir;
	Fl_Button* mostrar;
	Simple_window* sw;

	int * Genere(int n);
	int run_object(int argc, char ** argv);
	void set_window(int, int, int, int);
	void dibujar(Fl_Widget * w, void * data);
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
	cout << "\n";
	principal->input->value("");
	principal->sw->hide();
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
	window->color(FL_DARK_BLUE);

	input = new Fl_Int_Input(width + 10, rowmax * height + 30, width, 30, "N° de Nodos");
	input->labelfont(FL_BOLD + FL_ITALIC); input->labelcolor(FL_WHITE);

	ejecutar = new Fl_Button(width * 2 + 20, rowmax * height + 30, width, 30, "Ejecutar"); ejecutar->color(FL_DARK_BLUE); ejecutar->labelcolor(FL_WHITE);
	mostrar = new Fl_Button(width * 3 + 30, rowmax * height + 30, width, 30, "Mostrar"); mostrar->color(FL_DARK_BLUE); mostrar->labelcolor(FL_WHITE);
	salir = new Fl_Button(width * 4 + 40, rowmax * height + 30, width, 30, "Salir"); salir->color(FL_DARK_BLUE); salir->labelcolor(FL_WHITE);

	Fl_Scroll* scroll2 = new Fl_Scroll(20, 10, 340, 10);
	scroll2->type(Fl_Scroll::HORIZONTAL);
	
	sw = new Simple_window(Point(20, 20), colmax * width + 200, rowmax * height, "");
	sw->color(Color::black);
}

void Logica::dibujar(Fl_Widget * w, void * data)
{
	

	
}

int Logica::run_object(int argc, char ** argv)
{
	window->end();
	window->show(argc, argv);
	return Fl::run();
}