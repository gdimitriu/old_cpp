// test_8_5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_8_5.h"
#include "test_8_5Dlg.h"

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
// CTest_8_5Dlg dialog

CTest_8_5Dlg::CTest_8_5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_8_5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_8_5Dlg)
	m_b1 = FALSE;
	m_b2 = FALSE;
	m_b3 = FALSE;
	m_b4 = FALSE;
	m_b5 = FALSE;
	m_Enunt = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_8_5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_8_5Dlg)
	DDX_Check(pDX, IDC_b1, m_b1);
	DDX_Check(pDX, IDC_b2, m_b2);
	DDX_Check(pDX, IDC_b3, m_b3);
	DDX_Check(pDX, IDC_b4, m_b4);
	DDX_Check(pDX, IDC_b5, m_b5);
	DDX_Text(pDX, IDC_Enunt, m_Enunt);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_8_5Dlg, CDialog)
	//{{AFX_MSG_MAP(CTest_8_5Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_ABORT, OnAbort)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_8_5Dlg message handlers

BOOL CTest_8_5Dlg::OnInitDialog()
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
	CFileDialog m_FileOpen(TRUE);
	if(m_FileOpen.DoModal()==IDOK)
	{
		m_FileName=m_FileOpen.GetFileName();
		UpdateData(FALSE);
	}
	else OnOK();
	m_Contor=m_Punctaj=0;
	InputFile.open(m_FileName,ios::in);
	InputFile.seekg(0,ios::beg);
	m_Enunt="Raspunde la urmatoarele intrebari alegind, in functie de gradul preferintele de la 1 la 5.";
	m_Exit=FALSE;
	m_Flag=FALSE;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_8_5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_8_5Dlg::OnPaint() 
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
HCURSOR CTest_8_5Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_8_5Dlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	int i;
	if(m_Contor!=0)
	{
		m_Flag=FALSE;
		m_Exit=FALSE;
		UpdateData(TRUE);
		if(m_b1==TRUE) {i=1; m_Flag=TRUE; }
		if(m_b2==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa aveti un singur raspuns!");
				m_Exit=TRUE;
				m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
				UpdateData(FALSE);
			}
			else
			{
				i=2;
				m_Flag=TRUE;
			}
		}
		if(m_b3==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa aveti un singur raspuns!");
				m_Exit=TRUE;
				m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
				UpdateData(FALSE);
			}
			else
			{
				i=3;
				m_Flag=TRUE;
			}
		}
		if(m_b4==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa aveti un singur raspuns!");
				m_Exit=TRUE;
				m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
				UpdateData(FALSE);
			}
			else
			{
				i=4;
				m_Flag=TRUE;
			}
		}
		if(m_b5==TRUE)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa aveti un singur raspuns!");
				m_Exit=TRUE;
				m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
				UpdateData(FALSE);
			}
			else
			{
				i=5;
				m_Flag=TRUE;
			}
		}
		if(m_Flag==FALSE)
		{
			MessageBox("Trebuie sa aveti un singur raspuns!");
			m_Exit=TRUE;
			m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
			UpdateData(FALSE);
		}
		if(m_Exit==FALSE) m_Punctaj+=i;
	}
	if(m_Exit==FALSE)
	{
		if(m_Contor<8)
		{
			InputFile.getline(m_Enunt.GetBuffer(2000),2000);
			m_Enunt.ReleaseBuffer();
			m_b1=m_b2=m_b3=m_b4=m_b5=FALSE;
			UpdateData(FALSE);
			m_Contor++;
		}
		else
		{
			CString message[3];
			for(i=0;i<3;i++)
			{
				InputFile.getline(message[i].GetBuffer(2000),2000);
				message[i].ReleaseBuffer();
			}
			if(m_Punctaj<19) MessageBox(message[0]);
			else if(m_Punctaj<32) MessageBox(message[1]);
			else MessageBox(message[2]);
			InputFile.close();
			OnOK();
		}
	}
}

void CTest_8_5Dlg::OnAbort() 
{
	// TODO: Add your control notification handler code here
	InputFile.close();
	OnOK();
}
