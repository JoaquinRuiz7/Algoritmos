#ifndef ListaChetaImp_H
#define ListaChetaImp_H
#include "ListaCheta.h"
#include "NodoLista.h"


template < class T > 
class ListaChetaImp : public ListaCheta<T>{
public : 
	virtual ~ListaChetaImp();
	ListaChetaImp();
	ListaChetaImp(const ListaCheta<T> &l);
	ListaCheta<T> &operator=(const ListaCheta<T>&l);
	ListaCheta<T> &operator=(const ListaChetaImp<T>&l);
	ListaChetaImp(const ListaChetaImp<T> &l);
	void add(const T&e);
	void Delete(const T&e);
	bool contains(const T&e) const;
	bool isEmpty() const;
	bool full() const;
	void empty();
	void replace(const T&e , unsigned int position);
	void deleteInPosition(unsigned int position);
	T firstPositionElement();
	T lastPositionElement();
	ListaCheta<T> * clone()const;
	unsigned int length() const;
	void print() const;
protected:
	unsigned int lengthh;
	NodoLista<T> * list;
	NodoLista<T> * endOfList;
	NodoLista<T> * createNode(T e);
	void add2(const T&e, NodoLista<T> * &l , NodoLista<T> * &end);
	void deleteBeginning();

};
#include "ListaChetaImp.cpp"
#endif // !ListaChetaImp_H

