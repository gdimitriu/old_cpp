#include "StdAfx.h"
#include "JustLanguage.h"
#include <iostream>
#include <string>
#include <cstring>

using std::string;


JustLanguage::JustLanguage(void)
{
}


JustLanguage::~JustLanguage(void)
{
}


void JustLanguage::run(void)
{
	int *pi2=0;
	pi2=new int;
	int ival=foobar(pi2);
	std::cout<<ival<<std::endl;
	CStringexample1();
}


int JustLanguage::foobar(int *pi)
{
	*pi=1024;
	return *pi;
}

void JustLanguage::CStringexample1(void)
{
	int errors=0;
	const char *pc="a very long literal string";
	for(int ix=0;ix<1000000;++ix)
	{
		int len=strlen(pc);
		char *pc2=new char[len+1];
		strcpy(pc2,pc);
		if(strcmp(pc2,pc))
			++errors;
		delete []pc2;
	}
	std::cout<<"C-style strings: "<<errors<<" errors occured."<<std::endl;
	/** string implementation */
	errors=0;
	string str("a verly long literal string");
	for(int ix=0;ix<1000000;++ix)
	{
		int len=str.size();
		string str2=str;
		if(str!=str2)
			++errors;
	}
	std::cout<<"string class : "<<errors<<" errors occured."<<std::endl;
}