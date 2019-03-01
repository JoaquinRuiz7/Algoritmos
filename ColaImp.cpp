#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<<(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp() {
	this->largo = 0;
	this->ppio = NULL;
	this->fin = NULL;
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c) {
	this->largo = 0;
	this->ppio = NULL;
	this->fin = NULL;
	*this = c;
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c) {
	this->largo = 0;
	this->ppio = NULL;
	this->fin = NULL;
	*this = c;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c) {
	Cola<T> * copia = c.Clon();
	while (copia->EsLlena()) {
		this->Encolar(copia->Desencolar());
	}
	delete copia;
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c) {
	ColaImp<T> * nueva = c.Clon();
	nodoCola<T> * aux = nueva->ppio;
	while (aux) {
		this->Encolar(aux->dato);
		aux = aux->sig;
	}
	delete nueva;
	return *this;

}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const {
	Cola<T> * copia = c.Clon();
	nodoCola<T> * aux = this->ppio;
	while (copia->EsLlena()) {
		if (aux->dato != copia->Desencolar()) {
			return false;
		}
		aux = aux->sig;
	}
	return true;
}

template <class T>
ColaImp<T>::~ColaImp() {
	this->Vaciar();
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e) {
	nodoCola<T> * nuevo = new nodoCola<T>();
	nuevo->dato = e;
	nuevo->sig = NULL;
	if (this->EsVacia()) {
		this->ppio = nuevo; // si es vacia el principio y fin son iguales a nuevo.
		this->fin = nuevo;
	}
	else {
		this->fin->sig = nuevo; // sino fin -> sig = nuevo; 
		this->fin = this->fin->sig; // fin se actualiza a su siguiente.
	}
	this->largo++;
}

template <class T>
T& ColaImp<T>::Principio()const {
	return this->ppio->dato;
}

template <class T>
T ColaImp<T>::Desencolar() {
	nodoCola<T> * borrate = this->ppio;
	T primero = this->Principio();
	nodoCola<T> * siguiente = this->ppio->sig;
	this->ppio = siguiente;
	this->largo--;
	delete borrate;
	return primero;
}

template <class T>
void ColaImp<T>::Vaciar() {
	while (this->EsLlena()) {
		this->Desencolar();
	}
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const {
	return this->largo;
}

template <class T>
bool ColaImp<T>::EsVacia() const {
	if (!this->ppio)
		return true;
	else
		return false;
}

template <class T>
bool ColaImp<T>::EsLlena() const {
	if (this->ppio)
		return true;
	else
		return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const {
	ColaImp<T> * clon = new ColaImp<T>;
	nodoCola<T> * aux = this->ppio;
	while (aux) {
		clon->Encolar(aux->dato);
		aux = aux->sig;
	}
	return clon;
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const {
	nodoCola<T> * aux = this->ppio;
	while (aux) {
		if (!aux->sig) {
			o << aux->dato;
		}
		else {
			o << aux->dato << " ";
		}
		aux = aux->sig;
	}


}

#endif