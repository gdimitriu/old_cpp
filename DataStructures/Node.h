// Node.h: interface for the CNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NODE_H__293A25A5_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_NODE_H__293A25A5_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNode  
{
public:
	CNode * GetDown();
	CNode * GetUp();
	void * View(void);
	void SetDown(CNode *down);
	void SetUp(CNode *up);
	void * Get(CNode **up,CNode **down,int *type);
	CNode();
	CNode(long val,CNode *up,CNode *down);
	CNode(double val,CNode *up,CNode *down);
	CNode(char *val,CNode *up,CNode *down);
	CNode(char val,CNode *up,CNode *down);
	virtual ~CNode();
protected:
	CNode *up;//==right
	CNode *down;//==left
	void *data;
	int type; //-1=nothing 0=long 1=double 2=string 3=char
};

#endif // !defined(AFX_NODE_H__293A25A5_B8F0_11DB_B910_D4EA6C7C5E48__INCLUDED_)
