// cpp_stroustrup.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chistorgram.h"
#include "Cbasic_facilities.h"
#include <limits>
#include <iostream>
#include "ssort.h"

int _tmain(int argc, char* argv[])
{
	std::cout<<"float="<<std::numeric_limits<float>::max()<<" double="<<std::numeric_limits<double>::max()<<" long double="<<std::numeric_limits<long double>::max()<<std::endl;
	std::cout<<"short integer="<<std::numeric_limits<short>::max()<<" int="<<std::numeric_limits<int>::max()<<" long="<<std::numeric_limits<long>::max()<<" long long="<<std::numeric_limits<long long>::max()<<std::endl;
	std::cout<<"bool="<<std::numeric_limits<bool>::max()<<" char="<<std::numeric_limits<char>::max()<<std::endl;
	Chistorgram histogram;
	//	histogram.run();
	Cbasic_facilities basic;
	basic.run();
	basic.cap6_14();
	basic.cap5_12();
	ssort headSort;
	headSort.run();
	return 0;
}

