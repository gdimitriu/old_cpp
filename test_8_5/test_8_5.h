// test_8_5.h : main header file for the TEST_8_5 application
//

#if !defined(AFX_TEST_8_5_H__56FD89ED_2193_4F25_BA1C_656DCCB5C23C__INCLUDED_)
#define AFX_TEST_8_5_H__56FD89ED_2193_4F25_BA1C_656DCCB5C23C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest_8_5App:
// See test_8_5.cpp for the implementation of this class
//

class CTest_8_5App : public CWinApp
{
public:
	CTest_8_5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_8_5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest_8_5App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_8_5_H__56FD89ED_2193_4F25_BA1C_656DCCB5C23C__INCLUDED_)
