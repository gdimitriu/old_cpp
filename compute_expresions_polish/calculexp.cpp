// calculexp.cpp: implementation of the calculexp class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Compute Expresion.
	This is the implementation of the main class for Compute Expresion.

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
#include "calculexp.h"
#include<iostream>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include<stdlib.h>
#include<math.h>
calculexp::calculexp()
{

}

calculexp::~calculexp()
{

}

double calculexp::polish(string str)
{
	int length;
	int i;
	bool flag;
	struct element tempel;
	double tempd;
	int start;
	length=str.length();
	if(str[1]=='=' && (str[2]>=48 && str[2]<=57))
	{
		tempel.var=str[0];
		string vals;
		vals.insert(0,&str[2],length-2);
		tempel.val=atof(vals.data());
		flag=false;
		for (it = lista_var.begin(); it != lista_var.end(); ++it)
			if(it->var==tempel.var)
			{
				it->val=tempel.val;
				flag=true;
				break;
			}
		if(flag==false) lista_var.insert(lista_var.end(),tempel);
	}
	else
	{
		if(str[1]=='=') start=2;
		else start=0;
		for(i=start;i<length;i++)
		{
			if((str[i]<=90 && str[i]>=65) || (str[i]<=122 && str[i]>=97)) //we had variable
			{
				//search if we had it
				flag=false;
				for (it = lista_var.begin(); it != lista_var.end(); ++it)
					if(it->var==str[i])
					{
						flag=true;
						stiva_double.push(it->val);
						break;
					}
				//if we hadn't it, we ask for it
				if(flag==false)
				{
					tempel.var=str[i];
					cout<<"Variabila "<<str[i]<<"=";
					cin>>tempel.val;
					stiva_double.push(tempel.val);
					lista_var.insert(lista_var.end(),tempel);
				}
			}
			else
			if(str[i]=='+')
			{
				tempd=stiva_double.top();
				stiva_double.pop();
				tempd+=stiva_double.top();
				stiva_double.pop();
				stiva_double.push(tempd);
			}
			else
			if(str[i]=='*')
			{
				tempd=stiva_double.top();
				stiva_double.pop();
				tempd*=stiva_double.top();
				stiva_double.pop();
				stiva_double.push(tempd);
			}
			else
			if(str[i]=='-')
			{
				tempd=stiva_double.top();
				stiva_double.pop();
				tempd-=stiva_double.top();
				stiva_double.pop();
				stiva_double.push(tempd);
			}
			else
			if(str[i]=='/')
			{
				double numitor;
				tempd=stiva_double.top();
				stiva_double.pop();
				numitor=stiva_double.top();
				stiva_double.pop();
				if(numitor!=0.0) tempd/=numitor;
				else cout<<"Divided by zero\n";
				stiva_double.push(tempd);
			}
		}
		if(str[1]=='=')
		{
			tempel.var=str[0];
			tempel.val=tempd;
			flag=false;
			for (it = lista_var.begin(); it != lista_var.end(); ++it)
				if(it->var==tempel.var)
				{
					it->val=tempel.val;
					flag=true;
					break;
				}
			if(flag==false) lista_var.insert(lista_var.end(),tempel);
		}
		else cout<<tempd<<endl;
	}
	cout<<"Memory Variables"<<endl;
	for (it = lista_var.begin(); it != lista_var.end(); ++it)
		cout<<it->var<<"="<<it->val<<endl;
	return length;
}
