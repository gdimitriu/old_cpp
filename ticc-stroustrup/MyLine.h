#pragma once
#include "MyPoint.h"
class CMyLine
{
protected:
	CMyPoint m_first;
	CMyPoint m_second;
public:
	CMyLine(void);
	CMyLine(CMyPoint first,CMyPoint second);
	CMyLine(CMyLine &line);
	~CMyLine(void);
};

