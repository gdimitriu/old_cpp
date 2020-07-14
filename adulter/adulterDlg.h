// adulterDlg.h : header file
//

#if !defined(AFX_ADULTERDLG_H__69438705_A621_4310_B2BE_21D4AF79ADB3__INCLUDED_)
#define AFX_ADULTERDLG_H__69438705_A621_4310_B2BE_21D4AF79ADB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<FSTREAM.H>

/////////////////////////////////////////////////////////////////////////////
// CAdulterDlg dialog

class CAdulterDlg : public CDialog
{
// Construction
public:
	char m_temp;
	BOOL m_exit;
	CAdulterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdulterDlg)
	enum { IDD = IDD_ADULTER_DIALOG };
	BOOL	m_bA;
	BOOL	m_bB;
	BOOL	m_bC;
	BOOL	m_bD;
	CString	m_MessageA;
	CString	m_MessageB;
	CString	m_MessageC;
	CString	m_MessageD;
	CString	m_Enunt;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdulterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdulterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbort();
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int NrRaspunsuri;
	ifstream InputFile;
	BOOL m_Flag;
	int m_Raspunsuri[4];
	int m_Punctaj;
	int m_Contor;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADULTERDLG_H__69438705_A621_4310_B2BE_21D4AF79ADB3__INCLUDED_)
