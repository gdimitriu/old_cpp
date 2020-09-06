#pragma once
#include "myshape.h"
class CMyRectangle :
	public CMyShape
{
public:
	CMyRectangle(void);
	CMyRectangle(CMyPoint bl,CMyPoint tr);
	~CMyRectangle(void);
	void draw();
};

