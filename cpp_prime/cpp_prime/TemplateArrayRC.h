#pragma once
#include <cassert>
#include "templatearray.h"
template <class elemType>
class TemplateArrayRC :
	public TemplateArray<elemType>
{
public:
	TemplateArrayRC(int sz=TemplateArray<elemType>::DefaultArraySize): TemplateArray<elemType>(sz) {};
	TemplateArrayRC(elemType *ia,int sz) : TemplateArray<elemType>(elemType *ia,int sz) {};
	TemplateArrayRC(const TemplateArrayRC &rhs) : TemplateArray<elemType>(rhs) {};
	virtual elemType& operator[](int index)
	{
		assert(index>=0 && index<TemplateArray<elemType>::size());
		return ia[index];
	}
};

