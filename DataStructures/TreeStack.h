// TreeStack.h: interface for the CTreeStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREESTACK_H__02463C82_BB8A_11DB_B910_9A35301BFA40__INCLUDED_)
#define AFX_TREESTACK_H__02463C82_BB8A_11DB_B910_9A35301BFA40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "StackElem.h"

class CTreeStack  
{
public:
	bool IsEmpty();
	void Empty();
	CNode * Pop();
	void Push(CNode *node);
	CTreeStack();
	virtual ~CTreeStack();
protected:
	CStackElem *m_top;
};

#endif // !defined(AFX_TREESTACK_H__02463C82_BB8A_11DB_B910_9A35301BFA40__INCLUDED_)
