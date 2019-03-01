#ifndef nodoABB_H
#define nodoABB_H
#include <iostream>
#include<assert.h>
template <class U,class E>
class nodoABB {
public :
	U dato;
	E dato2;
	nodoABB<U,E> * izq;
	nodoABB <U,E> * der;
	virtual ~nodoABB(){}
private : 
	nodoABB<U,E> &operator=(const nodoABB<U,E> &n) { assert(false); return *this; }
};

#endif 

