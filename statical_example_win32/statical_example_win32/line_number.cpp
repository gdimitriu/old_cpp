#include "StdAfx.h"
#include "line_number.h"


line_number::line_number(void)
{
}


line_number::~line_number(void)
{
}


void line_number::goto_line(int line)
{
	m_Line=line;
}


int line_number::get_current_line(void)
{
	return m_Line;
}


long int line_number::get_char_pos(void)
{
	return 0;
}
