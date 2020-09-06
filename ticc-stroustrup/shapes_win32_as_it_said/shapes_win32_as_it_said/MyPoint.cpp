#include "MyPoint.h"
//operator !=
bool CMyPoint::operator!=(CMyPoint &point)
{
	if(m_x!=point.m_x || m_y!=point.m_y)
		return true;
	else
		return false;
}
//operator ==
bool CMyPoint::operator==(CMyPoint &point)
{
	if(m_x==point.m_y && m_y==point.m_y)
		return true;
	else
		return false;
}

CMyPoint& CMyPoint::operator=(UINT value)
{
	m_x=m_y=value;
	return(*this);
}
CMyPoint& CMyPoint::operator=(CMyPoint &point)
{
	m_x=point.m_x;
	m_y=point.m_y;
	return(*this);
}
CMyPoint& CMyPoint::operator+=(CMyPoint &point)
{
	m_x+=point.m_x;
	m_y+=point.m_y;
	return(*this);
}