// calculatorDlg.cpp : implementation file
//
/*
	Copyright 2006 Gabriel Dimitriu

	This file is part of Computer.
	This is the implementation of the dialog interface.
	
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

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_rez = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_rez, m_rez);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, On0)
	ON_BN_CLICKED(IDC_1, On1)
	ON_BN_CLICKED(IDC_2, On2)
	ON_BN_CLICKED(IDC_3, On3)
	ON_BN_CLICKED(IDC_4, On4)
	ON_BN_CLICKED(IDC_5, On5)
	ON_BN_CLICKED(IDC_6, On6)
	ON_BN_CLICKED(IDC_7, On7)
	ON_BN_CLICKED(IDC_8, On8)
	ON_BN_CLICKED(IDC_9, On9)
	ON_BN_CLICKED(IDC_add, Onadd)
	ON_BN_CLICKED(IDC_egal, Onegal)
	ON_BN_CLICKED(IDC_sub, Onsub)
	ON_BN_CLICKED(IDC_pct, Onpct)
	ON_BN_CLICKED(IDC_del, Ondel)
	ON_BN_CLICKED(IDC_div, Ondiv)
	ON_BN_CLICKED(IDC_mul, Onmul)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	computer=new Ccomputer();
	iseq=false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalculatorDlg::On0() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('0');
	m_rez.Insert(m_rez.GetLength(),'0');
	UpdateData(FALSE);
}

void CCalculatorDlg::On1() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('1');
	m_rez.Insert(m_rez.GetLength(),'1');
	UpdateData(FALSE);
}

void CCalculatorDlg::On2() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('2');
	m_rez.Insert(m_rez.GetLength(),'2');
	UpdateData(FALSE);
}

void CCalculatorDlg::On3() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('3');
	m_rez.Insert(m_rez.GetLength(),'3');
	UpdateData(FALSE);
}

void CCalculatorDlg::On4() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('4');
	m_rez.Insert(m_rez.GetLength(),'4');
	UpdateData(FALSE);
}

void CCalculatorDlg::On5() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('5');
	m_rez.Insert(m_rez.GetLength(),'5');
	UpdateData(FALSE);
}

void CCalculatorDlg::On6() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('6');
	m_rez.Insert(m_rez.GetLength(),'6');
	UpdateData(FALSE);
}

void CCalculatorDlg::On7() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('7');
	m_rez.Insert(m_rez.GetLength(),'7');
	UpdateData(FALSE);
}

void CCalculatorDlg::On8() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('8');
	m_rez.Insert(m_rez.GetLength(),'8');
	UpdateData(FALSE);
}

void CCalculatorDlg::On9() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('9');
	m_rez.Insert(m_rez.GetLength(),'9');
	UpdateData(FALSE);
}

void CCalculatorDlg::Onadd() 
{
	computer->operatie('+');
	m_rez.Insert(m_rez.GetLength(),'+');
	UpdateData(FALSE);
}

void CCalculatorDlg::Onegal() 
{
	double rez;
	if(iseq==false) clear();
	else
	{
		m_rez.Insert(m_rez.GetLength(),'=');
		computer->operatie('=');
		computer->get(&rez);
		CString temp;
		temp.Format("%lf",rez);
		m_rez.Insert(m_rez.GetLength(),temp);
		iseq=false;
		UpdateData(FALSE);
	}
}

void CCalculatorDlg::Onsub() 
{
	computer->operatie('-');
	m_rez.Insert(m_rez.GetLength(),'-');
	UpdateData(FALSE);
}

void CCalculatorDlg::Onpct() 
{
	if(iseq==false){ clear();iseq=true;}
	computer->Addop('.');
	m_rez.Insert(m_rez.GetLength(),'.');
	UpdateData(FALSE);
}

void CCalculatorDlg::update(double rez)
{
	CString temp;
	temp.Format("%lf",rez);
	m_rez.Insert(m_rez.GetLength(),temp);
	UpdateData(FALSE);
}

void CCalculatorDlg::clear()
{
	m_rez.Empty();
	UpdateData(FALSE);
}

void CCalculatorDlg::Ondel() 
{
	computer->delop();
	m_rez.Delete(m_rez.GetLength()-1,1);
	UpdateData(FALSE);
}

void CCalculatorDlg::Ondiv() 
{
	computer->operatie('/');
	m_rez.Insert(m_rez.GetLength(),'/');
	UpdateData(FALSE);
}

void CCalculatorDlg::Onmul() 
{
	computer->operatie('*');
	m_rez.Insert(m_rez.GetLength(),'*');
	UpdateData(FALSE);
}
