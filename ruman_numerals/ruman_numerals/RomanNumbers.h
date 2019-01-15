#pragma once
#include <string>

class CRomanNumbers
{
private:
	int m_position;
	char decimalbuffer[100];
public:
	CRomanNumbers(void);
	~CRomanNumbers(void);
	void convertreverse(int latin);
	void convert(int latin);
private:
	char m_replacefirstchar;
	char m_replacesecondchar;
	char m_replacethirdchar;
	int convertsmalldecimalreverse(int decimal,int position);
	int convertbigdecimalreverse(int decimal,int position);
	int convertsmalldecimal(int decimal,int position);
	int convertbigdecimal(int decimal,int position);
};
