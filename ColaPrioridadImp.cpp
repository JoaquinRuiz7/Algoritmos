#include "ColaPrioridadImp.h"
#ifndef ColaPrioridadImp_CPP
#define ColaPrioridadImp_CPP

template < class T >
ColaPrioridadImp<T> ::ColaPrioridadImp() {
	this->List = NULL;
	this->primeroEnSalir = NULL;
	this->fin = NULL;
	this->largo = 0;
}
template < class T >
ColaPrioridadImp<T> ::ColaPrioridadImp(const ColaPrioridad<T> & c) {
	this->List = NULL;
	this->primeroEnSalir = NULL;
	this->fin = NULL;
	this->largo = 0;
	*this = c;
}
template < class T >
ColaPrioridadImp<T> ::ColaPrioridadImp(const ColaPrioridadImp<T> & c) {
	this->List = NULL;
	this->primeroEnSalir = NULL;
	this->fin = NULL;
	this->largo = 0;
	*this = c;
}
template < class T >
unsigned int ColaPrioridadImp<T> ::maxPrioridad() const {
	unsigned int max = 0;
	NodoColaPriori<T> * aux = this->List;
	while (aux) {
		if (aux->prioridad > max) {
			max = aux->prioridad;
		}
		aux = aux->sig;
	}
	return max;
}
template < class T >
ColaPrioridadImp<T> & ColaPrioridadImp<T> :: operator=(const ColaPrioridad<T> & c) {
	ColaPrioridad<T> * aux = c.clone();
	while (aux) {
		this->inQue(aux->first(),aux->maxPrioridad());
		aux->unQue();
	}
	return *this;
}
template < class T >
ColaPrioridadImp<T> & ColaPrioridadImp<T> :: operator=(const ColaPrioridadImp<T> & c) {
	ColaPrioridad<T> * aux = c.clone();
	while (aux) {
		this->inQue(aux->first(), aux->maxPrioridad());
		aux->unQue();
	}
	return *this;
}
template < class T >
ColaPrioridadImp<T> * ColaPrioridadImp<T> ::clone() const {
	NodoColaPriori<T> * aux = this->List;
	ColaPrioridadImp<T> * clon = new ColaPrioridadImp<T>();
	while (aux) {
		clon->inQue(aux->dato, aux->prioridad);
		aux = aux->sig;
	}
	unsigned int laargo = this->largo;
	clon->largo = laargo;
	clon->fin = NULL;
	return clon;
}
template < class T >
ColaPrioridadImp<T> ::~ColaPrioridadImp() {
	this->destroy();
}
template < class T >
NodoColaPriori<T> * ColaPrioridadImp<T> ::createNode(const T&e, unsigned int prioridad) {
	NodoColaPriori<T> * nuevo = new NodoColaPriori<T>();
	nuevo->dato = e;
	nuevo->prioridad = prioridad;
	nuevo->sig = NULL;
	return nuevo;
}
template < class T >
void ColaPrioridadImp<T> ::insertarAlPrincipio(NodoColaPriori<T> * &c,NodoColaPriori<T> * &lista) {
	NodoColaPriori<T> * siguiente = this->List;
	c->sig = siguiente;
	lista = c;
}
template < class T >
void ColaPrioridadImp<T> ::inQue(const T&e, unsigned int prioridad) {
	if (!this->List) {
		this->List = createNode(e, prioridad);
		this->primeroEnSalir = this->List;
		this->largo++;
	}
	else {
		if (prioridad > this->primeroEnSalir->prioridad) {
			NodoColaPriori<T> * nuevo = createNode(e, prioridad);
			if (nuevo->prioridad > this->primeroEnSalir->prioridad) {
				this->insertarAlPrincipio(nuevo,this->List);
				this->primeroEnSalir = nuevo;
				this->largo++;
			}
		}
		else {
			NodoColaPriori<T> * nuevo = createNode(e, prioridad);
			this->insertarAlPrincipio(nuevo,this->List);
			this->largo++;
		}
	}
}
template < class T >
T ColaPrioridadImp<T> :: unQue2(unsigned int prioridad) {
	NodoColaPriori<T> * anterior = NULL;
	NodoColaPriori<T> * aux = this->List;
	while (aux && aux->prioridad != prioridad) {
		anterior = aux;
		aux = aux->sig;
		
	}
	if (anterior) {
		anterior->sig = aux->sig;
		NodoColaPriori<T> * borrate = aux;
		T elemento = aux->dato;
		delete borrate;
		this->largo--;
		this->primeroEnSalir = this->maximoPriori(this->List);
		return elemento;
	}
	else {
		NodoColaPriori<T> * borrate = aux;
		this->List = this->List->sig;
		T elemento = aux->dato;
		delete borrate;
		this->largo--;
		this->primeroEnSalir =this->maximoPriori(this->List);
		return elemento;
	}

}
template < class T >
NodoColaPriori<T>* ColaPrioridadImp<T> ::maximoPriori(NodoColaPriori<T> * c) {
	if (!c) {
		return NULL;
	}
	else {
		unsigned int pro = this->maxPrioridad();
		while (c) {
			if (c->prioridad == pro) {
				return c;
			}
			c = c->sig;
		}
		return c;
	}
}
template < class T >
T ColaPrioridadImp<T> ::unQue() {
	unsigned int prioridad = this->maxPrioridad();
	return unQue2(prioridad);

}
template < class T >
bool ColaPrioridadImp<T> ::full() const {
	return false;
}
template < class T >
bool ColaPrioridadImp<T> ::isEmpty() const {
	return !this->List;
}
template < class T >
unsigned int ColaPrioridadImp<T> ::length() const {
	return this->largo;
}
template < class T >
bool ColaPrioridadImp<T> ::contains(const T&e) const {
	NodoColaPriori<T> * aux = this->List;
	while (aux) {
		if (aux->dato == e)
			return true;
		else
			aux = aux->sig;
	}
	return false;
}
template < class T >
void ColaPrioridadImp<T> ::destroy() {
	while (!this->isEmpty()) {
		this->unQue();
	}
}
template < class T>
T ColaPrioridadImp<T> ::first() {
	return this->primeroEnSalir->dato;
}


#endif // !ColaPrioridadImp_CPP


