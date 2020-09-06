//header for windows
#include <afxwin.h>
#include "MyWindow.h"

//class for main application
class shappesApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};

BOOL shappesApp::InitInstance(void)
{
	m_pMainWnd=new CMyWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

shappesApp my_app;