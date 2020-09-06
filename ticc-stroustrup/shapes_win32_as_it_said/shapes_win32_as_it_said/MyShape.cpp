#include "MyShape.h"

//constructor
CMyShape::CMyShape(void)
{
	m_pDC=NULL;
	m_color=RGB(255,0,0);
	m_s=m_n=m_e=m_w=m_ne=m_nw=m_se=m_sw=m_c=0;
}

//default destructor
CMyShape::~CMyShape(void)
{
}

//get window
CPaintDC *CMyShape::getWindow()
{
	return m_pDC;
}

//set window
void CMyShape::setWindow(CPaintDC *pdc)
{
	m_pDC=pdc;
}