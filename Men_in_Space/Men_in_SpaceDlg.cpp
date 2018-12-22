// Men_in_SpaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Men_in_Space.h"
#include "Men_in_SpaceDlg.h"

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
// CMen_in_SpaceDlg dialog

CMen_in_SpaceDlg::CMen_in_SpaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMen_in_SpaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMen_in_SpaceDlg)
	m_bA = FALSE;
	m_bB = FALSE;
	m_bC = FALSE;
	m_bD = FALSE;
	m_bE = FALSE;
	m_Enunt = _T("");
	m_MessageA = _T("");
	m_MessageB = _T("");
	m_MessageC = _T("");
	m_MessageD = _T("");
	m_MessageE = _T("");
	m_bF = FALSE;
	m_MessageF = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMen_in_SpaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMen_in_SpaceDlg)
	DDX_Check(pDX, IDC_A, m_bA);
	DDX_Check(pDX, IDC_B, m_bB);
	DDX_Check(pDX, IDC_C, m_bC);
	DDX_Check(pDX, IDC_D, m_bD);
	DDX_Check(pDX, IDC_E, m_bE);
	DDX_Text(pDX, IDC_ENUNT, m_Enunt);
	DDX_Text(pDX, IDC_MA, m_MessageA);
	DDX_Text(pDX, IDC_MB, m_MessageB);
	DDX_Text(pDX, IDC_MC, m_MessageC);
	DDX_Text(pDX, IDC_MD, m_MessageD);
	DDX_Text(pDX, IDC_ME, m_MessageE);
	DDX_Check(pDX, IDC_F, m_bF);
	DDX_Text(pDX, IDC_MF, m_MessageF);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMen_in_SpaceDlg, CDialog)
	//{{AFX_MSG_MAP(CMen_in_SpaceDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMen_in_SpaceDlg message handlers

BOOL CMen_in_SpaceDlg::OnInitDialog()
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
	m_Count=0;
	m_MessageA="Aici va fi mesajul pentru optiunea A.";
	m_MessageB="Aici va fi mesajul pentru optiunea B.";
	m_MessageC="Aici va fi mesajul pentru optiunea C.";
	m_MessageD="Aici va fi mesajul pentru optiunea D.";
	m_MessageE="Aici va fi mesajul pentru optiunea E.";
	m_MessageF="Aici va fi mesajul pentru optiunea F.";
	m_Punctaj=0.0;
	InputFile.open("men_in_space.dat",ios::in);
	InputFile.seekg(0,ios::beg);
	InputFile.getline(m_Enunt.GetBuffer(200),200);
	m_Enunt.ReleaseBuffer();
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMen_in_SpaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMen_in_SpaceDlg::OnPaint() 
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
HCURSOR CMen_in_SpaceDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMen_in_SpaceDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	char str;
	BOOL flag;
	int i;
	float temp=0;
	flag=FALSE;
	if(m_Count!=0)
	{
		UpdateData(TRUE);
		for(i=0;i<m_NrRaspunsuri;i++) InputFile>>valori[i];
		m_Bifate[0]=m_bA;
		m_Bifate[1]=m_bB;
		m_Bifate[2]=m_bC;
		m_Bifate[3]=m_bD;
		m_Bifate[4]=m_bE;
		m_Bifate[5]=m_bF;
		flag=FALSE;
		for(i=0;i<m_NrRaspunsuri;i++)
		{
			if((valori[i]>0)&&m_Bifate[i]==TRUE) temp+=valori[i];
			else if((valori[i]==0.0) && m_Bifate[i]==TRUE)
			{
				temp=0;
				flag=TRUE;
			}
		}
		if(flag==FALSE)	m_Punctaj+=temp;
		flag=FALSE;
		//i=InputFile.peek();
		InputFile>>str;
		if(str<=57 && str>=48) flag=FALSE;
		else flag=TRUE;
		InputFile.seekg(-1,ios::cur);
		m_bA=m_bB=m_bC=m_bD=m_bE=m_bF=FALSE;
		m_MessageA="Aici va fi mesajul pentru optiunea A.";
		m_MessageB="Aici va fi mesajul pentru optiunea B.";
		m_MessageC="Aici va fi mesajul pentru optiunea C.";
		m_MessageD="Aici va fi mesajul pentru optiunea D.";
		m_MessageE="Aici va fi mesajul pentru optiunea E.";
		m_MessageF="Aici va fi mesajul pentru optiunea F.";
		UpdateData(FALSE);
	}
	if(flag==FALSE)
	{
		InputFile>>m_NrRaspunsuri>>str;
		InputFile.getline(m_Enunt.GetBuffer(2000),2000);
		m_Enunt.ReleaseBuffer();
		m_Enunt.Insert(0,str);
		switch(m_NrRaspunsuri)
		{
		case 1:
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			break;
		case 2:
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			break;
		case 3:
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			InputFile.getline(m_MessageC.GetBuffer(2000),2000);
			m_MessageC.ReleaseBuffer();
			break;
		case 4:
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			InputFile.getline(m_MessageC.GetBuffer(2000),2000);
			m_MessageC.ReleaseBuffer();
			InputFile.getline(m_MessageD.GetBuffer(2000),2000);
			m_MessageD.ReleaseBuffer();
			break;
		case 5:
			InputFile.getline(m_MessageA.GetBuffer(2000),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			InputFile.getline(m_MessageC.GetBuffer(2000),2000);
			m_MessageC.ReleaseBuffer();
			InputFile.getline(m_MessageD.GetBuffer(2000),2000);
			m_MessageD.ReleaseBuffer();
			InputFile.getline(m_MessageE.GetBuffer(2000),2000);
			m_MessageE.ReleaseBuffer();
			break;
		case 6:
			InputFile.getline(m_MessageA.GetBuffer(200),2000);
			m_MessageA.ReleaseBuffer();
			InputFile.getline(m_MessageB.GetBuffer(2000),2000);
			m_MessageB.ReleaseBuffer();
			InputFile.getline(m_MessageC.GetBuffer(2000),2000);
			m_MessageC.ReleaseBuffer();
			InputFile.getline(m_MessageD.GetBuffer(2000),2000);
			m_MessageD.ReleaseBuffer();
			InputFile.getline(m_MessageE.GetBuffer(2000),2000);
			m_MessageE.ReleaseBuffer();
			InputFile.getline(m_MessageF.GetBuffer(2000),2000);
			m_MessageF.ReleaseBuffer();
			break;
		default:
			MessageBox("Este o eroare in fisierul de raspunsuri!");
			break;
		}
		m_Count=1;
		UpdateData(FALSE);
	}
	else
	{
		CString mesaje[4];
		for(i=0;i<4;i++)
		{
			InputFile.getline(mesaje[i].GetBuffer(2000),2000);
			mesaje[i].ReleaseBuffer();
		}
		if(m_Punctaj<=6) MessageBox(mesaje[0]);
		else if(m_Punctaj<=12) MessageBox(mesaje[1]);
		else if(m_Punctaj<=18) MessageBox(mesaje[2]);
		else if(m_Punctaj<=25) MessageBox(mesaje[3]);
	}
}

void CMen_in_SpaceDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	InputFile.close();
	CDialog::OnCancel();
}
