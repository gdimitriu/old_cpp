#pragma once
#include "shapes.h"
#include "CmyPoint.h"
class CLine :
	public CShapes
{
private:
	CmyPoint m_first;
	CmyPoint m_second;
public:
	CLine(void):m_first(0,0),m_second(0,0){};
	CLine(CmyPoint first,CmyPoint second):m_first(first),m_second(second){};
	virtual ~CLine(void){};
	virtual void draw(CClientDC *pdc);
};

