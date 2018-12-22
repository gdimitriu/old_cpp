// Men_in_SpaceDlg.h : header file
//

#if !defined(AFX_MEN_IN_SPACEDLG_H__687F2831_6AA1_44D8_B6C6_0D854676C1C0__INCLUDED_)
#define AFX_MEN_IN_SPACEDLG_H__687F2831_6AA1_44D8_B6C6_0D854676C1C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<FSTREAM.H>
/////////////////////////////////////////////////////////////////////////////
// CMen_in_SpaceDlg dialog

class CMen_in_SpaceDlg : public CDialog
{
// Construction
public:
	float valori[6];
	int m_NrRaspunsuri;
	CMen_in_SpaceDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMen_in_SpaceDlg)
	enum { IDD = IDD_MEN_IN_SPACE_DIALOG };
	BOOL	m_bA;
	BOOL	m_bB;
	BOOL	m_bC;
	BOOL	m_bD;
	BOOL	m_bE;
	CString	m_Enunt;
	CString	m_MessageA;
	CString	m_MessageB;
	CString	m_MessageC;
	CString	m_MessageD;
	CString	m_MessageE;
	BOOL	m_bF;
	CString	m_MessageF;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMen_in_SpaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMen_in_SpaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNext();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_Bifate[6];
	float m_Punctaj;
	ifstream InputFile;
	int m_Count;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEN_IN_SPACEDLG_H__687F2831_6AA1_44D8_B6C6_0D854676C1C0__INCLUDED_)
