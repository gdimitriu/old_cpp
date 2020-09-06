#include "StdAfx.h"
#include "Ex1.h"
#include <cassert>
#include <iostream>

Ex1::Ex1(void)
{
}


Ex1::~Ex1(void)
{
}

namespace Ex1Name
{
	class base
	{
	public:
		virtual void iam() {std::cout<<"Base"<<std::endl;}
	};
	class extendbase1 :public base
	{
	public:
		void iam() {std::cout<<"extendedBase1"<<std::endl;}
	};
	class extendbase2 : public base
	{
	public:
		void iam() {std::cout<<"extendedBase2"<<std::endl;}
	};
}
void Ex1::run(void)
{
	using namespace Ex1Name;
	base b1;
	extendbase1 eb1;
	extendbase2 eb2;
	b1.iam();
	eb1.iam();
	eb2.iam();
	base* pBase;
	pBase=&eb1;
	pBase->iam();
	pBase=&eb2;
	pBase->iam();

}
