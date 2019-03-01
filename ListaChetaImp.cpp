
#include"ListaChetaImp.h"
#include "iostream"
using namespace std;

#ifndef ListaChetaImp_CPP
#define ListaChetaImp_CPP

template <class T>
ListaChetaImp<T>::ListaChetaImp() {
	this->list = NULL;
	this->endOfList = NULL;
	this->lengthh = 0;
}

template < class T >
ListaChetaImp<T> ::~ListaChetaImp() {
	this->empty();
}
template < class T > 
T ListaChetaImp<T> ::lastPositionElement() {
	return this->endOfList->dato;
}
template < class T >
T ListaChetaImp<T> ::firstPositionElement()  {
	return this->list->dato;
}
template <class T>
ListaChetaImp<T>::ListaChetaImp(const ListaCheta<T> &l) {
	this->list = NULL;
	this->endOfList = NULL;
	this->lengthh = 0;
	*this = l;
}

template <class T>
ListaChetaImp<T>::ListaChetaImp(const ListaChetaImp<T> &l) {
	this->list = NULL;
	this->endOfList = NULL;
	this->lengthh = 0;
	*this = l;
}
template <class T>
ListaCheta <T> & ListaChetaImp<T> :: operator=(const ListaCheta<T>&l){
	ListaCheta<T> * copia = l.clone();
	while (!copia->isEmpty) {
		this->add(copia->firstPositionElement());
		copia->Delete(copia->firstPositionElement());
	}
	return *this;
}
template <class T>
ListaCheta<T> & ListaChetaImp<T> ::operator=(const ListaChetaImp<T> &l) {
	ListaCheta<T> * copia = l.clone();
	NodoLista<T>* aux = clone->list;
	while (aux) {
		this->add(aux->dato);
		aux = aux->sig;
	}
	return *this;
}
template < class T >
NodoLista<T> * ListaChetaImp<T> ::createNode(T e) {
	NodoLista<T> * nnew = new NodoLista<T>();
	nnew->dato = e;
	nnew->sig = NULL;
	return nnew;
}
template < class T >
void ListaChetaImp<T> ::add2(const T&e, NodoLista<T> * &l, NodoLista<T> *& end) {
	if (!l) {
		l = createNode(e);
		end = l;
		this->lengthh++;
	}
	else {
		NodoLista<T> * nuevo = createNode(e);
		end->sig = nuevo;
		end = end->sig;
		this->lengthh++;
	}
}
template < class T >
void ListaChetaImp<T>::add(const T&e) {
	add2(e, this->list, this->endOfList);
}
template < class T >
void ListaChetaImp<T> ::deleteBeginning() {
	if (this->list) {
		NodoLista<T> * siguiente = this->list->sig;
		NodoLista<T> * borrate = this->list;
		this->list = siguiente;
		delete borrate;
		this->lengthh--;
	}
}
template <class T>
unsigned int ListaChetaImp<T> ::length() const {
	return this->lengthh;
}
template < class T >
void ListaChetaImp<T> ::Delete(const T&e) {
	NodoLista<T> * anterior = NULL;
	NodoLista<T> * siguiente = NULL;
	NodoLista <T> * aux = this->list;
	while (aux && aux->dato != e) {
		anterior = aux;
		aux = aux->sig;
	}
	if (!anterior) {
		deleteBeginning();
	}
	else {
		NodoLista<T> * borrate = aux;
		siguiente = aux->sig;
		anterior->sig = siguiente;
		delete borrate;
		this->lengthh--;
	}
}
template < class T >
bool ListaChetaImp<T> ::contains(const T&e) const{
	NodoLista<T> * aux = this->list;
	while (aux) {
		if (aux->dato == e) {
			return true;
		}
		aux = aux->sig;
	}
	return false;
}
template < class T >
bool ListaChetaImp<T> ::isEmpty() const{
	return !this->list;
}
template < class T >
void ListaChetaImp<T> :: replace(const T&e , unsigned int position) {
	if (this->list) {
		NodoLista<T> * aux = this->list;
		int count = 1;
		while (aux && count != position) {
			aux = aux->sig;
			count++;
		}
		aux->dato = e;
	}
}
template < class T >
void ListaChetaImp<T> ::deleteInPosition(unsigned int position) {
	if (this->list) {
		unsigned int count = 1;
		NodoLista<T> *aux = this->list;
		NodoLista<T> * anterior = NULL;
		while (aux && count != position) {
			count++;
			anterior = aux;
			aux = aux->sig;
		}
		if (anterior) {
			NodoLista<T> * borrate = aux;
			anterior->sig = aux->sig;
			delete borrate;
			this->lengthh--;
		}
		else {
			deleteBeginning();
		}
	}
}
template < class T >
bool ListaChetaImp<T> ::full() const {
	return false;
}
template < class T> 
void ListaChetaImp<T> ::empty() {
	while (!this->isEmpty()) {
		this->deleteBeginning();
	}
}
template < class T >
ListaCheta<T>* ListaChetaImp<T> ::clone() const {
	NodoLista<T> * aux = this->list;
	ListaCheta<T>* TheClone = new ListaChetaImp<T>();
	while (aux) {
		TheClone->add(aux->dato);
		aux = aux->sig;
	}
	return TheClone;
}
template < class T >
void ListaChetaImp<T> ::print() const{
	NodoLista<T> * aux = this->list;
	while (aux) {
		cout << aux->dato << " ";
		aux = aux->sig;
	}
}

#endif // !ListaChetaImp_H
