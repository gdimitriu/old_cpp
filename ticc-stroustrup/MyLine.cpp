#include "MyLine.h"
//default constructor
CMyLine::CMyLine(void): m_first(0,0),m_second(0,0)
{
}
//constructor with 2 points
CMyLine::CMyLine(CMyPoint first,CMyPoint second): m_first(first),m_second(second)
{
}
//copy constructor
CMyLine::CMyLine(CMyLine &line): m_first(line.m_first),m_second(line.m_second)
{
}
//destructor
CMyLine::~CMyLine()
{
}