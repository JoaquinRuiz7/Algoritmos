#pragma once
#include <iostream>
#include<assert.h>
template < class T >
class ABBT {
public :
	T dato;
	ABBT * left;
	ABBT * rigth;
private:
	ABBT<T> &operator=(const ABBT<T> &n) { assert(false); return *this; }
};