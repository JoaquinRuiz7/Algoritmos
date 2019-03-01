#include "TreeListImp.h"
#include "iostream"
using namespace std;


#ifndef TreeListImp_CPP
#define TreeListImp_CPP


template < class T >
TreeListImp<T> ::TreeListImp() {
	this->t = NULL;
	this->length = 0;
}
template < class T>
TreeListImp<T> ::TreeListImp(const TreeList & t) {
	this->t = NULL;
	this->length = 0;
	*this = t;
}
template < class T>
TreeListImp<T> ::TreeListImp(const TreeListImp & t) {
	this->t = NULL;
	this->length = 0;
	*this = t;
}
template < class T >
TreeListImp<T> & TreeListImp<T> ::operator=(const TreeListImp<T> & t) {
	TreeListImp<T> * aux = t.clone();
	while (!aux->isEmpty()) {
		this->add(aux->element());
		aux->Delete(aux->element());
	}
		return *this;
}
template < class T >
TreeListImp<T> & TreeListImp<T> ::operator=(const TreeList<T> & t) {
	TreeListImp<T> * aux = t.clone();
	while (aux->isEmpty()) {
		this->add(aux->element());
		aux->Delete(aux->element());
	}
	return *this;
}
template < class T >
ABBT<T>*TreeListImp<T>::createNode(const T&e) {
	ABBT<T> * nuevo = new ABBT<T>();
	nuevo->dato = e;
	nuevo->left = NULL;
	nuevo->rigth = NULL;
	return nuevo;
}
template < class T >
void TreeListImp<T>::add2(const T&e, ABBT<T> * &t) {
	if (!t) {
		t = createNode(e);
		this->length++;
	}
	else {
		if (e < t->dato) {
			add2(e, t->left);
		}
		else if (e > t->dato) {
			add2(e, t->rigth);
		}
		else {
			return;
		}
	}
}
template < class T >
void TreeListImp<T>::add(const T&e) {
	add2(e, this->t);
}
template < class T >
T TreeListImp<T>::min(ABBT<T> * t) {
	while (t->left) {
		t = t->left;
	}
	return t->dato;
}
template < class T >
void TreeListImp<T>::deleteNode(ABBT<T> * &t) {
	delete t;
	t = NULL;
	this->length--;
}
template < class T >
TreeListImp<T> :: ~TreeListImp() {
	this->empty();
}
template < class T >
void TreeListImp<T>::Delete2(const T&e, ABBT<T> * & t) {
	if (t) {
		if (t->dato == e){
			if (t->left && !t->rigth) {
				ABBT<T> * borrate = t;
				t = t->left;
				delete borrate;
				borrate = NULL;
				this->length--;
			}
			else if (t->rigth && !t->left) {
				ABBT<T> * borrate = t;
				t = t->rigth;
				delete borrate;
				borrate = NULL;
				this->length--;
			}
			else if(t->rigth && t->left){
				T minn = min(t->rigth);
				t->dato = minn;
				Delete2(minn, t->rigth);
			}
			else {
				deleteNode(t);
			}
		}
		else if (e < t->dato) {
			Delete2(e, t->left);
		}
		else {
			Delete2(e, t->rigth);
		}
	}
}
template < class T >
void TreeListImp<T>::Delete(const T&e) {
	Delete2(e, this->t);
}
template < class T >
bool TreeListImp<T>::contains2(const T&e, ABBT<T> * t) const {
	if (!t) {
		return false;
	}
	else if (t->dato == e) {
		return true;
	}
	else if (e < t->dato) {
		return contains2(e,t->left);
	}
	else {
		return contains2(e,t->rigth);
	}
}
template < class T >
bool TreeListImp<T>::contains(const T&e) const {
	return contains2(e, this->t);
}
template < class T >
bool TreeListImp<T> :: full() const {
	return false;
}
template < class T >
bool TreeListImp<T> ::isEmpty() const {
	return !this->t;
}
template < class T >
unsigned int TreeListImp<T> :: Length() const {
	return this->length;
}
template < class T >
void TreeListImp<T>::empty() {
	while (!this->isEmpty()) {
		this->Delete(this->element());
	}
}
template <class T> 
T TreeListImp<T> ::element() {
	return this->t->dato;
}
template < class T >
ABBT<T> * TreeListImp<T> ::treeCopy(ABBT<T> * original)const {
	if (original) {
		ABBT<T> * nuevo = createNode(original->dato);
		nuevo->left = treeCopy(original->left);
		nuevo->rigth = treeCopy(original->rigth);
		return nuevo;
	}
	else {
		return NULL;
	}
}
template < class T >
void TreeListImp<T> ::print2(ABBT<T> * t) const {
	if (t) {
		print2(t->left);
		cout << t->dato << " ";
		print2(t->rigth);
	}
}
template < class T >
void TreeListImp<T> ::print() const {
	print2(this->t);
}
template < class T >
TreeListImp<T>* TreeListImp<T> ::clone() const {
	TreeListImp<T> * clon = new TreeListImp<T>();
	clon->t = treeCopy(this->t);
	unsigned int largo = this->length;
	clon->length = largo;
	return clon;
}
#endif // !TreeListImp_CPP
