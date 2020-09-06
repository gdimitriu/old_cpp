// inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
public:
	int f(int val){cout<<"A f(int)="<<val<<endl; return val;}
	char f(char val) {cout<<"A f(char)="<<val<<endl; return val;}
};
class B {
public:
	double f(double val){ cout<<"B f(double)="<<val<<endl; return val;}
};
class AB : public A,public B {
public:
	using A::f;
	using B::f;
	char f(char val){ cout<<"AB f(char)="<<val<<endl; return val;}
	AB f(AB val){ cout<<"f(AB)"<<endl;return val;}
};
void g(AB& ab)
{
	ab.f(1);
	ab.f('a');
	ab.f(2.0);
	ab.f(ab);
}
void g1(AB *ab)
{
	ab->f(1);
	ab->f('a');
	ab->f(2.0);
	ab->f(*ab);
}

int _tmain(int argc, _TCHAR* argv[])
{
	AB ab;
	g(ab);
	g1(&ab);
	return 0;
}

