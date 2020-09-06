#pragma once
#ifndef IntArrayRC_H
#define IntArrayRC_H
#include "intarray.h"
class IntArrayRC :
	public IntArray
{
public:
	IntArrayRC(int sz=DefaultArraySize) : IntArray(sz) {};
	IntArrayRC(int *array,int array_size) : IntArray(array,array_size) {};
	IntArrayRC(const IntArrayRC &rhs) : IntArray(rhs.ia,rhs._size) {};
	virtual int& operator[](int);
private:
	void check_range(int);
};
#endif
