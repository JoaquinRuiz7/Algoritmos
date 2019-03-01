#pragma once
#ifndef TreeList_H
#define TreeList_H
#include<iostream>

template < class T >
class TreeList abstract {
public :
	virtual ~TreeList() {}
	virtual void add(const T&e) abstract;
	virtual void Delete(const T&e) abstract;
	virtual bool full() const abstract;
	virtual bool isEmpty() const abstract;
	virtual void empty() abstract;
	virtual unsigned int Length() const abstract;
	virtual bool contains(const T&e) const abstract;
	virtual void print() const abstract;
};
#endif // !TreeList_H

