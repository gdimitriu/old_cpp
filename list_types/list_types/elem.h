#include "link.h"
#pragma once
template<class T> class Celem : public CLink
{
protected:
	T m_data;
public:
	Celem(T value) : CLink(),m_data(value){};
	T GetData() { return m_data;}
	~Celem(){};
};