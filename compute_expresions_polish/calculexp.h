// calculexp.h: interface for the calculexp class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Compute Expresion.
	This is the definition of the main class for Compute Expresion.

    Compute Expresion is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Compute Expresion is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Compute Expresion; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#if !defined(AFX_CALCULEXP_H__4D295571_09CF_4CC6_9837_623EE0D12371__INCLUDED_)
#define AFX_CALCULEXP_H__4D295571_09CF_4CC6_9837_623EE0D12371__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<stack>
#include<list>
#include<string>
using namespace std ;
struct element
{
	char var;
	double val;
};
class calculexp  
{
public:
	double polish(string str);
	calculexp();
	virtual ~calculexp();
private:
	stack<double> stiva_double;
	list<struct element> lista_var;
	list<struct element>::iterator it;
};

#endif // !defined(AFX_CALCULEXP_H__4D295571_09CF_4CC6_9837_623EE0D12371__INCLUDED_)
