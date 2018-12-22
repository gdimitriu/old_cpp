// arboriDlg.cpp : implementation file
//
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the dialog implementation.

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

#include "stdafx.h"
#include "arbori.h"
#include "arboriDlg.h"

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
// CArboriDlg dialog

CArboriDlg::CArboriDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CArboriDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CArboriDlg)
	m_ival = 0;
	m_result = _T("");
	m_ssearch = 0;
	m_sview = 0;
	m_fname = _T("");
	m_eval = 0;
	m_eresult = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CArboriDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArboriDlg)
	DDX_Text(pDX, IDC_Ival, m_ival);
	DDX_Text(pDX, IDC_SResult, m_result);
	DDX_Text(pDX, IDC_sSearch, m_ssearch);
	DDX_Text(pDX, IDC_sview, m_sview);
	DDX_Text(pDX, IDC_Fname, m_fname);
	DDX_Text(pDX, IDC_Eval, m_eval);
	DDX_Text(pDX, IDC_eresult, m_eresult);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CArboriDlg, CDialog)
	//{{AFX_MSG_MAP(CArboriDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Insert, OnInsert)
	ON_BN_CLICKED(IDC_Save, OnSave)
	ON_BN_CLICKED(IDC_Search, OnSearch)
	ON_BN_CLICKED(IDC_View, OnView)
	ON_BN_CLICKED(IDC_Erase, OnErase)
	ON_BN_CLICKED(IDC_Create, OnCreate)
	ON_BN_CLICKED(IDC_Load, OnLoad)
	ON_BN_CLICKED(IDC_delete, Ondelete)
	ON_BN_CLICKED(IDC_reset, Onreset)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ResetFile, &CArboriDlg::OnBnClickedResetfile)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArboriDlg message handlers

BOOL CArboriDlg::OnInitDialog()
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
	m_mem=NULL;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CArboriDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CArboriDlg::OnPaint() 
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
HCURSOR CArboriDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CArboriDlg::OnErase() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_mem->erase(m_eval)==false)
	{
		m_eresult.Empty();
		m_eresult.Insert(0,"The value can't be erased");
	}
	else
	{
		m_eresult.Empty();
		m_eresult.Insert(0,"The value has been erased");
	}
	UpdateData(FALSE);
}

void CArboriDlg::OnInsert() 
{
	UpdateData(TRUE);
	m_mem->add(m_ival);
}

void CArboriDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	LPTSTR str;
	if(m_fname.IsEmpty()==TRUE)
	{
		CString strfile;
		CFileDialog fdial(FALSE);
		if(IDCANCEL==fdial.DoModal())
		{
			return;
		}
		strfile=fdial.GetPathName();
		m_fname.Empty();
		m_fname.Insert(0,strfile);
		UpdateData(FALSE);
	}
	str=m_fname.GetBuffer(2);
	int temp;
	m_file.open(str,ios::out | ios::binary);
	m_fname.ReleaseBuffer();
	switch(this->GetCheckedRadioButton(IDC_elistDL,LAST))
	{
		case (IDC_elistDL):
		{
			temp=IDC_elistDL;
			m_file.write((char *)(&temp),sizeof(int));
			m_mem->reset();
			while(m_mem->get(temp)==true)
				m_file.write((char *)&temp,sizeof(int));
			break;
		}
		case (IDC_estack):
		{
			temp=IDC_estack;
			m_file.write((char *)(&temp),sizeof(int));
			Cstack *ptemp;
			ptemp=new Cstack();
			while(m_mem->get(temp)==true)
				ptemp->add(temp);
			while(ptemp->get(temp)==true)
				m_file.write((char *)&temp,sizeof(int));
			delete ptemp;
			break;
		}
		case (IDC_etree):
		{
			temp=IDC_etree;
			m_file.write((char *)(&temp),sizeof(int));
			m_mem->reset();
			while(((Ctree *)m_mem)->getr(temp)==true)
				m_file.write((char *)&temp,sizeof(int));
			break;
		}
	}
	m_file.close();
}

void CArboriDlg::OnLoad() 
{
	// TODO: Add your control notification handler code here
	if(m_mem!=NULL)
	{
		AfxMessageBox("You have create another memory !",MB_OK,0);
		return;
	}
	UpdateData(TRUE);
	LPTSTR str;
	if(m_fname.IsEmpty()==TRUE)
	{
		CString strfile;
		CFileDialog fdial(TRUE);
		if(IDCANCEL==fdial.DoModal())
		{
			return;
		}
		strfile=fdial.GetPathName();
		m_fname.Empty();
		m_fname.Insert(0,strfile);
		UpdateData(FALSE);
	}
	str=m_fname.GetBuffer(2);
	int temp;
	m_file.open(str,ios::in | ios::binary);
	m_fname.ReleaseBuffer();
	m_file.read((char *)&temp,sizeof(int));
	this->CheckRadioButton(IDC_elistDL,LAST,temp);
	switch(temp)
	{
		case (IDC_elistDL):
		{
			ClistaDL *ptemp;
			ptemp=new ClistaDL();
			m_mem=(Cdata *)ptemp;
			break;
		}
		case (IDC_estack):
		{
			Cstack *ptemp;
			ptemp=new Cstack();
			m_mem=(Cdata *)ptemp;
			break;
		}
		case (IDC_etree):
		{
			Ctree *ptemp;
			ptemp=new Ctree();
			m_mem=(Cdata *)ptemp;
			break;
		}
	}
	while(!m_file.eof())
	{
		m_file.read((char *)&temp,sizeof(int));
		if(m_file.eof()!=0) break;
		m_mem->add(temp);
	}
	m_file.close();
	UpdateData(FALSE);
	
}

void CArboriDlg::OnSearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_mem->search(m_ssearch)==false)
	{
		m_result.Empty();
		m_result.Insert(0,"The element hasn't been found");
	}
	else
	{
		m_result.Empty();
		m_result.Insert(0,"The element has been found");
	}
	UpdateData(FALSE);
}

void CArboriDlg::OnView() 
{
	bool temp=m_mem->get(m_sview);
	if(temp==false) m_sview=-1024;
	UpdateData(FALSE);
}

void CArboriDlg::OnCreate() 
{
	// TODO: Add your control notification handler code here
	if(m_mem!=NULL)
	{
		AfxMessageBox("You have create anothere memory !",MB_OK,0);
		return;
	}
	switch(this->GetCheckedRadioButton(IDC_elistDL,LAST))
	{
		case (IDC_elistDL):
		{
			ClistaDL *temp;
			temp=new ClistaDL();
			m_mem=(Cdata *)temp;
			break;
		}
		case (IDC_estack):
		{
			Cstack *temp;
			temp=new Cstack();
			m_mem=(Cdata *)temp;
			break;
		}
		case (IDC_etree):
		{
			Ctree *temp;
			temp=new Ctree();
			m_mem=(Ctree *)temp;
			break;
		}
	}
}


void CArboriDlg::Ondelete() 
{
	delete m_mem;
	m_mem=NULL;
}

void CArboriDlg::Onreset() 
{
	m_mem->reset();
}

void CArboriDlg::OnBnClickedResetfile()
{
	m_fname.Empty();
	UpdateData(FALSE);
}
