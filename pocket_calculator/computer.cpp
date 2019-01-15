// computer.cpp: implementation of the Ccomputer class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2006 Gabriel Dimitriu

	This file is part of Computer.
	This is the implementation of the model of the computer.
	
    Computer is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Computer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Computer; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#include "stdafx.h"
#include "calculator.h"
#include "computer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ccomputer::Ccomputer()
{
	isop=false;
	input.Empty();
}

Ccomputer::~Ccomputer()
{

}

void Ccomputer::Addop(char ch)
{
	input.Insert(input.GetLength(),ch);
}

void Ccomputer::operatie(char ch)
{
	LPSTR wstr;
	wstr=input.GetBuffer(1000);
	oper=atof(wstr);
	input.ReleaseBuffer(1000);
	input.Empty();
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
	{
		if(isop==true)
		{
			switch(last)
			{
			case('+'):
				rez=inter+oper;
				inter=rez;
				break;
			case('-'):
				rez=inter-oper;
				inter=rez;
				break;
			case('*'):
				rez=inter*oper;
				inter=rez;
				break;
			case('/'):
				rez=inter/oper;
				inter=rez;
				break;
			}
			last=ch;
		}
		else
		{
			isop=true;
			inter=oper;
			last=ch;
		}
	}
	else if(ch=='=')
	{
		if(isop==true)
		{
			switch(last)
			{
			case('+'):
				rez=inter+oper;
				isop=false;
				break;
			case('-'):
				rez=inter-oper;
				isop=false;
				break;
			case('*'):
				rez=inter*oper;
				isop=false;
				break;
			case('/'):
				rez=inter/oper;
				isop=false;
				break;
			}
		}
		else
		{
			input.Empty();
			rez=0.0;
			inter=0.0;
			oper=0.0;
		}
	}
}

void Ccomputer::delop()
{
	input.Delete(input.GetLength()-1,1);
}

void Ccomputer::get(double *rez)
{
	*rez=this->rez;
}
