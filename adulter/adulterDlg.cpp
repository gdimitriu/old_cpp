// adulterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "adulter.h"
#include "adulterDlg.h"

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
// CAdulterDlg dialog

CAdulterDlg::CAdulterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdulterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdulterDlg)
	m_bA = FALSE;
	m_bB = FALSE;
	m_bC = FALSE;
	m_bD = FALSE;
	m_MessageA = _T("");
	m_MessageB = _T("");
	m_MessageC = _T("");
	m_MessageD = _T("");
	m_Enunt = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdulterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdulterDlg)
	DDX_Check(pDX, IDC_bA, m_bA);
	DDX_Check(pDX, IDC_bB, m_bB);
	DDX_Check(pDX, IDC_bC, m_bC);
	DDX_Check(pDX, IDC_bD, m_bD);
	DDX_Text(pDX, IDC_mA, m_MessageA);
	DDX_Text(pDX, IDC_mB, m_MessageB);
	DDX_Text(pDX, IDC_mC, m_MessageC);
	DDX_Text(pDX, IDC_mD, m_MessageD);
	DDX_Text(pDX, IDC_ENUNT, m_Enunt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdulterDlg, CDialog)
	//{{AFX_MSG_MAP(CAdulterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABORT, OnAbort)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdulterDlg message handlers

BOOL CAdulterDlg::OnInitDialog()
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
	m_Contor=m_Punctaj=0;
	InputFile.open("adulter.dat",ios::in);
	InputFile.seekg(0,ios::beg);
	InputFile>>NrRaspunsuri;
	char temp;
	InputFile>>temp;
	InputFile.getline(m_Enunt.GetBuffer(2000),2000);
	m_Enunt.ReleaseBuffer();
	m_Enunt.Insert(0,temp);
	m_MessageA="Aici va fi optiunea pentru A";
	m_MessageB="Aici va fi optiunea pentru B";
	m_MessageC="Aici va fi optiunea pentru C";
	m_MessageD="Aici va fi optiunea pentru D";
	m_Flag=FALSE;
	m_exit=FALSE;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdulterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdulterDlg::OnPaint() 
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
HCURSOR CAdulterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdulterDlg::OnAbort() 
{
	// TODO: Add your control notification handler code here
	InputFile.close();
	OnOK();
	
}

void CAdulterDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	int i;
	if(m_Contor!=0)
	{
		if(m_Flag==FALSE)
		{
			for(i=0;i<4;i++) InputFile>>m_Raspunsuri[i];
			InputFile>>m_temp;
		}
		UpdateData(TRUE);
		m_Flag=FALSE;
		m_exit=FALSE;
		if(m_bA==TRUE) { i=0; m_Flag=TRUE;}
		if(m_bB==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un singur raspuns!");
				m_bA=m_bB=m_bC=m_bD=FALSE;
				UpdateData(FALSE);
				m_exit=TRUE;
			}
			else
			{
				m_Flag=TRUE;
				i=1;
			}
		}
		if(m_bC==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un singur raspuns!");
				m_bA=m_bB=m_bC=m_bD=FALSE;
				UpdateData(FALSE);
				m_exit=TRUE;
			}
			else
			{
				m_Flag=TRUE;
				i=2;
			}
		}
		if(m_bD==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un singur raspuns!");
				m_bA=m_bB=m_bC=m_bD=FALSE;
				UpdateData(FALSE);
				m_exit=TRUE;
			}
			else
			{
				m_Flag=TRUE;
				i=3;
			}
		}
		if(m_Flag==FALSE)
		{
			MessageBox("Trebuie sa alegeti doar un singur raspuns!");
			m_bA=m_bB=m_bC=m_bD=FALSE;
			m_Flag=TRUE;
			UpdateData(FALSE);
			m_exit=TRUE;
		}
		if(m_exit==FALSE)
		{
			m_Punctaj+=m_Raspunsuri[i];
			m_Flag=FALSE;
		}
	}
	if(m_exit==FALSE)
	{
		if(m_Contor<NrRaspunsuri)
		{
			InputFile.getline(m_Enunt.GetBuffer(2000),2000);
			m_Enunt.ReleaseBuffer();
			if(m_Contor!=0)m_Enunt.Insert(0,m_temp);
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			InputFile.getline(m_MessageC.GetBuffer(2000),2000);
			m_MessageC.ReleaseBuffer();
			InputFile.getline(m_MessageD.GetBuffer(2000),2000);
			m_MessageD.ReleaseBuffer();
			m_bA=m_bB=m_bC=m_bD=FALSE;
			UpdateData(FALSE);
			m_Contor++;
		}
		else 
		{
			CString Message[4];
			for(i=0;i<4;i++)
			{
				InputFile.getline(Message[i].GetBuffer(2000),2000);
				Message[i].ReleaseBuffer();
				if(i==0) Message[0].Insert(0,m_temp);
			}
			if(m_Punctaj<5) MessageBox(Message[0]);
			else if(m_Punctaj<13) MessageBox(Message[1]);
			else if(m_Punctaj<22) MessageBox(Message[2]);
			else MessageBox(Message[3]);
			InputFile.close();
			OnOK();
		}
	}
}
