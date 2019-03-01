#pragma once
#include<iostream>
#include<assert.h>
template < class J >
class NodoColaPriori {
public :
	J dato;
	unsigned int prioridad;
	NodoColaPriori<J> * sig;

};
