#include "StdAfx.h"
#include <iostream>
#include "Error.h"
int Error::no_of_errors;

int Error::error(const string& s)
{
	no_of_errors++;
	std::cerr<<"error: "<<s<<std::endl;
	return 1;
}

int Error::get_nr_of_errors(void)
{
	return no_of_errors;
}

void Error::init(void)
{
	no_of_errors=0;
}