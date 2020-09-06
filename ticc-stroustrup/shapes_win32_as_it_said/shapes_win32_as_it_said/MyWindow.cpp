#include "MyWindow.h"
#include "MyRectangle.h"
#include "MyDot.h"
#include "MyCircle.h"
#include "MyLine.h"

IMPLEMENT_DYNAMIC(CMyWindow,CFrameWnd);

BEGIN_MESSAGE_MAP(CMyWindow, CFrameWnd)
	//{{AFX_MSG_MAP(CMyWindow)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//constructor
CMyWindow::CMyWindow(void):m_current(0,0)
{
	Create(NULL,_T("Stroustrup shapes"),WS_OVERLAPPEDWINDOW,CRect(0,0,300,300));
	house();
}
//the child house test as stroustrup said
void CMyWindow::house(void)
{
	CMyRectangle *rectangle=new CMyRectangle(CMyPoint(50,175),CMyPoint(200,100));
	m_shapes.push_back(rectangle);
	CMyLine *line=new CMyLine(rectangle->getNortWest(),CMyPoint(rectangle->getNorth().getX(),rectangle->getNorth().getY()-75));
	m_shapes.push_back(line);
	line=new CMyLine(CMyPoint(rectangle->getNorth().getX(),rectangle->getNorth().getY()-75),rectangle->getNortEast());
	m_shapes.push_back(line);
	rectangle=new CMyRectangle(CMyPoint(75,150),CMyPoint(125,125));
	m_shapes.push_back(rectangle);
	rectangle=new CMyRectangle(CMyPoint(135,175),CMyPoint(155,125));
	m_shapes.push_back(rectangle);
	rectangle=new CMyRectangle(CMyPoint(165,150),CMyPoint(185,125));
	m_shapes.push_back(rectangle);
}
//just tests for the framework
void CMyWindow::tests(void)
{
	CMyRectangle *rectangle=new CMyRectangle(CMyPoint(50,150),CMyPoint(150,50));
	m_shapes.push_back(rectangle);
	CMyDot *dot=new CMyDot(CMyPoint(100,100));
	m_shapes.push_back(dot);
	dot=new CMyDot(CMyPoint(75,75));
	m_shapes.push_back(dot);
	CMyCircle *circle=new CMyCircle(CMyPoint(100,100),25);
	m_shapes.push_back(circle);
	CMyLine *line=new CMyLine(circle->getCenter(),CMyPoint(150,150));
	m_shapes.push_back(line);
	line=new CMyLine(CMyPoint(50,50),CMyPoint(0,0));
	m_shapes.push_back(line);
	line=new CMyLine(CMyPoint(100,100),CMyPoint(50,150));
	m_shapes.push_back(line);
	line=new CMyLine(CMyPoint(100,100),CMyPoint(100,50));
	m_shapes.push_back(line);
}
//default destructor 
CMyWindow::~CMyWindow(void)
{
	for(vector<CMyShape *>::iterator i=m_shapes.begin();i!=m_shapes.end();++i)
		delete *i;
}
//setter for current point
void CMyWindow::current(CMyPoint point)
{
	m_current=point;
}
//gether for current point
CMyPoint CMyWindow::current(void)
{
	return m_current;
}

void CMyWindow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFrameWnd::OnPaint() for painting messages
	for(vector<CMyShape *>::iterator i=m_shapes.begin();i!=m_shapes.end();++i)
	{
		(*i)->setWindow(&dc);
		(*i)->draw();
		m_current=(*i)->getSouthEast();
	}
}
