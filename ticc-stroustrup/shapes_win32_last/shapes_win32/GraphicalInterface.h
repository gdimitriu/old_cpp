#pragma once

#include "Shapes.h"
#include "stdafx.h"

class CGraphicalInterface
{
private:
	HDC m_hdc;	
public:	
	CGraphicalInterface(void){m_hdc=NULL;};
	void SetHDC(HDC &hdc) {m_hdc=hdc;};
	CGraphicalInterface(HDC &hdc){m_hdc=hdc;};
	~CGraphicalInterface(void){};
	void draw(CShapes *Shape){ Shape->draw(m_hdc);}
};

