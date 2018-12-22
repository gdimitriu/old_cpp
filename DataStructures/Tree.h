// Tree.h: interface for the CTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREE_H__94E74804_BA8A_11DB_B910_D4EA6C7C5E48__INCLUDED_)
#define AFX_TREE_H__94E74804_BA8A_11DB_B910_D4EA6C7C5E48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Node.h"
#include "TreeStack.h"
#define DATA_TYPES 4
class CTree  
{
public:
	void ResetGet(int type);
	void * Get(int type);
	int Del(char val);
	int Del(char *val);
	int Del(double val);
	int Del(long val);
	void PrintSRD(int type);
	void PrintSDR(int type);
	void PrintRSD(int type);
	void Add(CNode *root,int type);
	void Add(char val);
	void Add(char *val);
	void Add(double val);
	void Add(long val);
	CTree();
	virtual ~CTree();
protected:
	void PrintSDR(CNode *root);
	void PrintSRD(CNode *root);
	void PrintRSD(CNode *root);
	CNode *roots[DATA_TYPES];
	CTreeStack stacks[DATA_TYPES];
	bool was[DATA_TYPES];
	CNode *views[DATA_TYPES];
	CNode *parc,*nparc,*old;
	CNode *left,*right;
	void *data[DATA_TYPES];
	bool m_first[DATA_TYPES];
};

#endif // !defined(AFX_TREE_H__94E74804_BA8A_11DB_B910_D4EA6C7C5E48__INCLUDED_)
