// MFifo.h: interface for the CMFifo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFIFO_H__D3CFCFC2_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_MFIFO_H__D3CFCFC2_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Node.h"
#define DATA_TYPES 4
class CMFifo  
{
public:
	void * Pop(int type);
	void Push(char *val);
	void Push(char val);
	void Push(double val);
	void Push(long val);
	CMFifo();
	virtual ~CMFifo();
protected:
	CNode *head[DATA_TYPES];
	CNode *tail[DATA_TYPES];
	CNode *parc;
	void *data[DATA_TYPES];
};

#endif // !defined(AFX_MFIFO_H__D3CFCFC2_B9C1_11DB_B910_D4EA6C7C5E48__INCLUDED_)
