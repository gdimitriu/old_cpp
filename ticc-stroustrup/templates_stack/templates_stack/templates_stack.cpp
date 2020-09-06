// templates_stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "CmyStack.h"

using namespace std;

template <class kind>
kind Maxim(kind d1,kind d2)
{
	if(d1<d2)
		return(d2);
	else
		return(d1);
}
char *Maxim(char *d1,char *d2)
{
	if(strcmp(d1,d2)>0)
		return(d1);
	else
		return(d2);
}

void testMaxim(void)
{
	cout <<"Maxim(2,1)="<<Maxim(2,1)<<"\n";
	cout <<"Maxim(1,2)="<<Maxim(1,2)<<"\n";
	cout <<"Maxim(2.34,4.23)="<<Maxim(2.34,4.23)<<"\n";
	cout <<"Maxim(\"able\",\"baker\")="<<Maxim("able","baker")<<"\n";
}

void testStackTemplate(void)
{
	CmyStack<int> intStack;
	intStack.Push(2);
	intStack.Push(6);
	intStack.Push(1);
	cout<<intStack.Pop()<<"\n";
	cout<<intStack.Pop()<<"\n";
	cout<<intStack.Pop()<<"\n";
	CmyStack<double> doubleStack;
	doubleStack.Push(2.4);
	doubleStack.Push(6.5);
	doubleStack.Push(1.78);
	cout<<doubleStack.Pop()<<"\n";
	cout<<doubleStack.Pop()<<"\n";
	cout<<doubleStack.Pop()<<"\n";

}

int _tmain(int argc, _TCHAR* argv[])
{
	testMaxim();
	testStackTemplate();
	return 0;
}

