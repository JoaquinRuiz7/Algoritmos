#pragma once
#include "ColaPrioridad.h"
#include "NodoColaPriori.h"

#ifndef ColaPrioridadImp_H
#define ColaPrioridadImp_H
#include "ColaPrioridad.h"
template < class T >
class ColaPrioridadImp : ColaPrioridad<T> {
public :
	ColaPrioridadImp & operator= (const ColaPrioridad<T> & c);
	ColaPrioridadImp & operator= (const ColaPrioridadImp<T> & c);
	ColaPrioridadImp();
	ColaPrioridadImp<T> * clone() const;
	ColaPrioridadImp(const ColaPrioridad<T> & c);
	ColaPrioridadImp(const ColaPrioridadImp<T> & c);
	virtual ~ColaPrioridadImp();
	void inQue(const T&e, unsigned int prioridad);
	T unQue();
	T unQue2(unsigned int prioridad);
	void destroy();
	bool full() const;
	unsigned int maxPrioridad() const;
	unsigned int length()const;
	NodoColaPriori<T> * maximoPriori(NodoColaPriori<T> * cola);
	bool isEmpty() const;
	bool contains(const T&e) const;
		
	
	void insertarAlPrincipio(NodoColaPriori<T> *& c,NodoColaPriori<T> *& list);
	NodoColaPriori<T> * createNode(const T&e, unsigned int prioridad);
	T first();
protected:
	unsigned int largo;
	NodoColaPriori <T> * List;
	NodoColaPriori<T> * primeroEnSalir;
	NodoColaPriori<T> * fin;
};
#include "ColaPrioridadImp.cpp"
#endif // !ColaPrioridadImp_H

