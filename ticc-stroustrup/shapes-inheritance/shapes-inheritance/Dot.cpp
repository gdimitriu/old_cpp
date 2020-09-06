#include "StdAfx.h"
#include "Dot.h"


void CDot::draw(CClientDC *pdc)
{
	pdc->SetPixel(m_point.GetX(),m_point.GetY(),RGB(0,0,0));
}