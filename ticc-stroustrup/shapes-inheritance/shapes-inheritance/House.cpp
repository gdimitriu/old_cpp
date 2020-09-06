#include "StdAfx.h"
#include <afxwin.h>
#include "resource.h"
#include "House.h"
#include "Dot.h"
#include "Rectangle.h"
#include "Line.h"
#include <iostream>


CHouse::CHouse(void)
{
	m_graphical=new CGraphicalSystem;
	m_graphical->Create(IDD_GRAPHICALSYSTEM,NULL);
	m_graphical->ShowWindow(SW_SHOW);
}


CHouse::~CHouse(void)
{
	delete m_graphical;
}


void CHouse::Create(void)
{
	RECT window;
	m_graphical->GetClientRect(&window);
	std::cout<<"bottom="<<window.bottom<<" right="<<window.right<<std::endl;
	CmyPoint point1(100,window.bottom);
	CmyPoint point2(300,window.bottom-300);
	CRectangle *houseRect=new CRectangle(point1,point2);
	CmyPoint point3(100,window.bottom-300);
	CmyPoint point4(200,window.bottom-400);
	CLine *line1=new CLine(point3,point4);
	CLine *line2=new CLine(point4,point2);
	CmyPoint point5(125,window.bottom-50);
	CmyPoint point6(175,window.bottom-275);
	CRectangle *fenster=new CRectangle(point5,point6);
	CmyPoint point7(225,window.bottom);
	CmyPoint point8(275,window.bottom-150);
	CRectangle *door=new CRectangle(point7,point8);
	m_graphical->draw(houseRect);
	m_graphical->draw(line1);
	m_graphical->draw(line2);
	m_graphical->draw(fenster);
	m_graphical->draw(door);
	delete door;
	delete fenster;
	delete line1;
	delete line2;
	delete houseRect;
}
