#pragma once
#ifndef NodoLista_H
#define NodoLista_H
#include <iostream>
#include<assert.h>
template < class J >
class NodoLista {
public :
	J dato;
	NodoLista<J> * sig;
private :
	NodoLista<J> &operator=(const NodoLista<J> & n) { assert (false); return *this; }

};
#endif // !NodoLista_H

