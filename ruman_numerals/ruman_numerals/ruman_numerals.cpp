// ruman_numerals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RomanNumbers.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	CRomanNumbers roman;
	roman.convert(3);
	roman.convert(4);
	roman.convert(7);
	roman.convert(8);
	roman.convert(20);
	roman.convert(49);
	roman.convert(50);
	roman.convert(150);
	roman.convert(369);
	roman.convert(448);
	cout<<"Convert reverse order\n";
	roman.convertreverse(3);
	roman.convertreverse(4);
	roman.convertreverse(7);
	roman.convertreverse(8);
	roman.convertreverse(20);
	roman.convertreverse(49);
	roman.convertreverse(50);
	roman.convertreverse(150);
	roman.convertreverse(369);
	roman.convertreverse(448);

	return 0;
}

