// Compute_expresions.cpp : Defines the entry point for the console application.
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Compute Expresion.
	This is the main part of Compute Expresion.

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

#include "stdafx.h"
#include<iostream>
#include<string>
#include "calculexp.h"
using namespace std ;

int main(int argc, char* argv[])
{
	string str;
	calculexp calc;
	cin>>str;
	while(str[0]!='=')
	{
		calc.polish(str);
		cin>>str;
	}
	return 0;
}
