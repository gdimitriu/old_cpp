#pragma once
#include <memory.h>
/*********************************************
* this is the implementation of the sparse infinite array
* this will implement one dimensional sparse vector using 
* linked list
*********************************************/
class CnodeSparse;
class CsA
{
protected:
	class CnodeSparse *m_head;
public:
	CsA(void);
	~CsA(void);
	double &operator [] (unsigned long);
	void List(void);
};

