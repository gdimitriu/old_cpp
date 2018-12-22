// arboriDlg.h : header file
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the dialog header.

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

#if !defined(AFX_ARBORIDLG_H__03C450E7_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
#define AFX_ARBORIDLG_H__03C450E7_49FA_11DA_B910_B337BE9EF70F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "data.h"
#include "listaDL.h"
#include "stack.h"
#include "tree.h"
#include <fstream>
#define LAST IDC_estack
/////////////////////////////////////////////////////////////////////////////
// CArboriDlg dialog
using namespace std;
class CArboriDlg : public CDialog
{
// Construction
public:
	CArboriDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CArboriDlg)
	enum { IDD = IDD_ARBORI_DIALOG };
	int		m_ival;
	CString	m_result;
	int		m_ssearch;
	int		m_sview;
	CString	m_fname;
	int		m_eval;
	CString	m_eresult;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArboriDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	Cdata *m_mem;
	fstream m_file;
	// Generated message map functions
	//{{AFX_MSG(CArboriDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInsert();
	afx_msg void OnSave();
	afx_msg void OnSearch();
	afx_msg void OnView();
	afx_msg void OnListDL();
	afx_msg void OnErase();
	afx_msg void OnCreate();
	afx_msg void OnLoad();
	afx_msg void Ondelete();
	afx_msg void Onreset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedResetfile();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARBORIDLG_H__03C450E7_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
