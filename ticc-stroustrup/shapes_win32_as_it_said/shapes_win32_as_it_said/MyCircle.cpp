#include "MyCircle.h"
#include <math.h>

CMyCircle::CMyCircle(void):CMyShape()
{
}
//constructor for circle with center and radius
CMyCircle::CMyCircle(CMyPoint &center,UINT uradius)
{
	int radius=uradius;
	//initialized everything with center
	m_w=m_e=m_n=m_s=m_se=m_sw=m_nw=m_ne=m_c=center;
	m_s.offsetY(radius);
	m_n.offsetY(-radius);
	m_w.offsetX(-radius);
	m_e.offsetX(radius);
	m_ne.offsetX(radius*cos(pi/2.0));
	m_ne.offsetY(-radius*sin(pi/2.0));
	m_se.offsetX(radius*cos(pi/2.0));
	m_se.offsetY(radius*sin(pi/2.0));
	m_nw.offsetX(-radius*cos(pi/2.0));
	m_nw.offsetY(-radius*sin(pi/2.0));
	m_sw.offsetX(-radius*cos(pi/2.0));
	m_sw.offsetY(radius*sin(pi/2.0));
}

CMyCircle::~CMyCircle(void)
{
}
//draw the circle as an ellipse
void CMyCircle::draw(void)
{
	m_pDC->Ellipse(m_w.getX(),m_n.getY(),m_e.getX(),m_s.getY());
}