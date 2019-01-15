#include "StdAfx.h"
#include "Chistorgram.h"
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>

Chistorgram::Chistorgram(void)
{
}


Chistorgram::~Chistorgram(void)
{
}


void Chistorgram::record(const string s)
{
	histogram[s]++;
}

static void print(const std::pair<const string,int> &p)
{
	std::cout<<p.first<<' '<<p.second<<std::endl;
}


void Chistorgram::run(void)
{
	if(false)
	{
		std::istream_iterator<string> ii(std::cin);
		std::istream_iterator<string> eos;
		//be carefully bind1st and mem_fun works only without reference
		std::for_each(ii,eos,std::bind1st(std::mem_fun(&Chistorgram::record),this));
		//this should work as stroustrup said but in fact it didn't :( because there is a pointer
		//std::for_each(ii,eos,std::mem_fun<void,Chistorgram>(&Chistorgram::record));
		std::for_each(histogram.begin(),histogram.end(),print);
	}
	external_run(this);
}

void external_run(Chistorgram *hist)
{
	std::istream_iterator<string> ii(std::cin);
	std::istream_iterator<string> eos;
	//this should work as stroustrup said but in fact it didn't :( because there is a pointer
	std::for_each(ii,eos,std::bind1st(std::mem_fun(&Chistorgram::record),hist));
	std::for_each(hist->histogram.begin(),hist->histogram.end(),print);
}