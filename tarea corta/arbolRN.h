#pragma once
#include <queue>
#include <iostream>
#include <string>

using namespace std;

enum color { rojo, negro };

typedef struct node *link;
struct node { // Red-Black Tree
	int v;
	int x;
	int y;
	link izq, der;
	color nColor;

	node(int v) : v{ v }, izq{ nullptr },
		der{ nullptr }, nColor{ rojo } {}
	node(int v, color nColor)
		: v{ v }, izq{ nullptr }, der{ nullptr },
		nColor{ nColor } {}
	node(int v, color nColor, link izq, link der)
		: v{ v }, izq{ izq }, der{ der },
		nColor{ nColor } {}

	string to_string();

	void show(int nivel);

	string scolor() {
		if (this->nColor == rojo)
			return "rojo";
		else
			return "negro";
	}

};

string node::to_string() {
	string sIzq = "";
	string sDer = "";
	if (this->izq)
		sIzq = this->izq->to_string();
	if (this->der)
		sDer = this->der->to_string();
	//return trim(sIzq + " " + std::to_string(this->v) + "<" + this->scolor() + "> " + sDer);
	return sIzq + " " + std::to_string(this->v) + "<" + this->scolor() + "> " + sDer;
}

void node::show(int nivel) {
	for (int i = 0; i < 3 * nivel; i++) cout << " ";

	if (this->izq == nullptr && this->der == nullptr) {
		cout << "[" << this->v << " <" << this->scolor() << ">" << "]";
	}
	else {
		cout << "[" << this->v << " <" << this->scolor() << ">" << endl;
		if (this->izq)
			this->izq->show(nivel + 1);
		else {
			for (int i = 0; i < 3 * (nivel + 1); i++) cout << " ";
			cout << "[ ]";
		}
		cout << "\n";
		if (this->der)
			this->der->show(nivel + 1);
		else {
			for (int i = 0; i < 3 * (nivel + 1); i++) cout << " ";
			cout << "[ ]";
		}
		cout << "\n";
		for (int i = 0; i < 3 * nivel; i++) cout << " ";
		cout << "]";
	}
}

void rotateR(link &h) {
	link p = h->izq;    // (1)
	h->izq = p->der;    // (2)
	p->der = h;         // (3)
	h = p;              // (4)
}

void rotateL(link &h) {
	link p = h->der;    // (1)
	h->der = p->izq;    // (2)
	p->izq = h;         // (3)
	h = p;              // (4)
}

bool esRojo(link x) {
	if (x == nullptr) return false;
	return x->nColor == rojo;
}

void RBinsertR(link& h, int x, int sw) {
	if (h == nullptr) { h = new node(x); return; }
	if (esRojo(h->izq) && esRojo(h->der)) {
		h->nColor = rojo;
		h->izq->nColor = negro;
		h->der->nColor = negro;
	}
	if (x < h->v) {
		RBinsertR(h->izq, x, 0);
		if (esRojo(h) && esRojo(h->izq) && sw)
			rotateR(h);
		if (esRojo(h->izq) && esRojo(h->izq->izq)) {
			rotateR(h);
			h->nColor = negro;
			h->der->nColor = rojo;
		}
	}
	else {
		RBinsertR(h->der, x, 1);
		if (esRojo(h) && esRojo(h->der) && !sw)
			rotateL(h);
		if (esRojo(h->der) && esRojo(h->der->der)) {
			rotateL(h);
			h->nColor = negro;
			h->izq->nColor = rojo;
		}
	}
}

void RBinsert(link& h, int x) {
	RBinsertR(h, x, 0);
	h->nColor = negro;
}

int contarAux(link &ab, int contador) {
	if (ab == NULL) { return contador; };
	if (ab->izq != 0) {
		contador = contarAux(ab->izq, contador);
	}
	ab->x = contador;
	contador++;
	if (ab->der != 0) {
		contador = contarAux(ab->der, contador);
	}
	return contador;
}

void columnas(link &ab) {
	contarAux(ab, 0);
}

void filas(link & ar) {
	link ab = ar;
	queue<link> q;
	int ciclos = 1;
	int cicloActual = 0;
	int hijos = 0;
	int nivel = 0;
	q.push(ab);
	while (!q.empty()) {
		if (cicloActual >= ciclos) {
			ciclos = 0;
			cicloActual = 0;
			ciclos = hijos;
			hijos = 0;
			nivel++;
		}
		ab = q.front();
		q.pop();
		ab->y = nivel;
		if (ab->izq != 0) {
			q.push(ab->izq);
			hijos++;
		}
		if (ab->der != 0) {
			q.push(ab->der);
			hijos++;
		}
		cicloActual++;
	}
}