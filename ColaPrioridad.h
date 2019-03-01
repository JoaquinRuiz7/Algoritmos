#pragma once
#ifndef ColaPrioridad_H
#define ColaPrioridad_H
template < class T > 
class ColaPrioridad abstract {
public :
	virtual ~ColaPrioridad() {}
	virtual void inQue(const T&e, unsigned int priority) abstract;
	virtual T unQue() abstract;
	virtual bool full() const abstract;
	virtual bool isEmpty() const abstract;
	virtual bool contains(const T&e) const abstract;
	virtual T first() abstract;
	virtual unsigned int maxPrioridad() const abstract;
	virtual unsigned int length() const abstract;
	virtual void destroy() abstract;
	virtual ColaPrioridad<T> * clone() const abstract;
};
#endif // !ColaPrioridad_H

