#include "StdAfx.h"
#include "IntArrayRC.h"
#include <cassert>

int& IntArrayRC::operator[](int index)
{
	check_range(index);
	return ia[index];
}

inline void IntArrayRC::check_range(int index)
{
	assert(index>=0 && index<_size);
}