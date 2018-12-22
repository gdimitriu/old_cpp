// DList.h: interface for the CDList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLIST_H__293A25A7_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_DLIST_H__293A25A7_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"
#define DATA_TYPES 4
class CDList  
{
public:
	int Del(char val);
	int Del(char *val);
	int Del(double val);
	int Del(long val);
	void ResetGet(int type);
	void * Get(int type);
	void Add(char *val);
	void Add(char val);
	void Add(double val);
	void Add(long val);
	CDList();
	virtual ~CDList();
protected:
	CNode *head[DATA_TYPES];
	CNode *tail[DATA_TYPES];
	CNode *parc,*next,*prev;
	CNode *view[DATA_TYPES];
	void *data[DATA_TYPES];
};

#endif // !defined(AFX_DLIST_H__293A25A7_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
