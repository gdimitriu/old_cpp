// viewerDlg.h : header file
//

#if !defined(AFX_VIEWERDLG_H__2C229E45_C927_4FA9_A236_589F81259BCD__INCLUDED_)
#define AFX_VIEWERDLG_H__2C229E45_C927_4FA9_A236_589F81259BCD__INCLUDED_
#include "RWBitmap.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CViewerDlg dialog

class CViewerDlg : public CDialog
{
// Construction
public:
	CViewerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CViewerDlg)
	enum { IDD = IDD_VIEWER_DIALOG };
	CString	m_FileName;
	CString	m_OFileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CRWBitmap Irwbitmap;
	CRWBitmap Orwbitmap;
	// Generated message map functions
	//{{AFX_MSG(CViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onread();
	afx_msg void Onwrite();
	afx_msg void Oncompute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWERDLG_H__2C229E45_C927_4FA9_A236_589F81259BCD__INCLUDED_)
