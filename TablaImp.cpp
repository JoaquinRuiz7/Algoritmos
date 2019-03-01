#include "tablaImp.h"

#ifndef TABLAIMP_CPP
#define TABLAIMP_CPP

template <class D, class R>
bool TablaImp<D,R>::existe(const D& d) const {
	return existeAux(d,this->t);
}
template < class D , class R >
bool TablaImp<D, R> ::existeAux(const D&d, nodoABB<D,R> *t) const
{
	if (!t) {
		return false;
	}
	else if (t->d == d) {
		return true;
	}
	else if (d < t->d) {
		return existeAux(d, t->izq);
	}
	else {
		return existeAux(d, t->der);
	}

}
template < class D , class R >
void TablaImp<D, R> ::agregar(const D&d, const R&r) {
	agregar2(d, r, this->t);
}
template <class D, class R >
Tabla<D, R>* TablaImp<D,R>::crearVacia()const {
	return new TablaImp<D,R>();
}
template <class D , class R >
void TablaImp<D, R> ::agregar2(const D&d, const R&r, nodoABB<D,R>* &t) {
	if (t) {
		if (!t) {
			t = new nodoABB();
			t->d = d;
			t->r = r;
			this->cant++;
		}
		else if (d < t->d) {
			agregar2(d, r, t->izq);
		}
		else {
			agregar2(d, r, t->der);
		}
	}
}
template < class D , class R >
bool TablaImp<D,R>::esVacia() const  {
	return this->cant == 0;
}
template < class D , class R >
bool TablaImp<D, R> ::esLLena() const {
	return false;
}
template < class D , class R >
unsigned int TablaImp <D, R> ::largo()const {
	return this->cant;
}
template < class D , class R>
nodoABB<D, R> * TablaImp<D,R>::treeCopy(nodoABB<D, R> * t) const {
	if (!t) {
		return NULL;
	}
	else {
		nodoABB<D, R> * copy = new nodoABB<D,R>();
		copy->dato = d;
		copy->dato2 = r;
		copy->izq = treeCopy(t->izq);
		copy->der = treeCopy(t->der);
		return copy;
	}

}
template <class D , class R >
Tabla<D, R> *TablaImp<D, R> ::clon() const {
	TablaImp<D, R> * clone = new TablaImp<D, R>();
	clone->t = treeCopy(this->t);
	unsigned int largo = this->cant;
	clone->cant = largo;
	return clone;
}




#endif