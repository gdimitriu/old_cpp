#pragma once
#include "myshape.h"
class CMyDot :
	public CMyShape
{
public:
	CMyDot(void);
	CMyDot(CMyPoint &point);
	~CMyDot(void);
	void draw();
};

