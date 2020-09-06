#include "StdAfx.h"
#include "Ex1.h"
#include <iostream>

Ex1::Ex1(void)
{
}


Ex1::~Ex1(void)
{
}
namespace Ex1Name
{
class Y;
class X
{
	int i;
public:
	X(int value)
	{
		i=value;
	}
	X operator+(const int value)
	{
		return(X(i+value));
	}
	int get() const
	{
		return i;
	}
	friend X operator*(const X&,const Y&);
	friend std::ostream& operator<<(std::ostream &output,const X& x);
};

std::ostream& operator<<(std::ostream &output,const X& x)
{
	output<<x.i;
	return output;
}

class Y
{
	int i;
public:
	Y(X x)
	{
		i=x.get();
	}
	Y operator+(const X x)
	{
		return Y(i+x.get());
	}
	friend X operator*(const X&,const Y&);
	operator int() const { return i;};
};

X operator*(const X& x,const Y& y)
{
	return X(x.i*y.i);
};

int f(X x)
{
	return x.get();
}
}
void Ex1::run(void)
{
	using Ex1Name::X;
	using Ex1Name::Y;
	using Ex1Name::f;
	using Ex1Name::operator*;
	X x=1;
	Y y=x;
	int i=2;
	std::cout<<i+10<<std::endl;
	std::cout<<(int)y+10<<std::endl;
	std::cout<<(int)y+10*(int)y<<std::endl;
	std::cout<<x+y+i<<std::endl;
	std::cout<<x*x+i<<std::endl;
	std::cout<<f(7)<<std::endl;
	std::cout<<f((int)y)<<std::endl;
	std::cout<<y+y<<std::endl;
	std::cout<<106+y<<std::endl;
}
