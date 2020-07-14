// adulter.h : main header file for the ADULTER application
//

#if !defined(AFX_ADULTER_H__31640C6E_0051_4257_B30B_ED5621E6F035__INCLUDED_)
#define AFX_ADULTER_H__31640C6E_0051_4257_B30B_ED5621E6F035__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdulterApp:
// See adulter.cpp for the implementation of this class
//

class CAdulterApp : public CWinApp
{
public:
	CAdulterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdulterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdulterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADULTER_H__31640C6E_0051_4257_B30B_ED5621E6F035__INCLUDED_)
