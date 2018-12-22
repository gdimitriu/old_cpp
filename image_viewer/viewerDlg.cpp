// viewerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "viewer.h"
#include "viewerDlg.h"

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
// CViewerDlg dialog

CViewerDlg::CViewerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CViewerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CViewerDlg)
	m_FileName = _T("");
	m_OFileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CViewerDlg)
	DDX_Text(pDX, IDC_FN, m_FileName);
	DDX_Text(pDX, IDC_FN2, m_OFileName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CViewerDlg, CDialog)
	//{{AFX_MSG_MAP(CViewerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_read, Onread)
	ON_BN_CLICKED(IDC_write, Onwrite)
	ON_BN_CLICKED(IDC_compute, Oncompute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewerDlg message handlers

BOOL CViewerDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CViewerDlg::OnPaint() 
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
HCURSOR CViewerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CViewerDlg::Onread() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	LPTSTR fn;
	fn=m_FileName.GetBuffer(100);
	Irwbitmap.SetIFileName(fn);
	m_FileName.ReleaseBuffer();
	Irwbitmap.ReadFH();
	Irwbitmap.ReadData();
	CClientDC dc(this); // device context for painting
	unsigned long i,j;
	for(i=0;i<Irwbitmap.height();i++)
		for(j=0;j<Irwbitmap.width();j++)
			dc.SetPixel(j+100,i+100,Irwbitmap.data[i][j]);
}

void CViewerDlg::Onwrite() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	LPTSTR fn;
	fn=m_OFileName.GetBuffer(100);
	Orwbitmap.SetOFileName(fn);
	m_FileName.ReleaseBuffer();
	Orwbitmap.WriteFH();
	Orwbitmap.WriteData();
}

void CViewerDlg::Oncompute() 
{
	// TODO: Add your control notification handler code here
	void *B,*G,*R;
	unsigned short type;
	unsigned long comp;
	type=Irwbitmap.GetPalette(&B,&G,&R,&comp);
	Orwbitmap.SetHeight(32);
	Orwbitmap.SetWidth(32);
	Orwbitmap.SetPalette(B,G,R,type,&comp);
	Orwbitmap.CreateImg();
	//average window
	unsigned long i,j,k,l;
	double temp;
	unsigned long ltemp;
	for(i=0;i<32;i++)
	{
		for(j=0;j<32;j++)
		{
			temp=0.0;
			for(k=0;k<8;k++)
				for(l=0;l<8;l++)
					temp+=Irwbitmap.data[i*8+k][j*8+l]>>16;
			temp=temp/64;
			ltemp=temp;
			Orwbitmap.data[i][j]=(ltemp<<24)>>8;
		}
	}
	CClientDC dc(this); // device context for painting
	for(i=0;i<Irwbitmap.height();i++)
		for(j=0;j<Irwbitmap.width();j++)
			dc.SetPixel(j+100,i+100,Irwbitmap.data[i][j]);
	for(i=0;i<Orwbitmap.height();i++)
		for(j=0;j<Orwbitmap.width();j++)
			dc.SetPixel(j+100,i+200+Irwbitmap.height(),Orwbitmap.data[i][j]);
}
