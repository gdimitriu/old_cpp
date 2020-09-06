#pragma once
#include "myshape.h"
class CMyLine :
	public CMyShape
{
public:
	CMyLine(void);
	CMyLine(CMyPoint &first,CMyPoint &second);
	~CMyLine(void);
	void draw(void);
};

