#pragma once
#include "myshape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle(void);
	CMyCircle(CMyPoint &center,UINT radius);
	~CMyCircle(void);
	void draw(void);
};

