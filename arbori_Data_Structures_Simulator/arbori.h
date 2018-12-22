// arbori.h : main header file for the ARBORI application
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	

    Arbori (Data Structures Simulator) is free software; you can redistribute
	it and/or modify it under the terms of the GNU General Public License as 
	published by the Free Software Foundation; either version 2 of the License,
	or (at your option) any later version.

    Arbori (Data Structures Simulator) is distributed in the hope that it will
	be useful,but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Arbori (Data Structures Simulator); if not, write to the Free 
	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#if !defined(AFX_ARBORI_H__03C450E5_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
#define AFX_ARBORI_H__03C450E5_49FA_11DA_B910_B337BE9EF70F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CArboriApp:
// See arbori.cpp for the implementation of this class
//

class CArboriApp : public CWinApp
{
public:
	CArboriApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArboriApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CArboriApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARBORI_H__03C450E5_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
