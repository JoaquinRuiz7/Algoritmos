#ifndef TABLAIMP_H
#define TABLAIMP_H


#include "Tabla.h"
#include "nodoABB.h"

template <class D ,class R>
class TablaImp : public Tabla <D, R> {
public : 
	virtual ~TablaImp();
	 void agregar(const D& d, const R&r);
	 R& obtener(const D& d);
	 Tabla<D, R> * clon()  const;
	 void borrar(const D& d);
	 void vaciar() ;
	 bool existe(const D& d) const;
	 bool esVacia() const;
	 bool esLLena() const;
	 Tabla <D, R> * crearVacia() const;
	unsigned int largo() const;
protected:
	
	nodoABB<D, R> *t;
	unsigned int cant;
	bool existeAux(const D& d, nodoABB<D,R>*t) const;
	void agregar2(const D&d, const R&r, nodoABB<D,R>* &t);
	nodoABB<D, R> * treeCopy(nodoABB<D,R>*t)const;
	
};


#include "TablaImp.cpp"

#endif
