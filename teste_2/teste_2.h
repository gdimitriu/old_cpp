// teste_2.h : main header file for the TESTE_2 application
//

#if !defined(AFX_TESTE_2_H__8195998B_AAD7_4877_AA86_884BC4240BB0__INCLUDED_)
#define AFX_TESTE_2_H__8195998B_AAD7_4877_AA86_884BC4240BB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTeste_2App:
// See teste_2.cpp for the implementation of this class
//

class CTeste_2App : public CWinApp
{
public:
	CTeste_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeste_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTeste_2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTE_2_H__8195998B_AAD7_4877_AA86_884BC4240BB0__INCLUDED_)
