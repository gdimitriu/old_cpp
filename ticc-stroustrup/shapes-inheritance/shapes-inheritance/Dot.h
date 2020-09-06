#pragma once
#include "shapes.h"
#include "CmyPoint.h"
class CDot :
	public CShapes
{
public:
	CDot(void): m_point(0,0){};
	CDot(CmyPoint &point):m_point(point){};
	virtual ~CDot(void){};
	void draw(CClientDC *pdc);
private:
	CmyPoint m_point;
};

