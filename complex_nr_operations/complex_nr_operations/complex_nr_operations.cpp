// complex_nr_operations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ccomplex.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Ccomplex a(2.0,2.0);
	Ccomplex b(1.0,1.0);
	
	cout<<"complex a="<<a.real()<<"i"<<a.imaginary()<<"\n";
	cout<<"complex b="<<b.real()<<"i"<<b.imaginary()<<"\n";
	Ccomplex c=a+b;
	cout<<"complex a+b="<<c.real()<<"i"<<c.imaginary()<<"\n";
	++a;
	b++;
	cout<<"complex ++a="<<a.real()<<"i"<<a.imaginary()<<"\n";
	cout<<"complex b++="<<b.real()<<"i"<<b.imaginary()<<"\n";
	a--;
	--b;
	cout<<"complex a--="<<a.real()<<"i"<<a.imaginary()<<"\n";
	cout<<"complex --b="<<b.real()<<"i"<<b.imaginary()<<"\n";
	Ccomplex d=-a;
	cout<<"complex -a="<<d.real()<<"i"<<d.imaginary()<<"\n";
	return 0;
}

