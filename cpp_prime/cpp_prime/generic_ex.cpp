#include "StdAfx.h"
#include "generic_ex.h"
#include <iostream>
#include <algorithm>
#include<vector>
using std::vector;

generic_ex::generic_ex(void)
{
}


generic_ex::~generic_ex(void)
{
}

void generic_ex::run(void)
{
	int ia[10]={51,23,7,88,41,98,12,103,37,6};
	vector<int> vec(ia,ia+10);
	//sort the array
	std::sort(vec.begin(),vec.end());
	//grab value to search for
	int search_value;
	std::cin>>search_value;
	//search for an element
	vector<int>::iterator found;
	found=std::find(vec.begin(),vec.end(),search_value);
	if(found!=vec.end())
		std::cout<<"search_value found!"<<std::endl;
	else
		std::cout<<"search_value not found!"<<std::endl;
	//reverse the array
	std::reverse(vec.begin(),vec.end());
}
