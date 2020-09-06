#include "MyRectangle.h"


CMyRectangle::CMyRectangle(void):CMyShape()
{
}


CMyRectangle::~CMyRectangle(void)
{
}
//constructor for rectangle
CMyRectangle::CMyRectangle(CMyPoint bl,CMyPoint tr)
{
	m_sw=bl;
	m_ne=tr;
	m_nw.setX(bl.getX());
	m_nw.setY(tr.getY());
	m_se.setX(tr.getX());
	m_se.setY(bl.getY());
	//center of the rectangle
	m_c.setX(tr.getX()+(tr.getX()-bl.getX())/2);
	m_c.setY(tr.getY()+(tr.getY()-bl.getY())/2);
	//east point of the rectangle is at middle of the east line
	m_e.setX(tr.getX());
	m_e.setY(tr.getY()+(tr.getY()-bl.getY())/2);
	//west point of the rectangle is at middle of the west line
	m_w.setX(bl.getX());
	m_w.setY(tr.getY()+(tr.getY()-bl.getY())/2);
	//north point of the rectangle is at middle of the north line
	m_n.setX(bl.getX()+(tr.getX()-bl.getX())/2);
	m_n.setY(tr.getY());
	//south point of the rectangle is at middle of the south line
	m_s.setX(bl.getX()+(tr.getX()-bl.getX())/2);
	m_s.setY(bl.getY());
}

void CMyRectangle::draw(void)
{
	m_pDC->Rectangle(m_sw.getX(),m_sw.getY(),m_ne.getX(),m_ne.getY());
}