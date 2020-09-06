#pragma once
#include "afxwin.h"
#include "MyPoint.h"
#include "MyShape.h"
#include <vector>
using std::vector;

class CMyWindow :
	public CFrameWnd
{
	DECLARE_DYNAMIC(CMyWindow);
private:
	CMyPoint m_current;
	vector<CMyShape *> m_shapes;
	void tests(void);
	void house(void);
public:
	CMyWindow(void);
	//set the currect point
	void current(CMyPoint point);
	//return the current point
	CMyPoint current(void);
	~CMyWindow(void);
	//{{AFX_MSG(CMyWindow)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

