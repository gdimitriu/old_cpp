// StackElem.h: interface for the CStackElem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACKELEM_H__02463C81_BB8A_11DB_B910_9A35301BFA40__INCLUDED_)
#define AFX_STACKELEM_H__02463C81_BB8A_11DB_B910_9A35301BFA40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"

class CStackElem  
{
public:
	CStackElem();
	virtual ~CStackElem();
	CStackElem *next;
	CNode *data;
};

#endif // !defined(AFX_STACKELEM_H__02463C81_BB8A_11DB_B910_9A35301BFA40__INCLUDED_)
