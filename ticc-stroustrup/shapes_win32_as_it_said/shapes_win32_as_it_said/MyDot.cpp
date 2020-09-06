#include "MyDot.h"


CMyDot::CMyDot(void):CMyShape()
{
}

CMyDot::CMyDot(CMyPoint &point)
{
	m_c.setX(point.getX());
	m_c.setY(point.getY());
	//rest are exactly as the center because the point has no dimension
	m_sw=m_nw=m_n=m_s=m_se=m_ne=m_e=m_w=m_c;
}

CMyDot::~CMyDot(void)
{
}

void CMyDot::draw(void)
{
	m_pDC->SetPixel(m_c.getX(),m_c.getY(),m_color);
}