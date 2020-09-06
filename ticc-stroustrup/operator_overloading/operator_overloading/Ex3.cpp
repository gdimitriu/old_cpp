#include "StdAfx.h"
#include "Ex3.h"
#include <iostream>
#include <cassert>

Ex3::Ex3(void)
{
}


Ex3::~Ex3(void)
{
}

class INT
{
private:
	int _value;
public:
	INT(const int value) : _value(value){}
	operator int(){return _value;}
	INT& operator=(const int value){ _value=value;return *this;}
	INT& operator+=(const int value){_value+=value;return *this;}
	INT& operator-=(const int value){_value-=value;return *this;}
	INT& operator*=(const int value){_value*=value;return *this;}
	INT operator++(int tmp){INT temp(_value);_value++;return temp;}
	INT operator--(int tmp){INT temp(_value);_value--;return temp;}
	INT& operator--(){_value--; return *this;}
	INT& operator++(){_value++; return *this;}
	INT operator-(){return INT(-_value);}
};

void Ex3::run(void)
{
	INT x(1),y(1),z(1),rez(0);
	std::cout<<"Starting Ex3 tests"<<std::endl;
	rez=x+y;
	assert(rez==2);
	rez=x*y;
	assert(rez==1);
	rez=x+y*z;
	assert(rez==2);
	rez=x-y;
	assert(rez==0);
	rez+=1;
	assert(rez==1);
	rez-=1;
	assert(rez==0);
	rez=2;
	rez*=2;
	assert(rez==4);
	rez=2.3;
	assert(rez==2);
	rez++;
	assert(rez==3);
	rez--;
	assert(rez==2);
	--rez;
	assert(rez==1);
	++rez;
	assert(rez==2);
	rez=-x;
	assert(rez==-1);
	std::cout<<"Ended Ex3 tests"<<std::endl;
}
