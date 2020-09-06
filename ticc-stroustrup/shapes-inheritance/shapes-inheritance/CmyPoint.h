#pragma once
class CmyPoint
{
public:
	CmyPoint(void):m_x(0),m_y(0){};
	CmyPoint(CmyPoint &point) :m_x(point.m_x),m_y(point.m_y){};
	CmyPoint(int x,int y):m_x(x),m_y(y){};
	int GetX(){return m_x;};
	int GetY(){return m_y;};
	~CmyPoint(void){};
private:
	int m_x;
	int m_y;
};

