// Fifo.h: interface for the CFifo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIFO_H__D3CFCFC1_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_FIFO_H__D3CFCFC1_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"
class CFifo  
{
public:
	void Push(char *val);
	void * Pop(int *type);
	void Push(char val);
	void Push(double val);
	void Push(long val);
	CFifo();
	virtual ~CFifo();
protected:
	CNode *head,*tail,*parc;
	void *data;
};

#endif // !defined(AFX_FIFO_H__D3CFCFC1_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_)
