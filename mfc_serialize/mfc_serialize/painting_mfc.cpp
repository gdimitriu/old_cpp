#include <afxwin.h>

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMyWindow : public CFrameWnd
{
public:
	DECLARE_SERIAL(CMyWindow);
	CMyWindow();
	afx_msg void OnMouseMove(UINT flags,CPoint point);
	afx_msg void OnLButtonUp(UINT flags,CPoint point);
	afx_msg void OnRButtonDown(UINT flags,CPoint point);
	virtual void Serialize(CArchive& ar)
	{
		m_values.Serialize(ar);
	}
	DECLARE_MESSAGE_MAP();
private:
	CObArray m_values;
};

IMPLEMENT_SERIAL(CMyWindow,CFrameWnd,1);

class CMyPoint : public CObject
{
public:
	DECLARE_SERIAL(CMyPoint);
	CMyPoint(CPoint point)
	{
		m_point=point;
	}
	CMyPoint()
	{
	}
	virtual void Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			//normal code for storing contents 
			//of this object
			ar<<m_point.x;
			ar<<m_point.y;
		}
		else
		{
			//normal code for reading contents 
			//of this object
			ar>>m_point.x;
			ar>>m_point.y;
		}

		//allow the base class to serialize along 
		//with its version information
		CObject::Serialize(ar);
	}
	int GetX() { return m_point.x;}
	int GetY() { return m_point.y;}
protected:
	CPoint m_point;
};

IMPLEMENT_SERIAL(CMyPoint,CObject,1);

BOOL CMyApp::InitInstance()
{
	m_pMainWnd=new CMyWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMyWindow,CFrameWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP();

CMyApp myApp;

CMyWindow::CMyWindow()
{
	Create(NULL,_T("painting mfc"),WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
}
void CMyWindow::OnMouseMove(UINT flags,CPoint point)
{
	if(flags==MK_LBUTTON)
	{
		CClientDC dc(this);
		CMyPoint* pPoint=new CMyPoint(point);
		dc.SetPixel(point.x,point.y,1);
		m_values.Add(pPoint);
	}
}

void CMyWindow::OnLButtonUp(UINT flags,CPoint point)
{
	CFile *pFile=new CFile(_T("stored.dat"),CFile::modeCreate | CFile::modeWrite);
	CArchive ar(pFile,CArchive::store);
	Serialize(ar);
	ar.Close();
	pFile->Close();
}

void CMyWindow::OnRButtonDown(UINT flags,CPoint point)
{
	CFile File;
	BOOL status;
	status=File.Open(_T("stored.dat"),CFile::modeRead);
	if(status!=FALSE)
	{
		CArchive ar(&File,CArchive::load);
		Serialize(ar);
		File.Close();
		CClientDC dc(this);
		CMyPoint *pPoint;
		for(int i=0;i<m_values.GetSize();++i)
		{
			pPoint=dynamic_cast<CMyPoint *>(m_values.GetAt(i));
			dc.SetPixel(pPoint->GetX(),pPoint->GetY(),1);
		}
	}
}