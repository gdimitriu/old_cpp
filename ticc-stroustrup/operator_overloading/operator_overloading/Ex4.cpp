#include "StdAfx.h"
#include "Ex4.h"
#include <cassert>
#include <iostream>

Ex4::Ex4(void)
{
}


Ex4::~Ex4(void)
{
}

class RINT
{
private:
	int _value;
public:
	RINT(int value): _value(value) {}
	int get() const {return _value;}
	RINT operator-(){_value=-_value;return *this;}
	RINT operator+(){_value=+_value;return *this;}
	RINT& operator%=(const int value)  { _value%=value;return *this;}
	RINT& operator%=(const RINT& value){ _value%=value._value;return *this;}
	RINT& operator+=(const RINT& value){ _value+=value._value;return *this;}
	RINT& operator+=(const int value)  { _value+=value;return *this;}
	RINT& operator*=(const RINT& value){ _value*=value._value;return *this;}
	RINT& operator*=(const int value)  { _value*=value;return *this;}
	RINT& operator/=(const int value)  { _value/=value;return *this;}
	RINT& operator/=(const RINT& value){ _value/=value._value;return *this;}
	RINT& operator-=(const int value)  { _value-=value;return *this;}
	RINT& operator-=(const RINT& value){ _value-=value._value;return *this;}
};

RINT operator+(const RINT& x,const RINT& y)
{
	RINT temp(x);
	return temp+=y;
}
RINT operator-(const RINT& x,const RINT& y)
{
	RINT temp(x);
	return temp-=y;
}
RINT operator*(const RINT& x,const RINT& y)
{
	RINT temp(x);
	return temp*=y;
}
RINT operator/(const RINT& x,const RINT& y)
{
	RINT temp(x);
	return temp/=y;
}
RINT operator%(const RINT& x,const RINT& y)
{
	RINT temp(x);
	return temp%=y;
}
/*
 why to define mixed mode arithmetic when the const and conversion operator will do that for me
RINT operator+(const int value,const RINT& x)
{
	RINT temp(x);
	return temp+=value;
}
RINT operator-(const int value,const RINT& x)
{
	RINT temp(value);
	return temp-=x;
}
RINT operator*(const int value,const RINT& x)
{
	RINT temp(x);
	return temp*=value;
}
RINT operator/(const int value,const RINT& x)
{
	RINT temp(value);
	return temp/=x;
}
RINT operator%(const RINT& x,const int value)
{
	RINT temp(x);
	return temp%=value;
}
*/
void Ex4::run(void)
{
	RINT x(1),y(1);
	RINT rez(0);
	std::cout<<"Starting Ex4 tests"<<std::endl;
	rez=x+y;
	assert(2==rez.get());
	rez=x*y;
	assert(1==rez.get());
	rez=x-y;
	assert(0==rez.get());
	rez=x/y;
	assert(1==rez.get());
	rez=-x;
	assert(-1==rez.get());
	x=2;
	rez=x%2;
	assert(0==rez.get());
	rez=x+1;
	assert(3==rez.get());
	rez=x-1;
	assert(1==rez.get());
	rez=x*2;
	assert(4==rez.get());
	rez=x/2;
	assert(1==rez.get());
	rez=1-x;
	assert(-1==rez.get());
	rez=1+x;
	assert(3==rez.get());
	rez=2*x;
	assert(4==rez.get());
	rez=2/x;
	assert(1==rez.get());
	std::cout<<"Ended Ex4 tests"<<std::endl;
}
