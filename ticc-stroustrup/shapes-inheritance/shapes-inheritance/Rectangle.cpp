#include "StdAfx.h"
#include "Rectangle.h"

void CRectangle::draw(CClientDC *pdc)
{
	pdc->Rectangle(m_bl.GetX(),m_bl.GetY(),m_tr.GetX(),m_tr.GetY());
}