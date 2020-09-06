#pragma once
class line_number
{
protected:
	int m_Line;
public:
	line_number(void);
	~line_number(void);
	void goto_line(int line);
	int get_current_line(void);
	long int get_char_pos(void);
};

