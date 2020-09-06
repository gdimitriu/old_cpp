#pragma once
#include "definitions.h"
//this class will hold only the point information
class CMyPoint
{
protected:
	long int m_x;
	long int m_y;
public:
	CMyPoint(void): m_x(0),m_y(0){};
	CMyPoint(UINT value): m_x(value),m_y(value){};
	CMyPoint(UINT x,UINT y) : m_x(x),m_y(y) {};
	//copy constructor
	CMyPoint(CMyPoint &point): m_x(point.m_x),m_y(point.m_y) {};
	//setters and gethers
	void setX(UINT x) { m_x=x;};
	void setY(UINT y) { m_y=y;};
	UINT getX(void) { return m_x;};
	UINT getY(void) { return m_y;};
	bool operator!=(CMyPoint &point);//inequality operator
	bool operator==(CMyPoint &point);//equality operator
	CMyPoint& operator=(UINT value);//assing operator for empty value
	CMyPoint& operator+=(CMyPoint &point);//+operator
	CMyPoint& operator=(CMyPoint &point);//assig operator for the same type
	//add only x or y is the user duty to validate the negative or positive values
	CMyPoint& offsetX(int x){ m_x+=x;return(*this);}
	CMyPoint& offsetY(int y){ m_y+=y;return(*this);}
	~CMyPoint(void) {};
};

