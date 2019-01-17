#pragma once
#include "CsA.h"
/************************************
* this is the class which contains the node
************************************/
class CnodeSparse
{
protected:
	unsigned long m_index;
	double m_value;
	class CnodeSparse *m_next;
	friend class CsA;
public:
	CnodeSparse(unsigned int index)
	{
		m_index=index;
		m_value=0;
		m_next=NULL;
	}
	CnodeSparse(void)
	{
		m_next=NULL;
	}
	~CnodeSparse(void)
	{
	}
};
