// teste_2Dlg.h : header file
//

#if !defined(AFX_TESTE_2DLG_H__AB5CB2A4_9329_4519_8F85_FFCDB9A8B22C__INCLUDED_)
#define AFX_TESTE_2DLG_H__AB5CB2A4_9329_4519_8F85_FFCDB9A8B22C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<FSTREAM.H>

/////////////////////////////////////////////////////////////////////////////
// CTeste_2Dlg dialog

class CTeste_2Dlg : public CDialog
{
// Construction
public:
	CString Messages[6];
	BOOL m_ReadVal;
	int NrRaspunsuri;
	int NrIntrebari;
	char m_temp;
	CString FileName;
	int m_Valori[6];
	int m_Contor;
	BOOL m_Exit;
	BOOL m_Flag;
	int Raspunsuri[6];
	ifstream InputFile;
	CTeste_2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTeste_2Dlg)
	enum { IDD = IDD_TESTE_2_DIALOG };
	BOOL	m_b1;
	BOOL	m_b2;
	BOOL	m_b3;
	BOOL	m_b4;
	BOOL	m_b5;
	BOOL	m_b6;
	CString	m_Enunt;
	CString	m_Message1;
	CString	m_Message2;
	CString	m_Message3;
	CString	m_Message4;
	CString	m_Message5;
	CString	m_Message6;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeste_2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTeste_2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbort();
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTE_2DLG_H__AB5CB2A4_9329_4519_8F85_FFCDB9A8B22C__INCLUDED_)
