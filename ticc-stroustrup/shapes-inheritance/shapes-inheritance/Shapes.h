#pragma once
class CShapes
{
public:
	CShapes(void){};
	virtual ~CShapes(void){};
	virtual void draw(CClientDC *pdc)=0;
};

