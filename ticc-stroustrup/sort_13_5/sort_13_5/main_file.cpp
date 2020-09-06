#include <iostream>
#include <algorithm>
#include "sort_template.h"

int main(int argc,char *arg[])
{
	vector<Record> _vectoras;
	Record _tmp;
	for(int i=0;i<10;++i)
	{
		_tmp.count=i;
		_tmp.price=10-i;
		_vectoras.push_back(_tmp);
	}
	for(vector<Record>::iterator i=_vectoras.begin();i!=_vectoras.end();++i)
	{
		std::cout<<(*i).price<<" ";
	}
	std::cout<<std::endl;
	//sort_13_5(_vectoras,compare_count);
	std::sort(_vectoras.begin(),_vectoras.end(),compare_count);
	for(vector<Record>::iterator i=_vectoras.begin();i!=_vectoras.end();++i)
	{
		std::cout<<(*i).price<<" ";
	}
	std::cout<<std::endl;

	return 0;
}