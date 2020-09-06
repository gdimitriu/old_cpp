#pragma once
#include "MyPoint.h"
#include <afxwin.h>
class CMyShape
{
protected:
	CMyPoint m_e;//est
	CMyPoint m_w;//west
	CMyPoint m_n;//north
	CMyPoint m_s;//south
	CMyPoint m_ne;//northest
	CMyPoint m_nw;//northwest
	CMyPoint m_se;//southest
	CMyPoint m_sw;//southwest
	CMyPoint m_c;//center
	CPaintDC *m_pDC;
	COLORREF m_color;
public:
	//constructor
	CMyShape(void);
	//default destructor
	~CMyShape(void);
	//setter and gether of the window pointer
	void setWindow(CPaintDC *pdc);
	CPaintDC *getWindow();
	//pure virtual function to be implemented by rest of the classes
	virtual void draw(void)=0;
	//gether for the contact points
	CMyPoint getSouth(void){return(m_s);}
	CMyPoint getNorth(void){return(m_n);}
	CMyPoint getEast(void){return(m_e);}
	CMyPoint getWest(void){return(m_w);}
	CMyPoint getSouthEast(void){return(m_se);}
	CMyPoint getSouthWest(void){return(m_sw);}
	CMyPoint getNortEast(void){return(m_ne);}
	CMyPoint getNortWest(void){return(m_nw);}
	CMyPoint getCenter(void){return(m_c);}
};

