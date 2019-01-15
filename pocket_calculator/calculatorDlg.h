// calculatorDlg.h : header file
//
/*
	Copyright 2006 Gabriel Dimitriu

	This file is part of Computer.
	This is the definition of the dialog interface.
	
    Computer is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Computer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Computer; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#if !defined(AFX_CALCULATORDLG_H__1E7690E7_AAAA_11DA_B910_FF68DBF41048__INCLUDED_)
#define AFX_CALCULATORDLG_H__1E7690E7_AAAA_11DA_B910_FF68DBF41048__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog
#include "computer.h"
class Ccomputer;
class CCalculatorDlg : public CDialog
{
// Construction
public:
	void clear();
	void update(double rez);
	Ccomputer * computer;
	bool iseq;
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	CString	m_rez;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void On0();
	afx_msg void On1();
	afx_msg void On2();
	afx_msg void On3();
	afx_msg void On4();
	afx_msg void On5();
	afx_msg void On6();
	afx_msg void On7();
	afx_msg void On8();
	afx_msg void On9();
	afx_msg void Onadd();
	afx_msg void Onegal();
	afx_msg void Onsub();
	afx_msg void Onpct();
	afx_msg void Ondel();
	afx_msg void Ondiv();
	afx_msg void Onmul();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__1E7690E7_AAAA_11DA_B910_FF68DBF41048__INCLUDED_)
