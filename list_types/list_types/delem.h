#include "dlink.h"
#pragma once
template<class T> class CDelem : public CDLink
{
private:
	T m_data;
public:
	CDelem(T value): m_data(value),CDLink(){};
	T GetData(void) { return m_data;};
	~CDelem(){};
};