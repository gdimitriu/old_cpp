// Stack.h: interface for the CStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__293A25A6_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_STACK_H__293A25A6_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Node.h"
class CStack  
{
public:
	void Push(char val);
	void * Pop(int *type);
	void Push(char *val);
	void Push(double val);
	void Push(long val);
	CStack();
	virtual ~CStack();
protected:
	void * data;
	CNode *stack;
	CNode *parc;
};

#endif // !defined(AFX_STACK_H__293A25A6_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
