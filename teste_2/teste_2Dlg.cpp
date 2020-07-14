// teste_2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "teste_2.h"
#include "teste_2Dlg.h"

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
// CTeste_2Dlg dialog

CTeste_2Dlg::CTeste_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTeste_2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTeste_2Dlg)
	m_b1 = FALSE;
	m_b2 = FALSE;
	m_b3 = FALSE;
	m_b4 = FALSE;
	m_b5 = FALSE;
	m_b6 = FALSE;
	m_Enunt = _T("");
	m_Message1 = _T("");
	m_Message2 = _T("");
	m_Message3 = _T("");
	m_Message4 = _T("");
	m_Message5 = _T("");
	m_Message6 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTeste_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTeste_2Dlg)
	DDX_Check(pDX, IDC_b1, m_b1);
	DDX_Check(pDX, IDC_b2, m_b2);
	DDX_Check(pDX, IDC_b3, m_b3);
	DDX_Check(pDX, IDC_b4, m_b4);
	DDX_Check(pDX, IDC_b5, m_b5);
	DDX_Check(pDX, IDC_b6, m_b6);
	DDX_Text(pDX, IDC_ENUNT, m_Enunt);
	DDX_Text(pDX, IDC_m1, m_Message1);
	DDX_Text(pDX, IDC_m2, m_Message2);
	DDX_Text(pDX, IDC_m3, m_Message3);
	DDX_Text(pDX, IDC_m4, m_Message4);
	DDX_Text(pDX, IDC_m5, m_Message5);
	DDX_Text(pDX, IDC_m6, m_Message6);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTeste_2Dlg, CDialog)
	//{{AFX_MSG_MAP(CTeste_2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABORT, OnAbort)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeste_2Dlg message handlers

BOOL CTeste_2Dlg::OnInitDialog()
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
	CFileDialog m_File(TRUE);
	if(m_File.DoModal()==IDOK)
		FileName=m_File.GetFileName();
	else OnOK();
	InputFile.open(FileName,ios::in);
	InputFile.seekg(0,ios::beg);
	m_Contor=0;
	for(int i=0;i<6;i++)	m_Valori[i]=Raspunsuri[i]=0;
	m_Enunt="Aici va fi enuntul, trebuie sa alegeti un singur raspuns!";
	m_Message1="Aici va fi raspunsul pentru optiunea 1!";
	m_Message2="Aici va fi raspunsul pentru optiunea 2!";
	m_Message3="Aici va fi raspunsul pentru optiunea 3!";
	m_Message4="Aici va fi raspunsul pentru optiunea 4!";
	m_Message5="Aici va fi raspunsul pentru optiunea 5!";
	m_Message6="Aici va fi raspunsul pentru optiunea 6!";
	m_Enunt="Aici va fi enuntul, nu aveti voie decit la un raspuns:";
	UpdateData(FALSE);
	m_Flag=FALSE;
	m_Exit=FALSE;
	InputFile>>NrIntrebari>>NrRaspunsuri;
	InputFile>>m_temp;
	m_ReadVal=TRUE;
	int contor=0;
	GetDlgItem(IDC_m1)->ShowWindow(TRUE);
	GetDlgItem(IDC_b1)->ShowWindow(TRUE);
	contor++;
	if(contor<NrRaspunsuri)
	{
		GetDlgItem(IDC_m2)->ShowWindow(TRUE);
		GetDlgItem(IDC_b2)->ShowWindow(TRUE);
		contor++;
	}
	else
	{
		GetDlgItem(IDC_m2)->ShowWindow(FALSE);
		GetDlgItem(IDC_b2)->ShowWindow(FALSE);
	}
	if(contor<NrRaspunsuri)
	{
		GetDlgItem(IDC_m3)->ShowWindow(TRUE);
		GetDlgItem(IDC_m3)->ShowWindow(TRUE);
		contor++;
	}
	else
	{
		GetDlgItem(IDC_m3)->ShowWindow(FALSE);
		GetDlgItem(IDC_b3)->ShowWindow(FALSE);
	}
	if(contor<NrRaspunsuri)
	{
		GetDlgItem(IDC_m4)->ShowWindow(TRUE);
		GetDlgItem(IDC_b4)->ShowWindow(TRUE);
		contor++;
	}
	else
	{
		GetDlgItem(IDC_m4)->ShowWindow(FALSE);
		GetDlgItem(IDC_b4)->ShowWindow(FALSE);
	}
	if(contor<NrRaspunsuri)
	{
		GetDlgItem(IDC_m5)->ShowWindow(TRUE);
		GetDlgItem(IDC_m5)->ShowWindow(TRUE);
		contor++;
	}
	else
	{
		GetDlgItem(IDC_m5)->ShowWindow(FALSE);
		GetDlgItem(IDC_b5)->ShowWindow(FALSE);
	}
	if(contor<NrRaspunsuri)
	{
		GetDlgItem(IDC_m6)->ShowWindow(TRUE);
		GetDlgItem(IDC_m6)->ShowWindow(TRUE);
		contor++;
	}
	else
	{
		GetDlgItem(IDC_m6)->ShowWindow(FALSE);
		GetDlgItem(IDC_b6)->ShowWindow(FALSE);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTeste_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTeste_2Dlg::OnPaint() 
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
HCURSOR CTeste_2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTeste_2Dlg::OnAbort() 
{
	// TODO: Add your control notification handler code here
	InputFile.close();
	OnOK();
}

void CTeste_2Dlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	int i;
	int contor;
	if(m_Contor!=0)
	{
		if(m_Flag==FALSE)
		{
			for(i=0;i<NrRaspunsuri;i++) InputFile>>m_Valori[i];
			m_ReadVal=TRUE;
			InputFile>>m_temp;
		}
		else m_ReadVal=FALSE;
		UpdateData(TRUE);
		m_Flag=FALSE;
		m_Exit=FALSE;
		contor=0;
		if(m_b1==TRUE)
		{
			i=m_Valori[0];
			m_Flag=TRUE;
			contor++;
		}
		if(m_b2==TRUE && contor<NrRaspunsuri)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un raspuns!");
				m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
				UpdateData(FALSE);
				m_Exit=TRUE;
			}
			else
			{
				i=m_Valori[1];
				m_Flag=TRUE;
				contor++;
			}
		}
		if(m_b3==TRUE && contor<NrRaspunsuri)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un raspuns!");
				m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
				UpdateData(FALSE);
				m_Exit=TRUE;
			}
			else
			{
				i=m_Valori[2];
				m_Flag=TRUE;
				contor++;
			}
		}
		if(m_b4==TRUE && contor<NrRaspunsuri)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un raspuns!");
				m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
				UpdateData(FALSE);
				m_Exit=TRUE;
			}
			else
			{
				i=m_Valori[3];
				m_Flag=TRUE;
				contor++;
			}
		}
		if(m_b5==TRUE && contor<NrRaspunsuri)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un raspuns!");
				m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
				UpdateData(FALSE);
				m_Exit=TRUE;
			}
			else
			{
				i=m_Valori[4];
				m_Flag=TRUE;
				contor++;
			}
		}
		if(m_b6==TRUE && contor<NrRaspunsuri)
		{
			if(m_Flag==TRUE)
			{
				MessageBox("Trebuie sa alegeti doar un raspuns!");
				m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
				UpdateData(FALSE);
				m_Exit=TRUE;
			}
			else
			{
				i=m_Valori[5];
				m_Flag=TRUE;
				contor++;
			}
		}
		if(m_Flag==FALSE)
		{
			MessageBox("Trebuie sa alegeti doar un raspuns!");
			m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
			UpdateData(FALSE);
			m_Exit=TRUE;
			m_Flag=TRUE;
		}
		if(m_Exit==FALSE) Raspunsuri[i]++;
	}
	if(m_Exit==FALSE)
	{
		if(m_Contor<NrIntrebari)
		{
			InputFile.getline(m_Enunt.GetBuffer(2000),2000);
			m_Enunt.ReleaseBuffer();
			if(m_ReadVal==TRUE)
			{
				m_Enunt.Insert(0,m_temp);
				m_ReadVal=FALSE;
			}
			contor=0;
			InputFile.getline(m_Message1.GetBuffer(2000),2000);
			m_Message1.ReleaseBuffer();
			contor++;
			if(contor<NrRaspunsuri)
			{
				InputFile.getline(m_Message2.GetBuffer(2000),2000);
				m_Message2.ReleaseBuffer();
				contor++;
			}
			if(contor<NrRaspunsuri)
			{
				InputFile.getline(m_Message3.GetBuffer(2000),2000);
				m_Message3.ReleaseBuffer();
				contor++;
			}
			if(contor<NrRaspunsuri)
			{
				InputFile.getline(m_Message4.GetBuffer(2000),2000);
				m_Message4.ReleaseBuffer();
				contor++;
			}
			if(contor<NrRaspunsuri)
			{
				InputFile.getline(m_Message5.GetBuffer(2000),2000);
				m_Message5.ReleaseBuffer();
				contor++;
			}
			if(contor<NrRaspunsuri)
			{
				InputFile.getline(m_Message6.GetBuffer(2000),2000);
				m_Message6.ReleaseBuffer();
				contor++;
			}
			m_b1=m_b2=m_b3=m_b4=m_b5=m_b6=FALSE;
			UpdateData(FALSE);
			m_Flag=FALSE;
			m_Contor++;
		}
		else
		{
			for(i=0;i<NrRaspunsuri;i++)
			{
				InputFile.getline(Messages[i].GetBuffer(20000),20000);
				Messages[i].ReleaseBuffer();
				if(i==0 && m_ReadVal==TRUE) Messages[i].Insert(0,m_temp);
			}
			int temp;
			temp=0;
			for(i=1;i<NrRaspunsuri;i++) if(Raspunsuri[i]>Raspunsuri[temp]) temp=i;
			MessageBox(Messages[temp]);
			InputFile.close();
			OnOK();
		}
	}
}
