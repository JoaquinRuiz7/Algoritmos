#pragma once
#ifndef ListaCheta_H
#define ListaCheta_H
#include <iostream>
#include <iostream>
template < class T >
class ListaCheta;
template < class T >
class ListaCheta abstract {
public :
	virtual ~ListaCheta() {}
	// Pre :
	// Pos : adds element at the end of the list.
	virtual void add(const T& e) abstract;
	// Pre : recieves an element.
	//¨Pos : deletes it from the list.
	virtual void Delete(const T&e) abstract;
	// Pre : the list isnt empty
	// Pos : returns true if the element is in the list.
	virtual bool contains(const T&e) const abstract;
	// Pre : 
	// Pos : return true if the list is full.
	virtual bool full() const abstract;
	// Pre : 
	// Pos : return true if the list is empty.
	virtual bool isEmpty() const abstract;
	// Pre : list !empty
	// Pos : deletes all elements of the list.
	virtual void empty() abstract;
	// Pre : list not empty.
	// Pos : returns the first element of the list.
	
	virtual void print()const abstract;
	
	// Pre : list not empty.
	// Pos : return a clone of the list tht doesnt share 
	// memory with this.
	virtual ListaCheta<T> * clone() const abstract;
	// Pre :
	// Pos : return the length of the list.
	virtual unsigned int length() const abstract;
	// Pre : recives a new parameter position must be 1 or higher(1<=position <= n).
	// Pos : replaces the value at i with the parameter value. 
	virtual void replace(const T&e , unsigned int position) abstract;
	// Pre : list ! empty
	// Pos : deletes the element in i position.
	virtual void deleteInPosition(unsigned int position) abstract;

protected:
	ListaCheta() {}
	ListaCheta(const ListaCheta<T> & l) {}

};
#endif // !ListaCheta_H
