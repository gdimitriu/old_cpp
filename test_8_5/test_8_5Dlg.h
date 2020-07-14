// test_8_5Dlg.h : header file
//

#if !defined(AFX_TEST_8_5DLG_H__3E8E377E_7D77_4865_83D7_BB3EFDC3C126__INCLUDED_)
#define AFX_TEST_8_5DLG_H__3E8E377E_7D77_4865_83D7_BB3EFDC3C126__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<FSTREAM.H>
/////////////////////////////////////////////////////////////////////////////
// CTest_8_5Dlg dialog

class CTest_8_5Dlg : public CDialog
{
// Construction
public:
	ifstream InputFile;
	BOOL m_Exit;
	BOOL m_Flag;
	int m_Contor;
	int m_Punctaj;
	CString m_FileName;
	CTest_8_5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_8_5Dlg)
	enum { IDD = IDD_TEST_8_5_DIALOG };
	BOOL	m_b1;
	BOOL	m_b2;
	BOOL	m_b3;
	BOOL	m_b4;
	BOOL	m_b5;
	CString	m_Enunt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_8_5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_8_5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNext();
	afx_msg void OnAbort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_8_5DLG_H__3E8E377E_7D77_4865_83D7_BB3EFDC3C126__INCLUDED_)
