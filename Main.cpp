#include "Tabla.h"
#include"TablaImp.h"
#include "ListaCheta.h"
#include"ListaChetaImp.h"
#include"ListaChetaImp.h"
#include "iostream";
#include"TreeList.h"
#include"TreeListImp.h"
#include"ColaPrioridad.h"
#include"ColaPrioridadImp.h"
#include"Cola.h"
#include"ColaImp.h"
using namespace std;
struct abb {
	int dato;
	abb* izq;
	abb*der;

};
void insertar(abb* &t, int dato) {

	if(!t){
		t = new abb();
		t->dato = dato;
		t->izq = NULL;
		t->der = NULL;
	}
	else if (dato < t->dato) {
		insertar(t->izq, dato);
	}
	else if (dato == t->dato) {
		return;
	}
	else {
		insertar(t->der, dato);
	}
}
void imprimirPorNiveles(abb * t) {
	if (t) {
		Cola<abb*> * cola = new ColaImp<abb*>();
		cola->Encolar(t);
		while (!cola->EsVacia()) {
			int dato = cola->Principio()->dato;
			if (cola->Principio()->izq) {
				cola->Encolar(cola->Principio()->izq);
			}
			if (cola->Principio()->der) {
				cola->Encolar(cola->Principio()->der);
			}
			cout << dato << " ";
			cola->Desencolar();
			
		}

	}

}
struct nodoListaD {
	int dato;
	nodoListaD * sig;
	nodoListaD * ant;
};
void insertarDoble(int d, nodoListaD * & ppio, nodoListaD * & fin) {
	if (!ppio) {
		ppio = new nodoListaD();
		ppio->dato = d;
		ppio->ant = NULL;
		ppio->sig = NULL;
		fin = ppio;
	}
	else {
		nodoListaD * nuevo = new nodoListaD();
		nuevo->dato = d;
		nuevo->sig = NULL;
		nuevo->ant = fin;
		fin->sig = nuevo;
		fin = fin->sig;
	}
}
void borrarPrimero(nodoListaD *& ppio) {
	if (ppio) {
		nodoListaD * borrate = ppio;
		ppio = ppio->sig;
		ppio->ant = NULL;
		delete borrate;
	}
}
void borrarFin(nodoListaD *& fin) {
	if (fin) {
		nodoListaD * borrate = fin;
		fin = fin->ant;
		delete borrate;
		fin->sig = NULL;
	}
}
void mostrarLista(nodoListaD * l) {
	while (l) {
		cout << l->dato << " ";
		l = l->sig;
	}
}

void main() {
	TreeListImp<int> * t = new TreeListImp<int>();
	t->add(8);
	t->add(7);
	t->add(6);
	t->add(5);
	t->add(4);
	t->add(3);
	t->add(2);
	t->add(1);
	
	
	t->print();
	t->Delete(3);
	cout << " despoues de borrar "<< endl;
	t->print();
	system("pause");

}