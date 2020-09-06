#include "StdAfx.h"
#include "IntArray.h"
#include <cassert>

void IntArray::init(int sz,int *array)
{
	//set the data members
	_size=sz;
	ia=new int[_size];
	for(int ix=0;ix<_size;++ix)
	{
		if(!array)
			ia[ix]=0;
		else
			ia[ix]=array[ix];
	}
}

IntArray::IntArray(int sz)
{
	init(sz,0);
}

IntArray::IntArray(int *array,int sz)
{
	init(sz,array);
}

IntArray::IntArray(const IntArray &rhs)
{
	init(rhs._size,rhs.ia);
}

void IntArray::sort(void)
{

}

int IntArray::min(void) const
{
	return 0;
}

int IntArray::max(void) const
{
	return _size;
}

int IntArray::find(int value) const
{
	for(int i=0;i<_size;++i)
	{
		if(ia[i]==value)
			return ia[i];
	}
	return -1;
}

int& IntArray::operator[](int index)
{
	 return ia[index];
}