// Sort.h: interface for the CSort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORT_H__F4AAC4E1_BC1C_11DB_B910_9A35301BFA40__INCLUDED_)
#define AFX_SORT_H__F4AAC4E1_BC1C_11DB_B910_9A35301BFA40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSort  
{
public:
	void ShellSort();
	void ShakeSort();
	void BubleSort();
	void DirectSel();
	void DirectIns();
	void Print();
	CSort();
	virtual ~CSort();
	CSort(long *val,int n);
protected:
	long *data;
	int nr;
};

#endif // !defined(AFX_SORT_H__F4AAC4E1_BC1C_11DB_B910_9A35301BFA40__INCLUDED_)
