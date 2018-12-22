// Men_in_Space.h : main header file for the MEN_IN_SPACE application
//

#if !defined(AFX_MEN_IN_SPACE_H__541602B9_21F5_4D61_A519_7EB6C4FC572E__INCLUDED_)
#define AFX_MEN_IN_SPACE_H__541602B9_21F5_4D61_A519_7EB6C4FC572E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMen_in_SpaceApp:
// See Men_in_Space.cpp for the implementation of this class
//

class CMen_in_SpaceApp : public CWinApp
{
public:
	CMen_in_SpaceApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMen_in_SpaceApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMen_in_SpaceApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEN_IN_SPACE_H__541602B9_21F5_4D61_A519_7EB6C4FC572E__INCLUDED_)
