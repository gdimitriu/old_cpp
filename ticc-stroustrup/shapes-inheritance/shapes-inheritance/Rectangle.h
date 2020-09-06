#pragma once
#include "shapes.h"
#include "CmyPoint.h"

class CRectangle :
	public CShapes
{
public:
	CRectangle(void):m_bl(0,0),m_tr(0,0){};
	CRectangle(CmyPoint bl,CmyPoint tr):m_bl(bl),m_tr(tr){};
	virtual void draw(CClientDC *pdc);
	virtual ~CRectangle(void){};
private:
	CmyPoint m_bl;
	CmyPoint m_tr;
};

