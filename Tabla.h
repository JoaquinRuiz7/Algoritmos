#pragma once

#ifndef TABLA_H
#define TABLA_H
#include <iostream>
using namespace std;
template < class D, class R >
class Tabla abstract {
public:
	virtual ~Tabla() {}
	virtual Tabla<D, R> *crearVacia() const abstract;
	virtual void agregar(const D& d, const R&r) abstract;
	virtual R& obtener(const D& d) abstract;
	virtual Tabla<D, R> * clon() const abstract ;
	virtual void borrar(const D& d) abstract;
	virtual void vaciar() abstract;
	virtual bool existe(const D& d) const abstract ;
	virtual bool esVacia() const abstract;
	virtual bool esLLena() const abstract;
	virtual int largo() const abstract;
};

#endif