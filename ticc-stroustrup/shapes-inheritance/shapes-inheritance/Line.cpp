#include "StdAfx.h"
#include "Line.h"

void CLine::draw(CClientDC *pdc)
{
	pdc->MoveTo(m_first.GetX(),m_first.GetY());
	pdc->LineTo(m_second.GetX(),m_second.GetY());
}