#pragma once

#ifndef TreeListImp_H
#define TreeListImp_H
#include "TreeList.h"
#include "ABBT.h"
template < class T >
class TreeListImp : public TreeList<T> {
public :
	TreeListImp();
	TreeListImp(const TreeList<T>&t);
	TreeListImp(const TreeListImp<T>&t);
	TreeListImp &operator=(const TreeList<T> & t);
	TreeListImp & operator=(const TreeListImp<T> &t);
	virtual ~TreeListImp();
	void add(const T&e);
	ABBT <T> * createNode(const T & e);
	void add2(const T&e, ABBT<T> *& t);
	void deleteNode(ABBT<T> * &t);
	void Delete(const T&e);
	void Delete2(const T&e, ABBT<T>* & t);
	T  min(ABBT<T> * t);
	T element();
	bool contains(const T&e) const;
	void print() const;
	void print2(ABBT<T>*t) const;
	ABBT<T> * treeCopy(ABBT<T> * t) const;
	bool full() const;
	void empty();
	bool isEmpty() const;
	TreeListImp<T> * clone() const;
	bool contains2(const T&e, ABBT<T> * t) const;
	unsigned int Length() const;

protected:
	ABBT<T> * t;
	unsigned int length;

};
#include "TreeListImp.cpp"
#endif // !TreeListImp_H

