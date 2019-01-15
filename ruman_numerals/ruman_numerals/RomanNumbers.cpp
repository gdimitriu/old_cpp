#include "StdAfx.h"
#include "RomanNumbers.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


CRomanNumbers::CRomanNumbers(void)
{
}


CRomanNumbers::~CRomanNumbers(void)
{
}


void CRomanNumbers::convert(int latin)
{
	char buffer[100];
	int decimalint;
	int iterator;
	int max_position;
	for(iterator=0;iterator<100;++iterator)
	{
		decimalbuffer[iterator]='\0';
	}
	_itoa(latin,buffer,10);
	max_position=strlen(buffer);
	m_position=0;	
	for(iterator=0;iterator<max_position;++iterator)
	{
		decimalint=buffer[iterator]-48;
		switch(max_position-iterator-1)
		{
		case 0:
			{
				//decimal
				m_replacefirstchar='I';
				m_replacesecondchar='V';
				m_replacethirdchar='X';
				m_position=convertsmalldecimal(decimalint,m_position);
				break;
			}
		case 1:
			{
				//teens
				m_replacefirstchar='X';
				m_replacesecondchar='L';
				m_replacethirdchar='C';
				m_position=convertsmalldecimal(decimalint,m_position);
				break;
			}
		case 2:
			{
				//hundreds
				m_replacefirstchar='C';
				m_replacesecondchar='D';
				m_replacethirdchar='M';
				m_position=convertsmalldecimal(decimalint,m_position);
				break;
			}
		}
	}
	cout<<decimalbuffer<<"\n";
}

int CRomanNumbers::convertsmalldecimal(int decimal,int position)
{
	switch(decimal)
	{
		case 0:
		{
			return position;
		}
		case 1:
		{
			decimalbuffer[position]=m_replacefirstchar;
			return position+1;
		}
		case 2:
		{
			decimalbuffer[position+1]=m_replacefirstchar;
			decimalbuffer[position]=m_replacefirstchar;
			return position+2;
		}
		case 3:
		{
			decimalbuffer[position+2]=m_replacefirstchar;
			decimalbuffer[position+1]=m_replacefirstchar;
			decimalbuffer[position]=m_replacefirstchar;
			return position+3;
		}
		case 4:
		{
			decimalbuffer[position]=m_replacefirstchar;
			decimalbuffer[position+1]=m_replacesecondchar;
			return position+2;
		}
		case 5:
		{
			decimalbuffer[position]=m_replacesecondchar;
			return position+1;
		}
		case 9:
		{
			decimalbuffer[position]=m_replacefirstchar;
			decimalbuffer[position+1]=m_replacethirdchar;
			return position+2;
		}
		default:
		{
			return convertbigdecimal(decimal,position);
		}
	}
}

int CRomanNumbers::convertbigdecimal(int decimal,int position)
{
	int bigdecimal;
	int local_position;
	bigdecimal=decimal-5;
	decimalbuffer[position]=m_replacesecondchar;
	local_position=convertsmalldecimal(bigdecimal,position+1);	
	return local_position;
}


void CRomanNumbers::convertreverse(int latin)
{
	char buffer[100];
	int decimalint;
	int iterator;
	for(iterator=0;iterator<100;++iterator)
	{
		decimalbuffer[iterator]='\0';
	}
	_itoa(latin,buffer,10);
	iterator=strlen(buffer)-1;
	decimalint=buffer[iterator]-48;
	m_replacefirstchar='I';
	m_replacesecondchar='V';
	m_replacethirdchar='X';
	m_position=convertsmalldecimalreverse(decimalint,0);
	if((iterator-1)>=0)
	{
		decimalint=buffer[iterator-1]-48;
		m_replacefirstchar='X';
		m_replacesecondchar='L';
		m_replacethirdchar='C';
		m_position=convertsmalldecimalreverse(decimalint,m_position);
	}
	if((iterator-2)>=0)
	{
		decimalint=buffer[iterator-2]-48;
		m_replacefirstchar='C';
		m_replacesecondchar='D';
		m_replacethirdchar='M';
		m_position=convertsmalldecimalreverse(decimalint,m_position);
	}
	cout<<decimalbuffer<<"\n";
}

int CRomanNumbers::convertsmalldecimalreverse(int decimal,int position)
{
	switch(decimal)
	{
		case 0:
		{
			return position;
		}
		case 1:
		{
			decimalbuffer[position]=m_replacefirstchar;
			return position+1;
		}
		case 2:
		{
			decimalbuffer[position]=m_replacefirstchar;
			decimalbuffer[position+1]=m_replacefirstchar;
			return position+2;
		}
		case 3:
		{
			decimalbuffer[position]=m_replacefirstchar;
			decimalbuffer[position+1]=m_replacefirstchar;
			decimalbuffer[position+2]=m_replacefirstchar;
			return position+3;
		}
		case 4:
		{
			decimalbuffer[position+1]=m_replacefirstchar;
			decimalbuffer[position]=m_replacesecondchar;
			return position+2;
		}
		case 5:
		{
			decimalbuffer[position+0]=m_replacesecondchar;
			return position+1;
		}
		case 9:
		{
			decimalbuffer[position+1]=m_replacefirstchar;
			decimalbuffer[position]=m_replacethirdchar;
			return position+2;
		}
		default:
		{
			return convertbigdecimalreverse(decimal,position);
		}
	}
}

int CRomanNumbers::convertbigdecimalreverse(int decimal,int position)
{
	int bigdecimal;
	int local_position;
	bigdecimal=decimal-5;
	local_position=convertsmalldecimalreverse(bigdecimal,position);
	decimalbuffer[local_position]=m_replacesecondchar;
	return local_position+1;
}